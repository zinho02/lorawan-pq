#ifndef __FIELDS_AVX2_H__
#define __FIELDS_AVX2_H__

/* Check for AVX2 support */
#ifdef __AVX2__

#include "fields_common.h"
#include "fields_ref.h"
/* Needed for memcpy */
#include <string.h>
/* Needed for AVX2 assembly intrinsics */
#include <immintrin.h>

/* === GF(2) === */
/* NOTE: for atomic multiplication, using vectorization is suboptimal */
static inline uint8_t gf2_mult_avx2(uint8_t a, uint8_t b)
{
        return gf2_mult_ref(a, b);
}

#define AVX_MASK_SET 0x80000000

static inline __m256i load_incomplete_m256_aligned32(const uint8_t *a, uint32_t len)
{
        __m256i res;

        if(len == 4){
                /* We only keep one element */
                const __m256i mask = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, AVX_MASK_SET);
                res = _mm256_maskload_epi32((int const*)a, mask);
		goto out;
        }
        if(len == 8){
                /* We only keep 2 elements */
                const __m256i mask = _mm256_set_epi32(0, 0, 0, 0, 0, 0, AVX_MASK_SET, AVX_MASK_SET);
                res = _mm256_maskload_epi32((int const*)a, mask);
		goto out;
        }
        if(len == 12){
                /* We only keep 3 elements */
                const __m256i mask = _mm256_set_epi32(0, 0, 0, 0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
                res = _mm256_maskload_epi32((int const*)a, mask);
		goto out;
        }
        if(len == 16){
                /* We only keep 4 elements */
                const __m256i mask = _mm256_set_epi32(0, 0, 0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
                res = _mm256_maskload_epi32((int const*)a, mask);
		goto out;
        }
        if(len == 20){
                /* We only keep 5 elements */
                const __m256i mask = _mm256_set_epi32(0, 0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
                res = _mm256_maskload_epi32((int const*)a, mask);
		goto out;
        }
        if(len == 24){
                /* We only keep 6 elements */
                const __m256i mask = _mm256_set_epi32(0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
                res = _mm256_maskload_epi32((int const*)a, mask);
		goto out;
        }
        /* We only keep 7 elements */
        const __m256i mask = _mm256_set_epi32(0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
        res = _mm256_maskload_epi32((int const*)a, mask);

out:
        return res;
}

static inline __m256i load_incomplete_m256_unaligned32(const uint8_t *a, uint32_t len)
{
	/* Deal with the 32-bit leftover */
	__m256i res, expanded_leftover;
	uint32_t leftover;
	__m64 _leftover;
	unsigned int i;

	/* Extract the leftover */
	leftover = 0;
	for(i = 0; i < (len % 4); i++){
		leftover |= (a[(4 * (len / 4)) + i] << (8 * i));
	}
	_leftover = _mm_set_pi32(0, leftover);
	expanded_leftover = _mm256_broadcastd_epi32(_mm_movpi64_epi64(_leftover));

	if(len < 4){
		res = expanded_leftover & _mm256_set_epi64x(0, 0, 0, 0xFFFFFF);
		goto out;
	}
	if((len >= 4) && (len < 8)){
		/* We only keep one element */
		const __m256i mask = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, AVX_MASK_SET);
		res = _mm256_maskload_epi32((int const*)a, mask);
		res = _mm256_blend_epi32(res, expanded_leftover, (1 << 1));
		goto out;
	}
	if((len >= 8) && (len < 12)){
		/* We only keep 2 elements */
		const __m256i mask = _mm256_set_epi32(0, 0, 0, 0, 0, 0, AVX_MASK_SET, AVX_MASK_SET);
		res = _mm256_maskload_epi32((int const*)a, mask);
		res = _mm256_blend_epi32(res, expanded_leftover, (1 << 2));
		goto out;
	}
	if((len >= 12) && (len < 16)){
		/* We only keep 3 elements */
		const __m256i mask = _mm256_set_epi32(0, 0, 0, 0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
		res = _mm256_maskload_epi32((int const*)a, mask);
		res = _mm256_blend_epi32(res, expanded_leftover, (1 << 3));
		goto out;
	}
	if((len >= 16) && (len < 20)){
		/* We only keep 4 elements */
		const __m256i mask = _mm256_set_epi32(0, 0, 0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
		res = _mm256_maskload_epi32((int const*)a, mask);
		res = _mm256_blend_epi32(res, expanded_leftover, (1 << 4));
		goto out;
	}
	if((len >= 20) && (len < 24)){
		/* We only keep 5 elements */
		const __m256i mask = _mm256_set_epi32(0, 0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
		res = _mm256_maskload_epi32((int const*)a, mask);
		res = _mm256_blend_epi32(res, expanded_leftover, (1 << 5));
		goto out;
	}
	if((len >= 24) && (len < 28)){
		/* We only keep 6 elements */
		const __m256i mask = _mm256_set_epi32(0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
		res = _mm256_maskload_epi32((int const*)a, mask);
		res = _mm256_blend_epi32(res, expanded_leftover, (1 << 6));
		goto out;
	}
	/* We only keep 7 elements */
	const __m256i mask = _mm256_set_epi32(0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
	res = _mm256_maskload_epi32((int const*)a, mask);
	res = _mm256_blend_epi32(res, expanded_leftover, (1 << 7));

out:
	return res;
}

static inline void store_incomplete_m256_aligned32(__m256i in, uint8_t *a, uint32_t len)
{
        if(len == 4){
                /* We only keep one element */
                __m256i mask = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, AVX_MASK_SET);
                _mm256_maskstore_epi32((int*)a, mask, in);
		goto out;
        }
        if(len == 8){
                /* We only keep 2 elements */
                __m256i mask = _mm256_set_epi32(0, 0, 0, 0, 0, 0, AVX_MASK_SET, AVX_MASK_SET);
                _mm256_maskstore_epi32((int*)a, mask, in);
		goto out;
        }
        if(len == 12){
                /* We only keep 3 elements */
                __m256i mask = _mm256_set_epi32(0, 0, 0, 0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
                _mm256_maskstore_epi32((int*)a, mask, in);
		goto out;
        }
        if(len == 16){
                /* We only keep 4 elements */
                __m256i mask = _mm256_set_epi32(0, 0, 0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
                _mm256_maskstore_epi32((int*)a, mask, in);
		goto out;
        }
        if(len == 20){
                /* We only keep 5 elements */
                __m256i mask = _mm256_set_epi32(0, 0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
                _mm256_maskstore_epi32((int*)a, mask, in);
		goto out;
        }
        if(len == 24){
                /* We only keep 6 elements */
                __m256i mask = _mm256_set_epi32(0, 0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
                _mm256_maskstore_epi32((int*)a, mask, in);
		goto out;
        }
        /* We only keep 7 elements */
        __m256i mask = _mm256_set_epi32(0, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET, AVX_MASK_SET);
        _mm256_maskstore_epi32((int*)a, mask, in);

out:
        return;
}

static inline void store_incomplete_m256_unaligned32(__m256i in, uint8_t *a, uint32_t len)
{
	uint8_t local_a[32];
	_mm256_storeu_si256((__m256i*)&local_a[0], in);
	memcpy(&a[0], &local_a[0], len);

	return;
}

/* This helper tries to efficiently copy len bytes from the ymm register */
static inline void store_incomplete_m256(__m256i in, uint8_t *a, uint32_t len)
{
	if(len == 32){
		_mm256_storeu_si256((__m256i*)a, in);
	}
	else if(len % 4 == 0){
		store_incomplete_m256_aligned32(in, a, len);
	}
	else{
		store_incomplete_m256_unaligned32(in, a, len);
	}
	return;
}


/* This helper tries to efficiently copy len bytes in the ymm register */
static inline __m256i load_incomplete_m256(const uint8_t *a, uint32_t len)
{
	if(len % 4 == 0){
		return load_incomplete_m256_aligned32(a, len);
	}
	else{
		return load_incomplete_m256_unaligned32(a, len);
	}
}

static inline uint8_t parity_avx2(__m256i v) {
	uint8_t res;

	res  = _mm_popcnt_u64(_mm256_extract_epi64(v, 0)) & 1;
	res ^= _mm_popcnt_u64(_mm256_extract_epi64(v, 1)) & 1;
	res ^= _mm_popcnt_u64(_mm256_extract_epi64(v, 2)) & 1;
	res ^= _mm_popcnt_u64(_mm256_extract_epi64(v, 3)) & 1;

	return res;
}

static inline uint8_t sum_uint8_avx2(__m256i accu) {
        uint32_t i;
        uint8_t res;
        __attribute__((aligned(32))) uint8_t local_c[32];
        /* Store the result */
        _mm256_storeu_si256((__m256i*)local_c, accu);
        /* Finish the xor computation byte pet byte  */
        res = 0;
        for(i = 0; i < 32; i++){
                res ^= local_c[i];
        }

        return res;     
}

static inline uint16_t sum_uint16_avx2(__m256i accu) {
        uint32_t i;
        uint16_t res;
        __attribute__((aligned(32))) uint16_t local_c[16];
        /* Store the result */
        _mm256_storeu_si256((__m256i*)local_c, accu);
        /* Finish the xor computation byte per uint16_t  */
        res = 0;
        for(i = 0; i < 16; i++){
                res ^= local_c[i];
        }

        return res;     
}    

/*
 * Vector multiplied by a constant in GF(2).
 */
static inline void gf2_constant_vect_mult_avx2(uint8_t b, const uint8_t *a, uint8_t *c, uint32_t len)
{
	gf2_constant_vect_mult_ref(b, a, c, len);

        return;
}

static inline uint8_t gf2_vect_mult_avx2(const uint8_t *a, const uint8_t *b, uint32_t len_bits)
{
	uint32_t i;
	__m256i accu, _a, _b;
	uint32_t len = (len_bits / 8);

	/* Set the accumulator to 0 */
	accu = _mm256_setzero_si256();
	for(i = 0; i < len; i += 32){
		if((len-i) < 32){
			/* Note: if we are here, we are sure that we are 32-bit aligned */
			_a = load_incomplete_m256(&a[i], len-i);
			_b = load_incomplete_m256(&b[i], len-i);
		}
		else{
			/* Obvious 256-bit */
			_a = _mm256_lddqu_si256((__m256i*)&a[i]);
			_b = _mm256_lddqu_si256((__m256i*)&b[i]);
		}
		/* Vectorized AND of inputs and then XOR with the accumulator */
		accu ^= (_a & _b);
	}

	/* Now, we have to compute the parity bit, do it 64 bits per 64 bits */
	return parity_avx2(accu);
}

/* Matrix and vector multiplication over GF(2) 
 * C = A * X, where X is a vector
 * Matrix is supposed to be square n x n, and vector n x 1
 * The output is a vector n x 1
 * */
/* XXX: TODO: this can be optimized by packing rows in zmm when n <= 256 */
static inline void gf2_mat_mult_avx2(const uint8_t *A, const uint8_t *X, uint8_t *Y, uint32_t n, matrix_type mtype)
{
        /* XXX: NOTE: because of alignment and loading latencies, treating the matrix as "regular" seems always better
         * than using the trianglar shape ... */
	(void)mtype;
	GF2_MAT_MULT(A, X, Y, n, REG, gf2_vect_mult_avx2);
}

/* GF(2) matrix transposition */
static inline void gf2_mat_transpose_avx2(const uint8_t *A, uint8_t *B, uint32_t n, matrix_type mtype)
{
        gf2_mat_transpose_ref(A, B, n, mtype);
}

/* === GF(256) === */
/* NOTE: for atomic multiplication, using vectorization is suboptimal */
static inline uint8_t gf256_mult_avx2(uint8_t x, uint8_t y)
{
	return gf256_mult_ref(x, y);
}

static inline __m256i gf256_mult_vectorized_avx2(__m256i _a, __m256i _b)
{
        uint32_t j;
        /* Our reduction polynomial */
        const __m256i red_poly = _mm256_set_epi64x(0x1B1B1B1B1B1B1B1B, 0x1B1B1B1B1B1B1B1B, 0x1B1B1B1B1B1B1B1B, 0x1B1B1B1B1B1B1B1B);
        const __m256i lsb      = _mm256_set_epi64x(0x0101010101010101, 0x0101010101010101, 0x0101010101010101, 0x0101010101010101);
        const __m256i rm_lsb   = _mm256_set_epi64x(0xfefefefefefefefe, 0xfefefefefefefefe, 0xfefefefefefefefe, 0xfefefefefefefefe);
        const __m256i msb      = _mm256_set_epi64x(0x8080808080808080, 0x8080808080808080, 0x8080808080808080, 0x8080808080808080);
        const __m256i rm_msb   = _mm256_set_epi64x(0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f);
        const __m256i zero     = _mm256_setzero_si256();
	__m256i accu = _mm256_setzero_si256();

        /* Compute the vectorized multiplication in GF(256) */
        for(j = 0; j < 8; j++){
                __m256i mask_lsb = _mm256_slli_epi64(_b & lsb, 7);
                __m256i mask_msb = _a & msb;
                /* Conditionally xor with a or 0 */
                accu ^= _mm256_blendv_epi8(zero, _a, mask_lsb);
                /* Shift right of _a by 1 is simply a global shit right with a AND 0x80 */
                _a = _mm256_slli_epi64(_a, 1) & rm_lsb;
                /* Conditionally xor with polynomial reduction or not */
                _a ^= _mm256_blendv_epi8(zero, red_poly, mask_msb);
                /* Shift left of _b by 1 is simply a global shift left with a AND 0x01 */
                _b = _mm256_srli_epi64(_b, 1) & rm_msb;
        }

        return accu;
}

/*
 * Vector multiplied by a constant in GF(256).
 */
static inline void gf256_constant_vect_mult_avx2(uint8_t b, const uint8_t *a, uint8_t *c, uint32_t len)
{
	uint32_t i;
	__m256i _a, _b;

	/* Load the constant byte b broadcasted in _b */
	_b = _mm256_set1_epi8(b);

        for(i = 0; i < len; i += 32){
                if((len-i) < 32){
                        _a = load_incomplete_m256(&a[i], len-i);
                        /* Vectorized multiplication in GF(256) */
                        store_incomplete_m256(gf256_mult_vectorized_avx2(_a, _b), &c[i], len-i);
                }
                else{
                        /* Obvious 512-bit */
                        _a = _mm256_lddqu_si256((__m256i*)&a[i]);
                        /* Vectorized multiplication in GF(256) */
                        _mm256_storeu_si256((void*)&c[i], gf256_mult_vectorized_avx2(_a, _b));
                }       
        }

        return;
}

/*
 * Vector to vector multiplication in GF(256).
 * Takes two vectors of length 'len', and returns a byte (element in GF(256))
 */
static inline uint8_t gf256_vect_mult_avx2(const uint8_t *a, const uint8_t *b, uint32_t len)
{
	uint32_t i;
	__m256i accu, _a, _b;

	/* Set the accumulator to 0 */
	accu = _mm256_setzero_si256();

	for(i = 0; i < len; i += 32){
		if((len-i) < 32){
			_a = load_incomplete_m256(&a[i], len-i);
			_b = load_incomplete_m256(&b[i], len-i);
		}
		else{
			/* Obvious 256-bit */
			_a = _mm256_lddqu_si256((__m256i*)&a[i]);
			_b = _mm256_lddqu_si256((__m256i*)&b[i]);
		}
		accu ^= gf256_mult_vectorized_avx2(_a, _b); 
	}

	return sum_uint8_avx2(accu);
}


/* Matrix and vector multiplication over GF(256) 
 * C += A * X, where X is a vector
 * Matrix is supposed to be square n x n, and vector n x 1
 * The output is a vector n x 1
 * */
static inline void gf256_mat_mult_avx2(const uint8_t *A, const uint8_t *X, uint8_t *Y, uint32_t n, matrix_type mtype)
{
        /* XXX: NOTE: because of alignment and loading latencies, treating the matrix as "regular" seems always better
         * than using the trianglar shape ... */
	(void)mtype;
	GF256_MAT_MULT(A, X, Y, n, REG, gf256_vect_mult_avx2);
}

/*
 * "Hybrid" scalar multiplication of a vector in GF(2) and a vector in GF(256)
 */
static inline uint8_t gf2_gf256_vect_mult_avx2(const uint8_t *a_gf2, const uint8_t *b_gf256, uint32_t len)
{
        uint32_t i;
        const __m256i zero = _mm256_setzero_si256();
	__m256i _a, _b;

        /* Set the accumulator to 0 */
        __m256i accu = _mm256_setzero_si256();

        for(i = 0; i < len; i += 32){
		if((len - i) < 32){
			uint32_t ceil_len = ((len - i) % 8 == 0) ? ((len - i) / 8) : (((len - i) / 8) + 1);
			_a = load_incomplete_m256(&a_gf2[i / 8], ceil_len);
			_b = load_incomplete_m256(&b_gf256[i], len - i);
		}
		else{
			/* Obvious 256-bit */
			_a = load_incomplete_m256(&a_gf2[i / 8], 4);
			_b = _mm256_lddqu_si256((__m256i*)&b_gf256[i]);
		}
		/* Create a selection mask from the bits in _a */
		const __m256i shuff_msk = _mm256_set_epi8(3, 3, 3,  3,  3, 3, 3, 3, 2, 2, 2,  2,  2, 2, 2, 2,
                                                          1, 1, 1,  1,  1, 1, 1, 1, 0, 0, 0,  0,  0, 0, 0, 0);
		const __m256i and_msk = _mm256_set_epi8(0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001,
							0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001,
							0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001,
							0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001);

		const __m256i xor_bitwise_not = _mm256_set_epi64x(0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff);
        	const __m256i msb      = _mm256_set_epi64x(0x8080808080808080, 0x8080808080808080, 0x8080808080808080, 0x8080808080808080);
		/* Copy in the two lanes */
		_a = _mm256_permute4x64_epi64(_a, 0b01000100);
		/* Only keep the selection bits */
		_a = _mm256_shuffle_epi8(_a, shuff_msk) & and_msk;
		/* Transform these bits to either 0 or 0xFF and keep 0x80 */
		_a = (_mm256_cmpeq_epi8(_a, zero) ^ xor_bitwise_not) & msb;
		/* Use blending for bytes selection */
                accu ^= _mm256_blendv_epi8(zero, _b, _a);
        }
        return sum_uint8_avx2(accu);
}

/*
 * "Hybrid" multiplication of a constant in GF(2) and a vector in GF(256)
 */
static inline void gf2_gf256_constant_vect_mult_avx2(uint8_t a_gf2, const uint8_t *b_gf256, uint8_t *c_gf256, uint32_t n)
{
	gf2_gf256_constant_vect_mult_ref(a_gf2, b_gf256, c_gf256, n);

        return;
}

/*
 * "Hybrid" multiplication of a constant in GF(256) and a vector in GF(2)
 */
static inline void gf256_gf2_constant_vect_mult_avx2(uint8_t a_gf256, const uint8_t *b_gf2, uint8_t *c_gf256, uint32_t len)
{
	uint32_t i;
        const __m256i zero = _mm256_setzero_si256();
	__m256i _a, _b;

        /* Broadcast the constant value */
	_a = _mm256_set1_epi8(a_gf256);

        for(i = 0; i < len; i += 32){
		uint32_t ceil_len;
		if((len - i) < 32){
			ceil_len = ((len - i) % 8 == 0) ? ((len - i) / 8) : (((len - i) / 8) + 1);
			_b = load_incomplete_m256(&b_gf2[i / 8], ceil_len);
		}
		else{
			ceil_len = 4;
			/* Obvious 256-bit */
			_b = load_incomplete_m256(&b_gf2[i / 8], 4);
		}
		/* Create a selection mask from the bits in _a */
		const __m256i shuff_msk = _mm256_set_epi8(3, 3, 3,  3,  3, 3, 3, 3, 2, 2, 2,  2,  2, 2, 2, 2,
                                                          1, 1, 1,  1,  1, 1, 1, 1, 0, 0, 0,  0,  0, 0, 0, 0);
		const __m256i and_msk = _mm256_set_epi8(0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001,
							0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001,
							0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001,
							0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001);

		const __m256i xor_bitwise_not = _mm256_set_epi64x(0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff);
        	const __m256i msb      = _mm256_set_epi64x(0x8080808080808080, 0x8080808080808080, 0x8080808080808080, 0x8080808080808080);
		/* Copy in the two lanes */
		_b = _mm256_permute4x64_epi64(_b, 0b01000100);
		/* Only keep the selection bits */
		_b = _mm256_shuffle_epi8(_b, shuff_msk) & and_msk;
		/* Transform these bits to either 0 or 0xFF and keep 0x80 */
		_b = (_mm256_cmpeq_epi8(_b, zero) ^ xor_bitwise_not) & msb;
		/* Use blending for bytes selection */
                __m256i _c = _mm256_blendv_epi8(zero, _a, _b);
		/* Store the result */
		store_incomplete_m256(_c, &c_gf256[i], 8 * ceil_len);
        }

        return;
}

/*
 * "Hybrid" scalar multiplication of a vector in GF(256) and a vector in GF(2)
 */
static inline uint8_t gf256_gf2_vect_mult_avx2(const uint8_t *a_gf256, const uint8_t *b_gf2, uint32_t n)
{
        return gf2_gf256_vect_mult_avx2(b_gf2, a_gf256, n);
}

/* 
 * "Hybrid" matrix multiplication of a matrix in GF(2) and a vector in GF(256), resulting
 *  in a vector in GF(256)
 */                     
static inline void gf2_gf256_mat_mult_avx2(const uint8_t *A, const uint8_t *X, uint8_t *Y, uint32_t n, matrix_type mtype)
{                       
        /* XXX: NOTE: because of alignment and loading latencies, treating the matrix as "regular" seems always better
         * than using the trianglar shape ... */
        (void)mtype; 
        GF2_GF256_MAT_MULT(A, X, Y, n, REG, gf2_gf256_vect_mult_avx2);
}

/*
 * "Hybrid" matrix multiplication of a matrix in GF(256) and a vector in GF(2), resulting
 *  in a vector in GF(256)
 */
static inline void gf256_gf2_mat_mult_avx2(const uint8_t *A, const uint8_t *X, uint8_t *Y, uint32_t n, matrix_type mtype)
{
        /* XXX: NOTE: because of alignment and loading latencies, treating the matrix as "regular" seems always better
         * than using the trianglar shape ... */
        (void)mtype; 
        GF256_GF2_MAT_MULT(A, X, Y, n, REG, gf256_gf2_vect_mult_avx2);
}

/* GF(256) matrix transposition */
static inline void gf256_mat_transpose_avx2(const uint8_t *A, uint8_t *B, uint32_t n, matrix_type mtype)
{
        gf256_mat_transpose_ref(A, B, n, mtype);
}


/* === GF(256^2) === */
/* NOTE: for atomic multiplication, using vectorization is suboptimal */
static inline uint16_t gf256to2_mult_avx2(uint16_t x, uint16_t y)
{
	return gf256to2_mult_ref(x, y);
}

/* Vectorize multiplication of _a and _b in GF(256^2): the elements in the field are made of
 * 16 bits each in the lanes of the ymm */
static inline __m256i gf256to2_mult_vectorized_avx2(__m256i _a, __m256i _b)
{
        const __m256i shuff_msk_crossed = _mm256_set_epi8(30, 31, 28, 29, 26, 27, 24, 25, 22, 23, 20, 21, 18, 19, 16, 17,
                                                          14, 15, 12, 13, 10, 11, 8 ,  9,  6,  7,  4,  5,  2,  3,  0,  1);
        const __m256i shuff_msk1 = _mm256_set_epi8(30, 30, 28, 28, 26, 26, 24, 24, 22, 22, 20, 20, 18, 18, 16, 16,
                                                   14, 14, 12, 12, 10, 10, 8 ,  8,  6,  6,  4,  4,  2,  2,  0,  0);
        const __m256i shuff_msk2 = _mm256_set_epi8(31, 31, 29, 29, 27, 27, 25, 25, 23, 23, 21, 21, 19, 19, 17, 17,
                                                   15, 15, 13, 13, 11, 11, 9 ,  9,  7,  7,  5,  5,  3,  3,  1,  1);

        const __m256i const32 = _mm256_set_epi64x(0x0020002000200020, 0x0020002000200020, 0x0020002000200020, 0x0020002000200020);

	const __m256i mask_c1 = _mm256_set_epi64x(0x8000800080008000, 0x8000800080008000, 0x8000800080008000, 0x8000800080008000);
        const __m256i zero = _mm256_setzero_si256();

	__m256i ab = gf256_mult_vectorized_avx2(_a, _b);
	__m256i a0b0 = _mm256_shuffle_epi8(ab, shuff_msk1);
	__m256i a1b1 = _mm256_shuffle_epi8(ab, shuff_msk2);
	__m256i a1b1_32 = gf256_mult_vectorized_avx2(a1b1, const32);
	/* */
	__m256i a0_xor_a1 = _a ^ _mm256_shuffle_epi8(_a, shuff_msk_crossed);
	__m256i b0_xor_b1 = _mm256_blendv_epi8(zero, _b ^ _mm256_shuffle_epi8(_b, shuff_msk_crossed), mask_c1);
	__m256i mult_ab_xor = gf256_mult_vectorized_avx2(a0_xor_a1, b0_xor_b1);
	
	/* Compute the result */
	__m256i res = a0b0 ^ a1b1_32 ^ mult_ab_xor;

        return res;
}

/*
 * Vector multiplied by a constant in GF(256^2).
 */
static inline void gf256to2_constant_vect_mult_avx2(uint16_t b, const uint16_t *a, uint16_t *c, uint32_t len)
{
	uint32_t i;
	__m256i _a, _b;

	/* Load the constant byte b broadcasted in _b */
	_b = _mm256_set1_epi16(b);

        for(i = 0; i < (2 * len); i += 32){
                if(((2 * len)-i) < 32){
                        _a = load_incomplete_m256((const uint8_t*)&a[i / 2], ((2 * len) - i));
                        /* Vectorized multiplication in GF(256) */
                        store_incomplete_m256(gf256to2_mult_vectorized_avx2(_a, _b), (uint8_t*)&c[i / 2], (2 * len)-i);
                }
                else{
                        /* Obvious 512-bit */
                        _a = _mm256_lddqu_si256((__m256i*)&a[i / 2]);
                        /* Vectorized multiplication in GF(256) */
                        _mm256_storeu_si256((__m256i*)&c[i / 2], gf256to2_mult_vectorized_avx2(_a, _b));
                }       
        }

        return;
}

/* Perform a multiplication in GF(256^2) of elements in vectors a an b */
static inline uint16_t gf256to2_vect_mult_avx2(const uint16_t *a, const uint16_t *b, uint32_t len)
{
        uint32_t i;
        __m256i accu, _a, _b;

        /* Set the accumulator to 0 */
        accu = _mm256_setzero_si256();

        for(i = 0; i < (2 * len); i += 32){
                if(((2 * len)-i) < 32){
                        _a = load_incomplete_m256((const uint8_t*)&a[i / 2], ((2 * len) - i));
                        _b = load_incomplete_m256((const uint8_t*)&b[i / 2], ((2 * len) - i));
                }
                else{
                        /* Obvious 256-bit */
                        _a = _mm256_lddqu_si256((__m256i*)&a[i / 2]);
                        _b = _mm256_lddqu_si256((__m256i*)&b[i / 2]);
                }
                accu ^= gf256to2_mult_vectorized_avx2(_a, _b);
        }

        return sum_uint16_avx2(accu);
}

/*
 * GF(2^16) matrix multiplication
 */
static inline void gf256to2_mat_mult_avx2(const uint16_t *A, const uint16_t *X, uint16_t *Y, uint32_t n, matrix_type mtype)
{
        /* XXX: NOTE: because of alignment and loading latencies, treating the matrix as "regular" seems always better
         * than using the trianglar shape ... */
        (void)mtype;
        GF256to2_MAT_MULT(A, X, Y, n, REG, gf256to2_vect_mult_avx2);
}

/*
 * "Hybrid" constant multiplication of a constant in GF(2) and a vector in GF(256^2)
 */
static inline void gf2_gf256to2_constant_vect_mult_avx2(uint8_t a_gf2, const uint16_t *b_gf256to2, uint16_t *c_gf256to2, uint32_t n)
{
	gf2_gf256to2_constant_vect_mult_ref(a_gf2, b_gf256to2, c_gf256to2, n);

        return;
}

/*
 * "Hybrid" constant multiplication of a constant in GF(256^2) and a vector in GF(2)
 */
static inline void gf256to2_gf2_constant_vect_mult_avx2(uint16_t a_gf256to2, const uint8_t *b_gf2, uint16_t *c_gf256to2, uint32_t len)
{
        uint32_t i;
        const __m256i zero = _mm256_setzero_si256();
	__m256i _a, _b;

        /* Broadcast the constant value */
	_a = _mm256_set1_epi16(a_gf256to2);

        for(i = 0; i < (2*len); i += 32){
		uint32_t ceil_len;
		if(((2*len) - i) < 32){
			ceil_len = (((2*len) - i) % 16 == 0) ? (((2*len) - i) / 16) : ((((2*len) - i) / 16) + 1);
			_b = load_incomplete_m256(&b_gf2[i / 16], ceil_len);
		}
		else{
			/* Obvious 256-bit */
			ceil_len = 2;
			_b = load_incomplete_m256(&b_gf2[i / 16], 2);
		}
		/* Create a selection mask from the bits in _a */
		const __m256i shuff_msk = _mm256_set_epi8(1, 1, 1,  1,  1, 1, 1, 1, 1, 1, 1,  1,  1, 1, 1, 1,
                                                          0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0);
		const __m256i and_msk = _mm256_set_epi8(0b10000000, 0b10000000, 0b01000000, 0b01000000, 0b00100000, 0b00100000, 0b00010000, 0b00010000,
							0b00001000, 0b00001000, 0b00000100, 0b00000100, 0b00000010, 0b00000010, 0b00000001, 0b00000001,
							0b10000000, 0b10000000, 0b01000000, 0b01000000, 0b00100000, 0b00100000, 0b00010000, 0b00010000,
							0b00001000, 0b00001000, 0b00000100, 0b00000100, 0b00000010, 0b00000010, 0b00000001, 0b00000001);

		const __m256i xor_bitwise_not = _mm256_set_epi64x(0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff);
        	const __m256i msb      = _mm256_set_epi64x(0x8080808080808080, 0x8080808080808080, 0x8080808080808080, 0x8080808080808080);
		/* Only keep the selection bits */
		_b = _mm256_permute4x64_epi64(_b, 0b01000100);
		_b = _mm256_shuffle_epi8(_b, shuff_msk);
		_b = _b & and_msk;
		/* Transform these bits to either 0 or 0xFF and keep 0x80 */
		_b = (_mm256_cmpeq_epi8(_b, zero) ^ xor_bitwise_not) & msb;
		/* Use blending for bytes selection */
                __m256i _c = _mm256_blendv_epi8(zero, _a, _b);
		/* Store the result */
		store_incomplete_m256(_c, (uint8_t*)&c_gf256to2[i / 2], 16 * ceil_len);
        }
        return;
}

/*
 * "Hybrid" constant multiplication of a constant in GF(256^2) and a vector in GF(256)
 */
static inline void gf256_gf256to2_constant_vect_mult_avx2(uint8_t a_gf256, const uint16_t *b_gf256to2, uint16_t *c_gf256to2, uint32_t n)
{
	gf256_gf256to2_constant_vect_mult_ref(a_gf256, b_gf256to2, c_gf256to2, n);

	return;
}

/*
 * "Hybrid" constant multiplication of a constant in GF(256^2) and a vector in GF(256)
 */
static inline void gf256to2_gf256_constant_vect_mult_avx2(uint16_t a_gf256to2, const uint8_t *b_gf256, uint16_t *c_gf256to2, uint32_t len)
{
	uint32_t i;
	__m256i _a, _b;
        const __m256i shuff_msk = _mm256_set_epi8(15, 15, 14, 14, 13, 13, 12, 12, 11, 11, 10, 10, 9, 9, 8, 8,
                                                   7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2,  2,  1, 1, 0, 0);

	/* Load the constant byte b broadcasted in _b */
	_a = _mm256_set1_epi16(a_gf256to2);

        for(i = 0; i < len; i += 16){
		uint32_t to_load = (len - i) < 16 ? (len - i) : 16;
                _b = load_incomplete_m256((const uint8_t*)&b_gf256[i], to_load);
		/* Copy in the two lanes */
		_b = _mm256_permute4x64_epi64(_b, 0b01000100);
                /* Duplicate elements in the register */
                _b = _mm256_shuffle_epi8(_b, shuff_msk);
                /* Vectorized multiplication in GF(256) */
                store_incomplete_m256(gf256_mult_vectorized_avx2(_a, _b), (uint8_t*)&c_gf256to2[i], 2 * to_load);
        }

        return;
}

/*
 * "Hybrid" scalar multiplication of a vector in GF(2) and a vector in GF(256^2)
 */
static inline uint16_t gf2_gf256to2_vect_mult_avx2(const uint8_t *a_gf2, const uint16_t *b_gf256to2, uint32_t len)
{
        uint32_t i;
        const __m256i zero = _mm256_setzero_si256();
	__m256i _a, _b;

        /* Set the accumulator to 0 */
        __m256i accu = _mm256_setzero_si256();

        for(i = 0; i < (2*len); i += 32){
		if(((2*len) - i) < 32){
			uint32_t ceil_len = (((2*len) - i) % 16 == 0) ? (((2*len) - i) / 16) : ((((2*len) - i) / 16) + 1);
			_a = load_incomplete_m256(&a_gf2[i / 16], ceil_len);
			_b = load_incomplete_m256((const uint8_t*)&b_gf256to2[i / 2], (2*len) - i);
		}
		else{
			/* Obvious 256-bit */
			_a = load_incomplete_m256(&a_gf2[i / 16], 2);
			_b = _mm256_lddqu_si256((__m256i*)&b_gf256to2[i / 2]);
		}
		/* Create a selection mask from the bits in _a */
		const __m256i shuff_msk = _mm256_set_epi8(1, 1, 1,  1,  1, 1, 1, 1, 1, 1, 1,  1,  1, 1, 1, 1,
                                                          0, 0, 0,  0,  0, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0, 0);
		const __m256i and_msk = _mm256_set_epi8(0b10000000, 0b10000000, 0b01000000, 0b01000000, 0b00100000, 0b00100000, 0b00010000, 0b00010000,
							0b00001000, 0b00001000, 0b00000100, 0b00000100, 0b00000010, 0b00000010, 0b00000001, 0b00000001,
							0b10000000, 0b10000000, 0b01000000, 0b01000000, 0b00100000, 0b00100000, 0b00010000, 0b00010000,
							0b00001000, 0b00001000, 0b00000100, 0b00000100, 0b00000010, 0b00000010, 0b00000001, 0b00000001);

		const __m256i xor_bitwise_not = _mm256_set_epi64x(0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff);
        	const __m256i msb      = _mm256_set_epi64x(0x8080808080808080, 0x8080808080808080, 0x8080808080808080, 0x8080808080808080);
		/* Copy in the two lanes */
		_a = _mm256_permute4x64_epi64(_a, 0b01000100);
		/* Only keep the selection bits */
		_a = _mm256_shuffle_epi8(_a, shuff_msk) & and_msk;
		/* Transform these bits to either 0 or 0xFF and keep 0x80 */
		_a = (_mm256_cmpeq_epi8(_a, zero) ^ xor_bitwise_not) & msb;
		/* Use blending for bytes selection */
                accu ^= _mm256_blendv_epi8(zero, _b, _a);
        }
        return sum_uint16_avx2(accu);
}

/*
 * "Hybrid" scalar multiplication of a vector in GF(256^2) and a vector in GF(256)
 */
static inline uint16_t gf256to2_gf2_vect_mult_avx2(const uint16_t *a_gf256to2, const uint8_t *b_gf2, uint32_t n)
{
        return gf2_gf256to2_vect_mult_avx2(b_gf2, a_gf256to2, n);
}

/*
 * "Hybrid" scalar multiplication of a vector in GF(256) and a vector in GF(256^2)
 */
static inline uint16_t gf256_gf256to2_vect_mult_avx2(const uint8_t *a_gf256, const uint16_t *b_gf256to2, uint32_t len)
{
        /* Note: the multiplication of an element in GF(256) and an element in GF(256^2)
         * simply consists in two multiplications in GF(256) (this is multiplying a constant by a degree 1 polynomial)
         * */
        uint32_t i;
        __m256i accu, _a, _b;

        /* Set the accumulator to 0 */
        accu = _mm256_setzero_si256();

        for(i = 0; i < (2 * len); i += 32){
                const __m256i shuff_msk = _mm256_set_epi8(15, 15, 14, 14, 13, 13, 12, 12, 11, 11, 10, 10, 9, 9, 8, 8,
                                                          7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2,  2,  1, 1, 0, 0);
                if(((2 * len)-i) < 32){
                        _a = load_incomplete_m256((const uint8_t*)&a_gf256[i / 2], ((2 * len)-i) / 2);
                        _b = load_incomplete_m256((const uint8_t*)&b_gf256to2[i / 2], (2 * len)-i);
                }
                else{
                        /* Obvious 256-bit */
                        _a = load_incomplete_m256((const uint8_t*)&a_gf256[i / 2], 16);
                        _b = _mm256_lddqu_si256((__m256i*)&b_gf256to2[i / 2]);
                }
                /* Duplicate the values in _a */
		_a = _mm256_permute4x64_epi64(_a, 0b01000100);
                _a = _mm256_shuffle_epi8(_a, shuff_msk);
                /* Multiply in GF(256) */
                accu ^= gf256_mult_vectorized_avx2(_a, _b);
        }

        return sum_uint16_avx2(accu);
}

/*
 * "Hybrid" scalar multiplication of a vector in GF(256^2) and a vector in GF(256)
 */
static inline uint16_t gf256to2_gf256_vect_mult_avx2(const uint16_t *a_gf256to2, const uint8_t *b_gf256, uint32_t n)
{
        return gf256_gf256to2_vect_mult_avx2(b_gf256, a_gf256to2, n);
}

/*
 * "Hybrid" matrix multiplication of a matrix in GF(2) and a vector in GF(256^2), resulting
 *  in a vector in GF(256^2)
 */
static inline void gf2_gf256to2_mat_mult_avx2(const uint8_t *A, const uint16_t *X, uint16_t *Y, uint32_t n, matrix_type mtype)
{
        /* XXX: NOTE: because of alignment and loading latencies, treating the matrix as "regular" seems always better
         * than using the trianglar shape ... */
        (void)mtype;
        GF2_GF256to2_MAT_MULT(A, X, Y, n, REG, gf2_gf256to2_vect_mult_avx2);
}

/*
 * "Hybrid" matrix multiplication of a matrix in GF(256^2) and a vector in GF(2), resulting
 *  in a vector in GF(256^2)
 */
static inline void gf256to2_gf2_mat_mult_avx2(const uint16_t *A, const uint8_t *X, uint16_t *Y, uint32_t n, matrix_type mtype)
{
        /* XXX: NOTE: because of alignment and loading latencies, treating the matrix as "regular" seems always better
         * than using the trianglar shape ... */
        (void)mtype;
        GF256to2_GF2_MAT_MULT(A, X, Y, n, REG, gf256to2_gf2_vect_mult_avx2);
}

/*
 * "Hybrid" matrix multiplication of a matrix in GF(256) and a vector in GF(256^2), resulting
 *  in a vector in GF(256^2)
 */
static inline void gf256_gf256to2_mat_mult_avx2(const uint8_t *A, const uint16_t *X, uint16_t *Y, uint32_t n, matrix_type mtype)
{
        /* XXX: NOTE: because of alignment and loading latencies, treating the matrix as "regular" seems always better
         * than using the trianglar shape ... */
        (void)mtype;
        GF256to2_MAT_MULT(A, X, Y, n, REG, gf256_gf256to2_vect_mult_avx2);
}

/*
 * "Hybrid" matrix multiplication of a matrix in GF(256^2) and a vector in GF(256), resulting
 *  in a vector in GF(256^2)
 */
static inline void gf256to2_gf256_mat_mult_avx2(const uint16_t *A, const uint8_t *X, uint16_t *Y, uint32_t n, matrix_type mtype)
{
        /* XXX: NOTE: because of alignment and loading latencies, treating the matrix as "regular" seems always better
         * than using the trianglar shape ... */
        (void)mtype; 
        GF256to2_MAT_MULT(A, X, Y, n, REG, gf256to2_gf256_vect_mult_avx2);
}

/* GF(256^2) matrix transposition */
static inline void gf256to2_mat_transpose_avx2(const uint16_t *A, uint16_t *B, uint32_t n, matrix_type mtype)
{
        gf256to2_mat_transpose_ref(A, B, n, mtype);
}

#endif /* __AVX2__ */

#endif /* __FIELDS_AVX2_H__ */
