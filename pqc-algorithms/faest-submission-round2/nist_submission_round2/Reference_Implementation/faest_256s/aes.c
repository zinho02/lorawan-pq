/*
 *  SPDX-License-Identifier: MIT
 */

#if defined(HAVE_CONFIG_H)
#include <config.h>
#endif

#include "aes.h"

#include "fields.h"
#include "compat.h"
#include "utils.h"

#if defined(HAVE_OPENSSL)
#include <openssl/evp.h>
#endif
#include <string.h>

#define ROUNDS_128 10
#define ROUNDS_192 12
#define ROUNDS_256 14

#define KEY_WORDS_128 4
#define KEY_WORDS_192 6
#define KEY_WORDS_256 8

#define AES_BLOCK_WORDS 4
#define RIJNDAEL_BLOCK_WORDS_192 6
#define RIJNDAEL_BLOCK_WORDS_256 8

static const bf8_t round_constants[30] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
    0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91,
};

static bf8_t compute_sbox(bf8_t in) {
  bf8_t t  = bf8_inv(in);
  bf8_t t0 = set_bit(parity8(t & (1 | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))), 0);
  t0 ^= set_bit(parity8(t & (1 | (1 << 1) | (1 << 5) | (1 << 6) | (1 << 7))), 1);
  t0 ^= set_bit(parity8(t & (1 | (1 << 1) | (1 << 2) | (1 << 6) | (1 << 7))), 2);
  t0 ^= set_bit(parity8(t & (1 | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 7))), 3);
  t0 ^= set_bit(parity8(t & (1 | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4))), 4);
  t0 ^= set_bit(parity8(t & ((1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5))), 5);
  t0 ^= set_bit(parity8(t & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6))), 6);
  t0 ^= set_bit(parity8(t & ((1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))), 7);
  return t0 ^ (1 | (1 << 1) | (1 << 5) | (1 << 6));
}

#if defined(FAEST_TESTS)
void aes_increment_iv(uint8_t* iv)
#else
static inline void aes_increment_iv(uint8_t* iv)
#endif
{
  uint32_t iv0;
  memcpy(&iv0, iv, sizeof(uint32_t));
  iv0 = htole32(le32toh(iv0) + 1);
  memcpy(iv, &iv0, sizeof(uint32_t));
}

// ## AES ##
// Round Functions
static void add_round_key(unsigned int round, aes_block_t state, const aes_round_keys_t* round_key,
                          unsigned int block_words) {
  for (unsigned int c = 0; c < block_words; c++) {
    xor_u8_array(&state[c][0], &round_key->round_keys[round][c][0], &state[c][0], AES_NR);
  }
}

static void sub_bytes(aes_block_t state, unsigned int block_words) {
  for (unsigned int c = 0; c < block_words; c++) {
    for (unsigned int r = 0; r < AES_NR; r++) {
      state[c][r] = compute_sbox(state[c][r]);
    }
  }
}

static void shift_row(aes_block_t state, unsigned int block_words) {
  aes_block_t new_state;
  switch (block_words) {
  case 4:
  case 6:
    for (unsigned int i = 0; i < block_words; ++i) {
      new_state[i][0] = state[i][0];
      new_state[i][1] = state[(i + 1) % block_words][1];
      new_state[i][2] = state[(i + 2) % block_words][2];
      new_state[i][3] = state[(i + 3) % block_words][3];
    }
    break;
  case 8:
    for (unsigned int i = 0; i < block_words; i++) {
      new_state[i][0] = state[i][0];
      new_state[i][1] = state[(i + 1) % 8][1];
      new_state[i][2] = state[(i + 3) % 8][2];
      new_state[i][3] = state[(i + 4) % 8][3];
    }
    break;
  }

  for (unsigned int i = 0; i < block_words; ++i) {
    memcpy(&state[i][0], &new_state[i][0], AES_NR);
  }
}

static void mix_column(aes_block_t state, unsigned int block_words) {
  for (unsigned int c = 0; c < block_words; c++) {
    bf8_t tmp = bf8_mul(state[c][0], 0x02) ^ bf8_mul(state[c][1], 0x03) ^ state[c][2] ^ state[c][3];
    bf8_t tmp_1 =
        state[c][0] ^ bf8_mul(state[c][1], 0x02) ^ bf8_mul(state[c][2], 0x03) ^ state[c][3];
    bf8_t tmp_2 =
        state[c][0] ^ state[c][1] ^ bf8_mul(state[c][2], 0x02) ^ bf8_mul(state[c][3], 0x03);
    bf8_t tmp_3 =
        bf8_mul(state[c][0], 0x03) ^ state[c][1] ^ state[c][2] ^ bf8_mul(state[c][3], 0x02);

    state[c][0] = tmp;
    state[c][1] = tmp_1;
    state[c][2] = tmp_2;
    state[c][3] = tmp_3;
  }
}

// Key Expansion functions
static void sub_words(bf8_t* words) {
  words[0] = compute_sbox(words[0]);
  words[1] = compute_sbox(words[1]);
  words[2] = compute_sbox(words[2]);
  words[3] = compute_sbox(words[3]);
}

static void rot_word(bf8_t* words) {
  bf8_t tmp = words[0];
  words[0]  = words[1];
  words[1]  = words[2];
  words[2]  = words[3];
  words[3]  = tmp;
}

void expand_key(aes_round_keys_t* round_keys, const uint8_t* key, unsigned int key_words,
                unsigned int block_words, unsigned int num_rounds) {

  for (unsigned int k = 0; k < key_words; k++) {
    round_keys->round_keys[k / block_words][k % block_words][0] = bf8_load(&key[4 * k]);
    round_keys->round_keys[k / block_words][k % block_words][1] = bf8_load(&key[(4 * k) + 1]);
    round_keys->round_keys[k / block_words][k % block_words][2] = bf8_load(&key[(4 * k) + 2]);
    round_keys->round_keys[k / block_words][k % block_words][3] = bf8_load(&key[(4 * k) + 3]);
  }

  for (unsigned int k = key_words; k < block_words * (num_rounds + 1); ++k) {
    bf8_t tmp[AES_NR];
    memcpy(tmp, round_keys->round_keys[(k - 1) / block_words][(k - 1) % block_words], sizeof(tmp));

    if (k % key_words == 0) {
      rot_word(tmp);
      sub_words(tmp);
      tmp[0] ^= round_constants[(k / key_words) - 1];
    }

    if (key_words > 6 && (k % key_words) == 4) {
      sub_words(tmp);
    }

    unsigned int m = k - key_words;
    round_keys->round_keys[k / block_words][k % block_words][0] =
        round_keys->round_keys[m / block_words][m % block_words][0] ^ tmp[0];
    round_keys->round_keys[k / block_words][k % block_words][1] =
        round_keys->round_keys[m / block_words][m % block_words][1] ^ tmp[1];
    round_keys->round_keys[k / block_words][k % block_words][2] =
        round_keys->round_keys[m / block_words][m % block_words][2] ^ tmp[2];
    round_keys->round_keys[k / block_words][k % block_words][3] =
        round_keys->round_keys[m / block_words][m % block_words][3] ^ tmp[3];
  }
}

// Calling Functions

void aes128_init_round_keys(aes_round_keys_t* round_key, const uint8_t* key) {
  expand_key(round_key, key, KEY_WORDS_128, AES_BLOCK_WORDS, ROUNDS_128);
}

void aes192_init_round_keys(aes_round_keys_t* round_key, const uint8_t* key) {
  expand_key(round_key, key, KEY_WORDS_192, AES_BLOCK_WORDS, ROUNDS_192);
}

void aes256_init_round_keys(aes_round_keys_t* round_key, const uint8_t* key) {
  expand_key(round_key, key, KEY_WORDS_256, AES_BLOCK_WORDS, ROUNDS_256);
}

void rijndael192_init_round_keys(aes_round_keys_t* round_key, const uint8_t* key) {
  expand_key(round_key, key, KEY_WORDS_192, RIJNDAEL_BLOCK_WORDS_192, ROUNDS_192);
}

void rijndael256_init_round_keys(aes_round_keys_t* round_key, const uint8_t* key) {
  expand_key(round_key, key, KEY_WORDS_256, RIJNDAEL_BLOCK_WORDS_256, ROUNDS_256);
}

static void load_state(aes_block_t state, const uint8_t* src, unsigned int block_words) {
  for (unsigned int i = 0; i != block_words * 4; ++i) {
    state[i / 4][i % 4] = bf8_load(&src[i]);
  }
}

#if !defined(FAEST_TESTS)
static
#endif
    uint8_t
    invnorm(uint8_t in) {
  // check for in == 0 is not necessary, since bf8_inv(0) == 0

  const bf8_t bf_x_inv = bf8_inv(in);
  bf8_t bf_x_17        = bf_x_inv;
  for (unsigned int i = 0; i < 4; i++) {
    bf_x_17 = bf8_square(bf_x_17);
  }
  bf_x_17         = bf8_mul(bf_x_17, bf_x_inv);
  uint8_t y_prime = 0;
  bf8_store(&y_prime, bf_x_17);
  uint8_t y = 0;
  y ^= ((y_prime >> 0) & 1) << 0;
  y ^= ((y_prime >> 6) & 1) << 1;
  y ^= ((y_prime >> 7) & 1) << 2;
  y ^= ((y_prime >> 2) & 1) << 3;
  return y;
}

static uint8_t* store_invnorm_state(uint8_t* dst, aes_block_t state, unsigned int block_words) {
  for (unsigned int i = 0; i != block_words * 4; i += 2, ++dst) {
    uint8_t normstate_lo = invnorm(state[i / 4][i % 4]);
    uint8_t normstate_hi = invnorm(state[i / 4][(i + 1) % 4]);
    bf8_store(dst, (normstate_hi << 4) | normstate_lo);
  }
  return dst;
}

static uint8_t* store_state(uint8_t* dst, aes_block_t state, unsigned int block_words) {
  for (unsigned int i = 0; i != block_words * 4; ++i, ++dst) {
    bf8_store(dst, state[i / 4][i % 4]);
  }
  return dst;
}

static void aes_encrypt(const aes_round_keys_t* keys, aes_block_t state, unsigned int block_words,
                        unsigned int num_rounds) {
  // first round
  add_round_key(0, state, keys, block_words);

  for (unsigned int round = 1; round < num_rounds; ++round) {
    sub_bytes(state, block_words);
    shift_row(state, block_words);
    mix_column(state, block_words);
    add_round_key(round, state, keys, block_words);
  }

  // last round
  sub_bytes(state, block_words);
  shift_row(state, block_words);
  add_round_key(num_rounds, state, keys, block_words);
}

void aes128_encrypt_block(const aes_round_keys_t* key, const uint8_t* plaintext,
                          uint8_t* ciphertext) {
  aes_block_t state;
  load_state(state, plaintext, AES_BLOCK_WORDS);
  aes_encrypt(key, state, AES_BLOCK_WORDS, ROUNDS_128);
  store_state(ciphertext, state, AES_BLOCK_WORDS);
}

void aes192_encrypt_block(const aes_round_keys_t* key, const uint8_t* plaintext,
                          uint8_t* ciphertext) {
  aes_block_t state;
  load_state(state, plaintext, AES_BLOCK_WORDS);
  aes_encrypt(key, state, AES_BLOCK_WORDS, ROUNDS_192);
  store_state(ciphertext, state, AES_BLOCK_WORDS);
}

void aes256_encrypt_block(const aes_round_keys_t* key, const uint8_t* plaintext,
                          uint8_t* ciphertext) {
  aes_block_t state;
  load_state(state, plaintext, AES_BLOCK_WORDS);
  aes_encrypt(key, state, AES_BLOCK_WORDS, ROUNDS_256);
  store_state(ciphertext, state, AES_BLOCK_WORDS);
}

void rijndael192_encrypt_block(const aes_round_keys_t* key, const uint8_t* plaintext,
                               uint8_t* ciphertext) {
  aes_block_t state;
  load_state(state, plaintext, RIJNDAEL_BLOCK_WORDS_192);
  aes_encrypt(key, state, RIJNDAEL_BLOCK_WORDS_192, ROUNDS_192);
  store_state(ciphertext, state, RIJNDAEL_BLOCK_WORDS_192);
}

void rijndael256_encrypt_block(const aes_round_keys_t* key, const uint8_t* plaintext,
                               uint8_t* ciphertext) {
  aes_block_t state;
  load_state(state, plaintext, RIJNDAEL_BLOCK_WORDS_256);
  aes_encrypt(key, state, RIJNDAEL_BLOCK_WORDS_256, ROUNDS_256);
  store_state(ciphertext, state, RIJNDAEL_BLOCK_WORDS_256);
}

static void add_to_upper_word(uint8_t* iv, uint32_t tweak) {
  uint32_t iv3;
  memcpy(&iv3, iv + IV_SIZE - sizeof(uint32_t), sizeof(uint32_t));
  iv3 = htole32(le32toh(iv3) + tweak);
  memcpy(iv + IV_SIZE - sizeof(uint32_t), &iv3, sizeof(uint32_t));
}

void prg(const uint8_t* key, const uint8_t* iv, uint32_t tweak, uint8_t* out, unsigned int seclvl,
         size_t outlen) {
  uint8_t internal_iv[IV_SIZE];
  memcpy(internal_iv, iv, IV_SIZE);
  add_to_upper_word(internal_iv, tweak);

#if !defined(HAVE_OPENSSL)
  aes_round_keys_t round_key;

  switch (seclvl) {
  case 256:
    aes256_init_round_keys(&round_key, key);
    for (; outlen >= 16; outlen -= 16, out += 16) {
      aes_block_t state;
      load_state(state, internal_iv, AES_BLOCK_WORDS);
      aes_encrypt(&round_key, state, AES_BLOCK_WORDS, ROUNDS_256);
      store_state(out, state, AES_BLOCK_WORDS);
      aes_increment_iv(internal_iv);
    }
    if (outlen) {
      aes_block_t state;
      load_state(state, internal_iv, AES_BLOCK_WORDS);
      aes_encrypt(&round_key, state, AES_BLOCK_WORDS, ROUNDS_256);
      uint8_t tmp[16];
      store_state(tmp, state, AES_BLOCK_WORDS);
      memcpy(out, tmp, outlen);
    }
    return;
  case 192:
    aes192_init_round_keys(&round_key, key);
    for (; outlen >= 16; outlen -= 16, out += 16) {
      aes_block_t state;
      load_state(state, internal_iv, AES_BLOCK_WORDS);
      aes_encrypt(&round_key, state, AES_BLOCK_WORDS, ROUNDS_192);
      store_state(out, state, AES_BLOCK_WORDS);
      aes_increment_iv(internal_iv);
    }
    if (outlen) {
      aes_block_t state;
      load_state(state, internal_iv, AES_BLOCK_WORDS);
      aes_encrypt(&round_key, state, AES_BLOCK_WORDS, ROUNDS_192);
      uint8_t tmp[16];
      store_state(tmp, state, AES_BLOCK_WORDS);
      memcpy(out, tmp, outlen);
    }
    return;
  default:
    aes128_init_round_keys(&round_key, key);
    for (; outlen >= 16; outlen -= 16, out += 16) {
      aes_block_t state;
      load_state(state, internal_iv, AES_BLOCK_WORDS);
      aes_encrypt(&round_key, state, AES_BLOCK_WORDS, ROUNDS_128);
      store_state(out, state, AES_BLOCK_WORDS);
      aes_increment_iv(internal_iv);
    }
    if (outlen) {
      aes_block_t state;
      load_state(state, internal_iv, AES_BLOCK_WORDS);
      aes_encrypt(&round_key, state, AES_BLOCK_WORDS, ROUNDS_128);
      uint8_t tmp[16];
      store_state(tmp, state, AES_BLOCK_WORDS);
      memcpy(out, tmp, outlen);
    }
    return;
  }
#else
  const EVP_CIPHER* cipher;
  switch (seclvl) {
  case 256:
    cipher = EVP_aes_256_ecb();
    break;
  case 192:
    cipher = EVP_aes_192_ecb();
    break;
  default:
    cipher = EVP_aes_128_ecb();
    break;
  }
  assert(cipher);

  EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
  assert(ctx);
  EVP_CIPHER_CTX_set_padding(ctx, 1);

  EVP_EncryptInit_ex(ctx, cipher, NULL, key, NULL);

  int len = 0;
  for (size_t idx = 0; idx < outlen / IV_SIZE; idx += 1, out += IV_SIZE) {
    int ret = EVP_EncryptUpdate(ctx, out, &len, internal_iv, IV_SIZE);
    assert(ret == 1);
    assert(len == (int)IV_SIZE);
    aes_increment_iv(internal_iv);
  }
  if (outlen % IV_SIZE) {
    uint8_t last_block[IV_SIZE];
    int ret = EVP_EncryptUpdate(ctx, last_block, &len, internal_iv, IV_SIZE);
    assert(ret == 1);
    assert(len == (int)IV_SIZE);
    memcpy(out, last_block, outlen % IV_SIZE);
  }
  EVP_CIPHER_CTX_free(ctx);
#endif
}

uint8_t* aes_extend_witness(const uint8_t* key, const uint8_t* in, const faest_paramset_t* params) {
  const unsigned int lambda     = params->faest_param.lambda;
  const unsigned int l          = params->faest_param.l;
  const unsigned int S_ke       = params->faest_param.Ske;
  const unsigned int num_rounds = params->faest_param.R;
  const unsigned int nk         = lambda / 32;

  uint8_t* w           = malloc((l + 7) / 8);
  uint8_t* const w_out = w;

  unsigned int block_words = AES_BLOCK_WORDS;
  unsigned int beta        = 1;
  switch (params->faest_paramid) {
  case FAEST_192F:
  case FAEST_192S:
  case FAEST_256F:
  case FAEST_256S:
    beta = 2;
    break;
  case FAEST_EM_192F:
  case FAEST_EM_192S:
    block_words = RIJNDAEL_BLOCK_WORDS_192;
    break;
  case FAEST_EM_256F:
  case FAEST_EM_256S:
    block_words = RIJNDAEL_BLOCK_WORDS_256;
    break;
  default:
    break;
  }

  if (faest_is_em(params)) {
    // switch input and key for EM
    const uint8_t* tmp = key;
    key                = in;
    in                 = tmp;
  }

  // Step 3
  aes_round_keys_t round_keys;
  switch (lambda) {
  case 256:
    if (block_words == RIJNDAEL_BLOCK_WORDS_256) {
      rijndael256_init_round_keys(&round_keys, key);
    } else {
      aes256_init_round_keys(&round_keys, key);
    }
    break;
  case 192:
    if (block_words == RIJNDAEL_BLOCK_WORDS_192) {
      rijndael192_init_round_keys(&round_keys, key);
    } else {
      aes192_init_round_keys(&round_keys, key);
    }
    break;
  default:
    aes128_init_round_keys(&round_keys, key);
    break;
  }

  // Step 4
  if (!faest_is_em(params)) {
    // Key schedule constraints only needed for normal AES, not EM variant.
    for (unsigned int i = 0; i != nk; ++i) {
      memcpy(w, round_keys.round_keys[i / 4][i % 4], sizeof(aes_word_t));
      w += sizeof(aes_word_t);
    }

    for (unsigned int j = 0, ik = nk; j < S_ke / 4; ++j) {
      memcpy(w, round_keys.round_keys[ik / 4][ik % 4], sizeof(aes_word_t));
      w += sizeof(aes_word_t);
      ik += lambda == 192 ? 6 : 4;
    }
  } else {
    // saving the OWF key to the extended witness
    memcpy(w, in, lambda / 8);
    w += lambda / 8;
  }

  assert(w - w_out == params->faest_param.Lke / 8);

  // Step 10
  // common part for AES-128, EM-128, EM-192, EM-256, first part for AES-192 and AES-256
  {
    // Step 12
    aes_block_t state;
    load_state(state, in, block_words);

    // Step 13
    add_round_key(0, state, &round_keys, block_words);

    for (unsigned int round = 1; round < num_rounds; ++round) {
      if (round % 2 == 1) {
        // save inverse norm of the S-box inputs, in coloumn major order
        w = store_invnorm_state(w, state, block_words);
      }
      // Step 15
      sub_bytes(state, block_words);
      // Step 16
      shift_row(state, block_words);
      if (round % 2 == 0) {
        // Step 17
        w = store_state(w, state, block_words);
      }
      // Step 18
      mix_column(state, block_words);
      // Step 19
      add_round_key(round, state, &round_keys, block_words);
    }
    // last round is not commited to, so not computed
  }

  if (beta == 2) {
    // AES-192 and AES-256
    uint8_t buf[16];
    memcpy(buf, in, sizeof(buf));
    buf[0] ^= 0x1;

    // Step 12
    aes_block_t state;
    load_state(state, buf, block_words);

    // Step 13
    add_round_key(0, state, &round_keys, block_words);

    for (unsigned int round = 1; round < num_rounds; ++round) {
      if (round % 2 == 1) {
        // save inverse norm of the S-box inputs, in coloumn major order
        w = store_invnorm_state(w, state, block_words);
      }
      // Step 15
      sub_bytes(state, block_words);
      // Step 16
      shift_row(state, block_words);
      if (round % 2 == 0) {
        // Step 17
        w = store_state(w, state, block_words);
      }
      // Step 18
      mix_column(state, block_words);
      // Step 19
      add_round_key(round, state, &round_keys, block_words);
    }
    // last round is not commited to, so not computed
  }

  assert(w - w_out == l / 8);

  return w_out;
}
