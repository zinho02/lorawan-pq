#include <string.h>
#include <stddef.h>
#include <assert.h>

#include "params.h"
#include "uint.h"
#include "rng.h"

/* assumes little-endian throughout. */

uint const uint_0 = {{0}};
uint const uint_1 = {{1}};

bool uint_eq(uint const *x, uint const *y)
{
    return memcmp(x->c, y->c, sizeof(uint64_t) * LIMBS) == 0;
}

void uint_set(uint *x, uint64_t y)
{
    memset(x->c, 0, sizeof(uint64_t) * LIMBS);
    x->c[0] = y;
}

size_t uint_len(uint const *x)
{
    for (size_t i = LIMBS - 1, j; i < LIMBS; --i) {
        uint64_t v = x->c[i];
        if (!v) continue;
        for (j = 0; v; ++j, v >>= 1);
        return 64*i+j;
    }
    return 0;
}

bool uint_bit(uint const *x,  uint64_t k)
{
    return 1 & (x->c[k / 64] >> k % 64);
}

bool uint_add3(uint *x, uint const *y, uint const *z)
{
    bool c = 0;
    for (size_t i = 0; i < LIMBS; ++i) {
        uint64_t t;
        c = __builtin_add_overflow(y->c[i], c, &t);
        c |= __builtin_add_overflow(t, z->c[i], &x->c[i]);
    }
    return c;
}

bool uint_sub3(uint *x, uint const *y, uint const *z)
{
    bool b = 0;
    for (size_t i = 0; i < LIMBS; ++i) {
        uint64_t t;
        b = __builtin_sub_overflow(y->c[i], b, &t);
        b |= __builtin_sub_overflow(t, z->c[i], &x->c[i]);
    }
    return b;
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

void uint_mul3_64(uint *x, const uint *y, uint64_t z) {
    uint64_t c = 0;

    for (size_t i = 0; i < LIMBS; ++i) {
        uint64_t hi, lo;
        mul64(&hi, &lo, y->c[i], z);

        uint64_t sum = lo + c;
        x->c[i] = sum;
        c = hi + (sum < lo);
    }
}

void uint_random(uint *x, uint const *m)
{
    if (!m) {
        randombytes(x, sizeof(*x));
        return;
    }

    assert(memcmp(m, &uint_0, sizeof(*m)));

    const size_t bits = uint_len(m);
    const uint64_t mask = ((uint64_t) 1 << bits % 64) - 1;

    while (true) {

        *x = uint_0;
        randombytes(x, (bits+7)/8);

        if (bits < 64*LIMBS)
            x->c[bits/64] &= mask;

        for (size_t i = LIMBS-1; i < LIMBS; --i) {
            if (x->c[i] < m->c[i])
                return;
            else if (x->c[i] > m->c[i])
                break;
        }
    }
}

