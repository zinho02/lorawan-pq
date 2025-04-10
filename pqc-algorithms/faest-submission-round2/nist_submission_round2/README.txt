.
├── Additional_Implementations
│   └── avx2
│       ├── faest_128f
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       ├── faest_128s
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       ├── faest_192f
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       ├── faest_192s
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       ├── faest_256f
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       ├── faest_256s
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       ├── faest_em_128f
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       ├── faest_em_128s
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       ├── faest_em_192f
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       ├── faest_em_192s
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       ├── faest_em_256f
│       │   ├── Makefile
│       │   ├── NIST-KATs
│       │   │   ├── PQCgenKAT_sign.c
│       │   │   ├── rng.c
│       │   │   └── rng.h
│       │   ├── aes.hpp
│       │   ├── aes_defs.hpp
│       │   ├── all.inc
│       │   ├── api.cpp
│       │   ├── api.h
│       │   ├── api.hpp
│       │   ├── avx2
│       │   │   ├── aes_impl.cpp
│       │   │   ├── aes_impl.hpp
│       │   │   ├── aes_impl.o
│       │   │   ├── block_impl.hpp
│       │   │   ├── constants_impl.hpp
│       │   │   ├── gfsmall_impl.hpp
│       │   │   ├── polynomials_impl.hpp
│       │   │   ├── transpose_impl.hpp
│       │   │   └── transpose_secpar_impl.hpp
│       │   ├── block.hpp
│       │   ├── constants.hpp
│       │   ├── debug.hpp
│       │   ├── faest.cpp
│       │   ├── faest.hpp
│       │   ├── faest.inc
│       │   ├── faest_keys.hpp
│       │   ├── faest_keys.inc
│       │   ├── gfsmall.hpp
│       │   ├── hash.hpp
│       │   ├── owf_proof.cpp
│       │   ├── owf_proof.hpp
│       │   ├── owf_proof.inc
│       │   ├── owf_proof_tools.hpp
│       │   ├── parameters.hpp
│       │   ├── poly2d.hpp
│       │   ├── polynomials.hpp
│       │   ├── polynomials_constants.cpp
│       │   ├── polynomials_constants.hpp
│       │   ├── prgs.hpp
│       │   ├── quicksilver.hpp
│       │   ├── randomness.h
│       │   ├── randomness_os.c
│       │   ├── randomness_randombytes.c
│       │   ├── sha3
│       │   │   ├── KeccakHash.c
│       │   │   ├── KeccakHash.h
│       │   │   ├── KeccakHashtimes4.c
│       │   │   ├── KeccakHashtimes4.h
│       │   │   ├── KeccakP-1600-64.macros
│       │   │   ├── KeccakP-1600-AVX2.s
│       │   │   ├── KeccakP-1600-SnP.h
│       │   │   ├── KeccakP-1600-times2-SIMD128.c
│       │   │   ├── KeccakP-1600-times2-SnP.h
│       │   │   ├── KeccakP-1600-times4-SIMD256.c
│       │   │   ├── KeccakP-1600-times4-SnP.h
│       │   │   ├── KeccakP-1600-times8-SnP.h
│       │   │   ├── KeccakP-1600-times8-on4.c
│       │   │   ├── KeccakP-1600-unrolling.macros
│       │   │   ├── KeccakSponge.c
│       │   │   ├── KeccakSponge.h
│       │   │   ├── KeccakSponge.inc
│       │   │   ├── KeccakSpongetimes4.c
│       │   │   ├── KeccakSpongetimes4.h
│       │   │   ├── KeccakSpongetimes4.inc
│       │   │   ├── PlSnP-Fallback.inc
│       │   │   ├── SIMD128-config.h
│       │   │   ├── SIMD256-config.h
│       │   │   ├── SnP-Relaned.h
│       │   │   ├── align.h
│       │   │   ├── brg_endian.h
│       │   │   └── config.h
│       │   ├── small_vole.cpp
│       │   ├── small_vole.hpp
│       │   ├── small_vole.inc
│       │   ├── tests
│       │   │   └── api_test.c
│       │   ├── transpose.hpp
│       │   ├── transpose_secpar.hpp
│       │   ├── universal_hash.hpp
│       │   ├── util.hpp
│       │   ├── vector_com.cpp
│       │   ├── vector_com.hpp
│       │   ├── vector_com.inc
│       │   ├── vole_check.hpp
│       │   ├── vole_commit.cpp
│       │   ├── vole_commit.hpp
│       │   ├── vole_commit.inc
│       │   └── vole_key_index_permutation.hpp
│       └── faest_em_256s
│           ├── Makefile
│           ├── NIST-KATs
│           │   ├── PQCgenKAT_sign.c
│           │   ├── rng.c
│           │   └── rng.h
│           ├── aes.hpp
│           ├── aes_defs.hpp
│           ├── all.inc
│           ├── api.cpp
│           ├── api.h
│           ├── api.hpp
│           ├── avx2
│           │   ├── aes_impl.cpp
│           │   ├── aes_impl.hpp
│           │   ├── aes_impl.o
│           │   ├── block_impl.hpp
│           │   ├── constants_impl.hpp
│           │   ├── gfsmall_impl.hpp
│           │   ├── polynomials_impl.hpp
│           │   ├── transpose_impl.hpp
│           │   └── transpose_secpar_impl.hpp
│           ├── block.hpp
│           ├── constants.hpp
│           ├── debug.hpp
│           ├── faest.cpp
│           ├── faest.hpp
│           ├── faest.inc
│           ├── faest_keys.hpp
│           ├── faest_keys.inc
│           ├── gfsmall.hpp
│           ├── hash.hpp
│           ├── owf_proof.cpp
│           ├── owf_proof.hpp
│           ├── owf_proof.inc
│           ├── owf_proof_tools.hpp
│           ├── parameters.hpp
│           ├── poly2d.hpp
│           ├── polynomials.hpp
│           ├── polynomials_constants.cpp
│           ├── polynomials_constants.hpp
│           ├── prgs.hpp
│           ├── quicksilver.hpp
│           ├── randomness.h
│           ├── randomness_os.c
│           ├── randomness_randombytes.c
│           ├── sha3
│           │   ├── KeccakHash.c
│           │   ├── KeccakHash.h
│           │   ├── KeccakHashtimes4.c
│           │   ├── KeccakHashtimes4.h
│           │   ├── KeccakP-1600-64.macros
│           │   ├── KeccakP-1600-AVX2.s
│           │   ├── KeccakP-1600-SnP.h
│           │   ├── KeccakP-1600-times2-SIMD128.c
│           │   ├── KeccakP-1600-times2-SnP.h
│           │   ├── KeccakP-1600-times4-SIMD256.c
│           │   ├── KeccakP-1600-times4-SnP.h
│           │   ├── KeccakP-1600-times8-SnP.h
│           │   ├── KeccakP-1600-times8-on4.c
│           │   ├── KeccakP-1600-unrolling.macros
│           │   ├── KeccakSponge.c
│           │   ├── KeccakSponge.h
│           │   ├── KeccakSponge.inc
│           │   ├── KeccakSpongetimes4.c
│           │   ├── KeccakSpongetimes4.h
│           │   ├── KeccakSpongetimes4.inc
│           │   ├── PlSnP-Fallback.inc
│           │   ├── SIMD128-config.h
│           │   ├── SIMD256-config.h
│           │   ├── SnP-Relaned.h
│           │   ├── align.h
│           │   ├── brg_endian.h
│           │   └── config.h
│           ├── small_vole.cpp
│           ├── small_vole.hpp
│           ├── small_vole.inc
│           ├── tests
│           │   └── api_test.c
│           ├── transpose.hpp
│           ├── transpose_secpar.hpp
│           ├── universal_hash.hpp
│           ├── util.hpp
│           ├── vector_com.cpp
│           ├── vector_com.hpp
│           ├── vector_com.inc
│           ├── vole_check.hpp
│           ├── vole_commit.cpp
│           ├── vole_commit.hpp
│           ├── vole_commit.inc
│           └── vole_key_index_permutation.hpp
├── IP_Statements
│   ├── ChristianRechberger-IP-Statement-2D1.pdf
│   ├── EmmanuelaOrsini-IP-Statement-2D1.pdf
│   ├── Michael-IP-Statement-2D1.pdf
│   ├── SebastianRamacher-2D1.pdf
│   ├── SebastianRamacher-2D3.pdf
│   ├── Shibam-IP-Statement-2D1.pdf
│   ├── Shibam-IP-Statement-2D3.pdf
│   ├── Ward_Beullens.pdf
│   ├── carstenbaum.pdf
│   ├── christianmajenz.pdf
│   ├── cypriendelpechdesaintguilhem.pdf
│   ├── lawrence roy imp signed.pdf
│   ├── lawrence roy signed.pdf
│   ├── lennartbraun.pdf
│   └── peterscholl.pdf
├── KAT
│   ├── faest_128f
│   │   ├── PQCsignKAT_32.req
│   │   └── PQCsignKAT_32.rsp
│   ├── faest_128s
│   │   ├── PQCsignKAT_32.req
│   │   └── PQCsignKAT_32.rsp
│   ├── faest_192f
│   │   ├── PQCsignKAT_40.req
│   │   └── PQCsignKAT_40.rsp
│   ├── faest_192s
│   │   ├── PQCsignKAT_40.req
│   │   └── PQCsignKAT_40.rsp
│   ├── faest_256f
│   │   ├── PQCsignKAT_48.req
│   │   └── PQCsignKAT_48.rsp
│   ├── faest_256s
│   │   ├── PQCsignKAT_48.req
│   │   └── PQCsignKAT_48.rsp
│   ├── faest_em_128f
│   │   ├── PQCsignKAT_32.req
│   │   └── PQCsignKAT_32.rsp
│   ├── faest_em_128s
│   │   ├── PQCsignKAT_32.req
│   │   └── PQCsignKAT_32.rsp
│   ├── faest_em_192f
│   │   ├── PQCsignKAT_48.req
│   │   └── PQCsignKAT_48.rsp
│   ├── faest_em_192s
│   │   ├── PQCsignKAT_48.req
│   │   └── PQCsignKAT_48.rsp
│   ├── faest_em_256f
│   │   ├── PQCsignKAT_64.req
│   │   └── PQCsignKAT_64.rsp
│   └── faest_em_256s
│       ├── PQCsignKAT_64.req
│       └── PQCsignKAT_64.rsp
├── Optimized_Implementation
│   └── README
├── README.txt
├── Reference_Implementation
│   ├── faest_128f
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_128f.c
│   │   ├── faest_128f.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   ├── faest_128s
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_128s.c
│   │   ├── faest_128s.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   ├── faest_192f
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_192f.c
│   │   ├── faest_192f.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   ├── faest_192s
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_192s.c
│   │   ├── faest_192s.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   ├── faest_256f
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_256f.c
│   │   ├── faest_256f.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   ├── faest_256s
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_256s.c
│   │   ├── faest_256s.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   ├── faest_em_128f
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── faest_em_128f.c
│   │   ├── faest_em_128f.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   ├── faest_em_128s
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── faest_em_128s.c
│   │   ├── faest_em_128s.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   ├── faest_em_192f
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── faest_em_192f.c
│   │   ├── faest_em_192f.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   ├── faest_em_192s
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── faest_em_192s.c
│   │   ├── faest_em_192s.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   ├── faest_em_256f
│   │   ├── Makefile
│   │   ├── NIST-KATs
│   │   │   ├── PQCgenKAT_sign.c
│   │   │   ├── rng.c
│   │   │   └── rng.h
│   │   ├── aes.c
│   │   ├── aes.h
│   │   ├── api.h
│   │   ├── bavc.c
│   │   ├── bavc.h
│   │   ├── compat.c
│   │   ├── compat.h
│   │   ├── crypto_sign.c
│   │   ├── crypto_sign.h
│   │   ├── endian_compat.h
│   │   ├── faest.c
│   │   ├── faest.h
│   │   ├── faest_aes.c
│   │   ├── faest_aes.h
│   │   ├── faest_defines.h
│   │   ├── faest_em_256f.c
│   │   ├── faest_em_256f.h
│   │   ├── fields.c
│   │   ├── fields.h
│   │   ├── hash_shake.h
│   │   ├── instances.c
│   │   ├── instances.h
│   │   ├── macros.h
│   │   ├── owf.c
│   │   ├── owf.h
│   │   ├── parameters.h
│   │   ├── random_oracle.c
│   │   ├── random_oracle.h
│   │   ├── randomness.c
│   │   ├── randomness.h
│   │   ├── sha3
│   │   │   ├── KeccakHash.c
│   │   │   ├── KeccakHash.h
│   │   │   ├── KeccakHashtimes4.c
│   │   │   ├── KeccakHashtimes4.h
│   │   │   ├── KeccakP-1600-64.macros
│   │   │   ├── KeccakP-1600-SnP.h
│   │   │   ├── KeccakP-1600-opt64-config.h
│   │   │   ├── KeccakP-1600-opt64.c
│   │   │   ├── KeccakP-1600-times4-SnP.h
│   │   │   ├── KeccakP-1600-times4-on1.c
│   │   │   ├── KeccakP-1600-unrolling.macros
│   │   │   ├── KeccakSponge.c
│   │   │   ├── KeccakSponge.h
│   │   │   ├── KeccakSponge.inc
│   │   │   ├── KeccakSpongetimes4.c
│   │   │   ├── KeccakSpongetimes4.h
│   │   │   ├── KeccakSpongetimes4.inc
│   │   │   ├── PlSnP-Fallback.inc
│   │   │   ├── SnP-Relaned.h
│   │   │   ├── align.h
│   │   │   ├── brg_endian.h
│   │   │   ├── config.h
│   │   │   └── s390_cpacf.h
│   │   ├── tests
│   │   │   └── api_test.c
│   │   ├── universal_hashing.c
│   │   ├── universal_hashing.h
│   │   ├── utils.c
│   │   ├── utils.h
│   │   ├── vole.c
│   │   └── vole.h
│   └── faest_em_256s
│       ├── Makefile
│       ├── NIST-KATs
│       │   ├── PQCgenKAT_sign.c
│       │   ├── rng.c
│       │   └── rng.h
│       ├── aes.c
│       ├── aes.h
│       ├── api.h
│       ├── bavc.c
│       ├── bavc.h
│       ├── compat.c
│       ├── compat.h
│       ├── crypto_sign.c
│       ├── crypto_sign.h
│       ├── endian_compat.h
│       ├── faest.c
│       ├── faest.h
│       ├── faest_aes.c
│       ├── faest_aes.h
│       ├── faest_defines.h
│       ├── faest_em_256s.c
│       ├── faest_em_256s.h
│       ├── fields.c
│       ├── fields.h
│       ├── hash_shake.h
│       ├── instances.c
│       ├── instances.h
│       ├── macros.h
│       ├── owf.c
│       ├── owf.h
│       ├── parameters.h
│       ├── random_oracle.c
│       ├── random_oracle.h
│       ├── randomness.c
│       ├── randomness.h
│       ├── sha3
│       │   ├── KeccakHash.c
│       │   ├── KeccakHash.h
│       │   ├── KeccakHashtimes4.c
│       │   ├── KeccakHashtimes4.h
│       │   ├── KeccakP-1600-64.macros
│       │   ├── KeccakP-1600-SnP.h
│       │   ├── KeccakP-1600-opt64-config.h
│       │   ├── KeccakP-1600-opt64.c
│       │   ├── KeccakP-1600-times4-SnP.h
│       │   ├── KeccakP-1600-times4-on1.c
│       │   ├── KeccakP-1600-unrolling.macros
│       │   ├── KeccakSponge.c
│       │   ├── KeccakSponge.h
│       │   ├── KeccakSponge.inc
│       │   ├── KeccakSpongetimes4.c
│       │   ├── KeccakSpongetimes4.h
│       │   ├── KeccakSpongetimes4.inc
│       │   ├── PlSnP-Fallback.inc
│       │   ├── SnP-Relaned.h
│       │   ├── align.h
│       │   ├── brg_endian.h
│       │   ├── config.h
│       │   └── s390_cpacf.h
│       ├── tests
│       │   └── api_test.c
│       ├── universal_hashing.c
│       ├── universal_hashing.h
│       ├── utils.c
│       ├── utils.h
│       ├── vole.c
│       └── vole.h
├── Supporting_Documentation
│   └── FAESTv2.pdf
└── cover_sheet.pdf

128 directories, 1843 files
