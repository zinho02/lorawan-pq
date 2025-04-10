#include "api.hpp"

using faest_params = faest::v2::faest_em_128_s;
using faest_scheme = faest::faest_scheme<faest_params>;

static_assert(faest_scheme::CRYPTO_SECRETKEYBYTES == 32);
static_assert(faest_scheme::CRYPTO_PUBLICKEYBYTES == 32);
static_assert(faest_scheme::CRYPTO_BYTES == 3906);

extern "C" int crypto_sign_keypair(
    unsigned char* pk, unsigned char* sk)
{
    return faest::faest_scheme<faest_params>::crypto_sign_keypair(pk, sk);
}

extern "C" int crypto_sign(
	unsigned char *sm, unsigned long long *smlen,
	const unsigned char *m, unsigned long long mlen,
	const unsigned char *sk)
{
    return faest::faest_scheme<faest_params>::crypto_sign(sm, smlen, m, mlen, sk);
}

extern "C" int crypto_sign_open(
	unsigned char *m, unsigned long long *mlen,
	const unsigned char *sm, unsigned long long smlen,
	const unsigned char *pk)
{
    return faest::faest_scheme<faest_params>::crypto_sign_open(m, mlen, sm, smlen, pk);
}
