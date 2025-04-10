#ifndef AES_IMPL_HPP
#define AES_IMPL_HPP

#include <cassert>
#include <cstring>
#include <immintrin.h>
#include <inttypes.h>
#include <wmmintrin.h>

#include "../aes_defs.hpp"
#include "../constants.hpp"
#include "../transpose.hpp"
#include "../util.hpp"

namespace faest
{

template <secpar S, size_t num_keys, uint32_t num_blocks>
void aes_keygen_impl(aes_round_keys<S>* aeses, const block_secpar<S>* keys, block128* output);

void rijndael192_encrypt_block(const rijndael192_round_keys* __restrict__ fixed_key,
                               block192* __restrict__ block);

template <secpar S>
inline void aes_round_function(const aes_round_keys<S>* __restrict__ round_keys,
                               block128* __restrict__ block, block128* __restrict__ after_sbox,
                               size_t round)
{
    block128 state = *block;
    block128 state_after_sbox = {_mm_aesenclast_si128(state.data, block128::set_zero().data)};
    *after_sbox = state_after_sbox;

    if (round < AES_ROUNDS<S>)
        state = {_mm_aesenc_si128(state.data, round_keys->keys[round].data)};
    else
        state = state_after_sbox ^ round_keys->keys[round];
    *block = state;
}

template <secpar S>
ALWAYS_INLINE void aes_round(const aes_round_keys<S>* aeses, block128* state, size_t num_keys,
                             size_t evals_per_key, size_t round)
{
    PRAGMA_UNROLL(2*AES_PREFERRED_WIDTH)
    for (size_t i = 0; i < num_keys * evals_per_key; ++i)
        if (round == 0)
            state[i] = state[i] ^ aeses[i / evals_per_key].keys[round];
        else if (round < AES_ROUNDS<S>)
            state[i] = {_mm_aesenc_si128(state[i].data, aeses[i / evals_per_key].keys[round].data)};
        else state[i] = {
            _mm_aesenclast_si128(state[i].data, aeses[i / evals_per_key].keys[round].data)};
}

// This implements the rijndael256 RotateRows step, then cancels out the RotateRows of AES so
// that AES-NI can be used for the sbox.
ALWAYS_INLINE void rijndael256_rotate_rows_undo_128(block128* s)
{
    // Swapping bytes between 128-bit halves is equivalent to rotating left overall, then
    // rotating right within each half.
    __m128i mask = _mm_setr_epi8(0, -1, -1, -1, 0, 0, -1, -1, 0, 0, -1, -1, 0, 0, 0, -1);
    __m128i b0_blended = _mm_blendv_epi8(s[0].data, s[1].data, mask);
    __m128i b1_blended = _mm_blendv_epi8(s[1].data, s[0].data, mask);

    // The rotations for 128-bit AES are different, so rotate within the halves to
    // match.
    __m128i perm = _mm_setr_epi8(0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13, 2, 3);
    s[0] = {_mm_shuffle_epi8(b0_blended, perm)};
    s[1] = {_mm_shuffle_epi8(b1_blended, perm)};
}

ALWAYS_INLINE void rijndael256_round(const rijndael256_round_keys* round_keys, block256* state,
                                     size_t num_keys, size_t evals_per_key, size_t round)
{
#ifdef __GNUC__
    _Pragma(STRINGIZE(GCC unroll (2*RIJNDAEL256_PREFERRED_WIDTH)))
#endif
        for (size_t i = 0; i < num_keys * evals_per_key; ++i)
    {
        block128 s[2], round_key[2];
        memcpy(&s[0], &state[i], sizeof(block256));
        memcpy(&round_key[0], &round_keys[i / evals_per_key].keys[round], sizeof(block256));

        // Use AES-NI to implement the round function.
        if (round == 0)
        {
            s[0] = s[0] ^ round_key[0];
            s[1] = s[1] ^ round_key[1];
        }
        else if (round < AES_ROUNDS<secpar::s256>)
        {
            rijndael256_rotate_rows_undo_128(&s[0]);
            s[0] = {_mm_aesenc_si128(s[0].data, round_key[0].data)};
            s[1] = {_mm_aesenc_si128(s[1].data, round_key[1].data)};
        }
        else
        {
            rijndael256_rotate_rows_undo_128(&s[0]);
            s[0] = {_mm_aesenclast_si128(s[0].data, round_key[0].data)};
            s[1] = {_mm_aesenclast_si128(s[1].data, round_key[1].data)};
        }

        memcpy(&state[i], &s[0], sizeof(block256));
    }
}

template <secpar S, size_t num_keys, size_t blocks_per_key>
ALWAYS_INLINE void
aes_keygen_ecb(const block_secpar<S>* __restrict__ keys, aes_round_keys<S>* __restrict__ aeses,
               block128* __restrict__ data)
{
    // TODO: can probably ditch this wrapper now.
    aes_keygen_impl<S, num_keys, blocks_per_key>(aeses, keys, data);
}

template <secpar S, size_t num_keys, size_t blocks_per_key>
inline void aes_ecb(const aes_round_keys<S>* __restrict__ aeses, block128* __restrict__ data)
{
    // IIRC, GCC won't keep state in registers unless I make this a local variable.
    block128 state[num_keys * blocks_per_key];
    memcpy(state, data, sizeof(state));

    // Make it easier for the compiler to optimize by unwinding the first and last rounds. (Since we
    // aren't asking it to unwind the whole loop.)
    aes_round(aeses, state, num_keys, blocks_per_key, 0);
    for (size_t round = 1; round < AES_ROUNDS<S>; ++round)
        aes_round(aeses, state, num_keys, blocks_per_key, round);
    aes_round(aeses, state, num_keys, blocks_per_key, AES_ROUNDS<S>);

    memcpy(data, state, sizeof(state));
}

template <size_t num_keys, uint32_t num_blocks>
inline void aes_fixed_key_ctr(const aes_round_keys<secpar::s128>* __restrict__ fixed_key,
                              const block128* __restrict__ keys,
                              const block128& iv,
                              const uint32_t* __restrict__ tweaks,
                              const uint32_t* counters,
                              block128* __restrict__ output)
{
    block128 state[num_keys * num_blocks];

    for (size_t l = 0; l < num_keys; ++l)
        for (uint32_t m = 0; m < num_blocks; ++m)
            state[l * num_blocks + m] = iv.add32(block128::set_low32(counters[l] + m, tweaks[l])) ^ keys[l];

    aes_round(fixed_key, state, 1, num_keys * num_blocks, 0);
    for (size_t round = 1; round < AES_ROUNDS<secpar::s128>; ++round)
        aes_round(fixed_key, state, 1, num_keys * num_blocks, round);
    aes_round(fixed_key, state, 1, num_keys * num_blocks, AES_ROUNDS<secpar::s128>);

    for (size_t l = 0; l < num_keys; ++l)
        for (uint32_t m = 0; m < num_blocks; ++m)
            output[l * num_blocks + m] = state[l * num_blocks + m] ^ keys[l];
}

template <size_t num_keys, uint32_t num_blocks>
inline void rijndael256_fixed_key_ctr(const rijndael256_round_keys* __restrict__ fixed_key,
                                      const block256* __restrict__ keys,
                                      const block256& iv,
                                      const uint32_t* __restrict__ tweaks,
                                      const uint32_t* __restrict__ counters,
                                      block256* __restrict__ output)
{
    block256 state[num_keys * num_blocks];

    for (size_t l = 0; l < num_keys; ++l)
        for (uint32_t m = 0; m < num_blocks; ++m)
            state[l * num_blocks + m] = iv.add32(block256::set_low32(counters[l] + m, tweaks[l])) ^ keys[l];

    rijndael256_round(fixed_key, state, 1, num_keys * num_blocks, 0);
    for (size_t round = 1; round < RIJNDAEL_ROUNDS<secpar::s256>; ++round)
        rijndael256_round(fixed_key, state, 1, num_keys * num_blocks, round);
    rijndael256_round(fixed_key, state, 1, num_keys * num_blocks, RIJNDAEL_ROUNDS<secpar::s256>);

    for (size_t l = 0; l < num_keys; ++l)
        for (uint32_t m = 0; m < num_blocks; ++m)
            output[l * num_blocks + m] = state[l * num_blocks + m] ^ keys[l];
}

template <size_t num_keys, uint32_t num_blocks>
inline void rijndael192_fixed_key_ctr(const rijndael192_round_keys* __restrict__ fixed_key,
                                      const block192* __restrict__ keys,
                                      const block192& iv,
                                      const uint32_t* __restrict__ tweaks,
                                      const uint32_t* __restrict__ counters,
                                      block192* __restrict__ output)
{
    for (size_t l = 0; l < num_keys; ++l)
    {
        for (uint32_t m = 0; m < num_blocks; ++m)
        {
            block192 state = iv.add32(block192::set_low32(counters[l] + m, tweaks[l])) ^ keys[l];
            rijndael192_encrypt_block(fixed_key, &state);
            output[l * num_blocks + m] = state;
        }
    }
}

} // namespace faest

#endif
