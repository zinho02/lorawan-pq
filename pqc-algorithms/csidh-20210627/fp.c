
#include <stddef.h>
#include <string.h>
#include <assert.h>

#include "params.h"
#include "uint.h"
#include "fp.h"

uint64_t *fp_mul_counter = NULL;
uint64_t *fp_sq_counter = NULL;
uint64_t *fp_inv_counter = NULL;
uint64_t *fp_sqt_counter = NULL;

bool fp_eq(fp const *x, fp const *y)
{
    uint64_t r = 0;
    for (size_t k = 0; k < LIMBS; ++k)
        r |= x->c[k] ^ y->c[k];
    return !r;
}

void fp_set(fp *x, uint64_t y)
{
    uint_set((uint *) x, y);
    fp_enc(x, (uint *) x);
}

static void reduce_once(uint *x)
{
    uint t;
    if (!uint_sub3(&t, x, &p))
        *x = t;
}

void fp_add3(fp *x, fp const *y, fp const *z)
{
    bool c = uint_add3((uint *) x, (uint *) y, (uint *) z);
    (void) c; assert(!c);
    reduce_once((uint *) x);
}

void fp_add2(fp *x, fp const *y)
{
    fp_add3(x, x, y);
}

void fp_sub3(fp *x, fp const *y, fp const *z)
{
    if (uint_sub3((uint *) x, (uint *) y, (uint *) z))
        uint_add3((uint *) x, (uint *) x, &p);
}

void fp_sub2(fp *x, fp const *y)
{
    fp_sub3(x, x, y);
}


/* Montgomery arithmetic */

void fp_enc(fp *x, uint const *y)
{
    fp_mul3(x, (fp *) y, &r_squared_mod_p);
}

void fp_dec(uint *x, fp const *y)
{
    fp_mul3((fp *) x, y, (fp *) &uint_1);
}

static inline void mul64(uint64_t *hi, uint64_t *lo, uint64_t a, uint64_t b) {
    uint64_t a_lo = (uint32_t)a;
    uint64_t a_hi = a >> 32;
    uint64_t b_lo = (uint32_t)b;
    uint64_t b_hi = b >> 32;

    uint64_t p0 = a_lo * b_lo;
    uint64_t p1 = a_lo * b_hi;
    uint64_t p2 = a_hi * b_lo;
    uint64_t p3 = a_hi * b_hi;

    uint64_t mid = (p0 >> 32) + (uint32_t)p1 + (uint32_t)p2;
    *lo = (p0 & 0xFFFFFFFFULL) | (mid << 32);
    *hi = p3 + (p1 >> 32) + (p2 >> 32) + (mid >> 32);
}

void fp_mul3(fp *x, const fp *y, const fp *z) {
    if (fp_mul_counter) ++*fp_mul_counter;

    uint64_t t[LIMBS + 1] = {0};
    for (size_t k = 0; k < LIMBS; ++k) {
#define r(i) t[(k + (i)) % (LIMBS + 1)]

        uint64_t yz0, yz1;
        mul64(&yz1, &yz0, y->c[k], z->c[0]);
        uint64_t m = inv_min_p_mod_r * (yz0 + r(0));

        bool c = 0, o = 0;
        for (size_t i = 0; i < LIMBS; ++i) {
            uint64_t lo, hi;
            mul64(&hi, &lo, m, p.c[i]);
            o = __builtin_add_overflow(r(i), o, &r(i));
            o |= __builtin_add_overflow(r(i), lo, &r(i));
            c = __builtin_add_overflow(r(i+1), c, &r(i+1));
            c |= __builtin_add_overflow(r(i+1), hi, &r(i+1));
        }
        o = __builtin_add_overflow(r(LIMBS), o, &r(LIMBS));
        assert(!c && !o);

        c = o = 0;
        for (size_t i = 0; i < LIMBS; ++i) {
            uint64_t lo, hi;
            mul64(&hi, &lo, y->c[k], z->c[i]);
            o = __builtin_add_overflow(r(i), o, &r(i));
            o |= __builtin_add_overflow(r(i), lo, &r(i));
            c = __builtin_add_overflow(r(i+1), c, &r(i+1));
            c |= __builtin_add_overflow(r(i+1), hi, &r(i+1));
        }
        o = __builtin_add_overflow(r(LIMBS), o, &r(LIMBS));
        assert(!c && !o);
#undef r
    }
    for (size_t i = 0; i < LIMBS; ++i)
	    x->c[i] = t[(LIMBS + i) % (LIMBS + 1)];

    reduce_once(x);
}

void fp_mul2(fp *x, fp const *y)
{
    fp_mul3(x, x, y);
}

void fp_sq2(fp *x, fp const *y)
{
    if (fp_sq_counter) ++*fp_sq_counter;
    uint64_t *mulcnt = fp_mul_counter;
    fp_mul_counter = NULL;
    fp_mul3(x, y, y);
    fp_mul_counter = mulcnt;
}

void fp_sq1(fp *x)
{
    fp_sq2(x, x);
}

/* (obviously) not constant time in the exponent */
static void fp_pow(fp *x, uint const *e)
{
    fp y = *x;
    *x = fp_1;
    for (size_t k = 0; k < LIMBS; ++k) {
        uint64_t t = e->c[k];
        for (size_t i = 0; i < 64; ++i, t >>= 1) {
            if (t & 1)
                fp_mul2(x, &y);
            fp_sq1(&y);
        }
    }
}

void fp_inv(fp *x)
{
    if (fp_inv_counter) ++*fp_inv_counter;
    uint64_t *mulcnt = fp_mul_counter;
    fp_mul_counter = NULL;
    fp_pow(x, &p_minus_2);
    fp_mul_counter = mulcnt;
}

bool fp_issquare(fp *x)
{
    if (fp_sqt_counter) ++*fp_sqt_counter;
    uint64_t *mulcnt = fp_mul_counter;
    fp_mul_counter = NULL;
    fp_pow(x, &p_minus_1_halves);
    fp_mul_counter = mulcnt;
    return !memcmp(x, &fp_1, sizeof(fp));
}


void fp_random(fp *x)
{
    uint_random((uint *) x, &p);
}


