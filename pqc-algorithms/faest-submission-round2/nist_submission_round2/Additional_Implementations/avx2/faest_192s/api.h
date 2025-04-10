#ifndef FAEST_API_H
#define FAEST_API_H

#ifdef __cplusplus
extern "C" {
#endif

#define CRYPTO_SECRETKEYBYTES 40
#define CRYPTO_PUBLICKEYBYTES 48
#define CRYPTO_BYTES 11260

#define CRYPTO_ALGNAME "faest_192s"

int crypto_sign_keypair(unsigned char* pk, unsigned char* sk);
int crypto_sign(
	unsigned char *sm, unsigned long long *smlen,
	const unsigned char *m, unsigned long long mlen,
	const unsigned char *sk);
int crypto_sign_open(
	unsigned char *m, unsigned long long *mlen,
	const unsigned char *sm, unsigned long long smlen,
	const unsigned char *pk);

#ifdef __cplusplus
}
#endif

#endif
