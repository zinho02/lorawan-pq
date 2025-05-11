# Benchmark Signature Algorithms
The [benchmark_sign.c](benchmark_sign.c) file was used to benchmark the results.

## SQISign

Build:
```sh
cd sqisign-submission-round2/Reference_Implementation
mkdir -p build
cd build
cmake -DSQISIGN_BUILD_TYPE=ref ..
make benchmark_sign_lvl1
```

Test:
```sh
cd apps
./benchmark_sign_lvl1
```

## MAYO

Build:
```sh
cd mayo-submission-round2/Reference_Implementation
mkdir -p build
cd build
cmake -DMAYO_BUILD_TYPE=ref -DENABLE_AESNI=OFF ..
make benchmark_sign_mayo_1
```

Test:
```sh
cd apps
./benchmark_sign_mayo_1
```

## HAWK
Build:
```sh
cd hawk-submission-round2/NIST-SUBMISSION/Reference_Implementation/hawk512
make benchmark_sign
```

Test:
```sh
./benchmark_sign
```

## SNOVA
Build:
```sh
cd snova-submission-round2/SNOVA_Round2/Reference_Implementation/src
make benchmark_sign
```

Test:
```sh
./benchmark_sign.a
```

## PERK
Build:
```
cd perk-submission-round2/perk/Reference_Implementation/perk-128-fast-3
make benchmark_sign
```

Test:
```sh
cd build/bin
./benchmark_sign
```

## LESS
Build:
```
cd less-submission-round2/Submission_LESS_Round2/Utilities/Benchmarking
mkdir build
cd build
cmake -DUSE_REFERENCE=1 ..
make benchmark_sign252_68
```

Test:
```sh
./benchmark_sign252_68
```

## UOV
Build:
```
cd uov-submission-round2/UOV/Reference_Implementation
make benchmark_sign
```

Test:
```sh
./benchmark_sign
```

## ML-DSA
Build:
```
cd dilithium-round3/Dilithium/dilithium/Reference_Implementation/crypto_sign/dilithium2
make benchmark_sign
```

Test:
```sh
./benchmark_sign
```

## Falcon
Build:
```
cd falcon-round3/falcon-round3/Reference_Implementation/falcon512/falcon512int
mkdir build
make build/benchmark_sign
```

Test:
```sh
cd build
./benchmark_sign
```

## SLH-DSA
Build:
```
cd SPHINCS-round3/NIST-PQ-Submission-SPHINCS-20201001/Reference_Implementation/crypto_sign/sphincs-haraka-128f-simple
make benchmark_sign
```

Test:
```sh
cd build
./benchmark_sign
```

## FAEST
Build:
```
cd faest-submission-round2/nist_submission_round2/Reference_Implementation/crypto_sign/faest_128f
make benchmark_sign
```

Test:
```sh
./benchmark_sign
```

## MiRitH
Build:
```
cd mirith-submission/mirith_nist_submission-main/Reference_Implementation/mirith_Ia_fast/test
make benchmark_sign
```

Test:
```sh
./benchmark_sign
```

## MIRA
Build:
```
cd MIRA-submission/MIRA/Reference_Implementation/MIRA-128F
make benchmark_sign
```

Test:
```sh
cd bin
./benchmark_sign
```

## QR-UOV
Build:
```
cd qr-uov-submission-round2/QR_UOV - Round2/Reference_Implementation
make qruov1q127L3v156m54
cd qruov1q127L3v156m54/refa
```

Test:
```sh
./benchmark_sign
```

## CROSS
Build:
```
cd cross-submission-round2/Additional_Implementations/Benchmarking
mkdir build
cd build
cmake -DREFERENCE=1 ..
make benchmark_sign_1_RSDPG_SPEED
```

Test:
```sh
cd bin
./benchmark_sign_1_RSDPG_SPEED
```

## SDitH
Build:
```
cd sdith-submission/sdith/Reference_Implementation/Threshold_Variant/sdith_threshold_cat1_p251
make benchmark_sign 
```

Test:
```sh
./benchmark_sign
```

## MQOM
Build:
```
cd mqom-submission-round2/submission_package_v2/Reference_Implementation/mqom2_cat1_gf256_fast_r3
make benchmark_sign
```

Test:
```sh
./benchmark_sign
```

# Benchmark CSIDH
The [csidh-20210627/csidh_benchmark.c](csidh-20210627/csidh_benchmark.c) file was used to benchmark the results.

Build:
```
cd csidh-20210627
make csidh_benchmark BITS=512 FP_IMPL=fp.c UINT_IMPL=uint.c
```

Test:
```
./csidh_benchmark
```
