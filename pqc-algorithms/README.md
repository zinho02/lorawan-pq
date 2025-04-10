## SQISign

Build:
```sh
cd sqisign-submission-round2/Reference_Implementation
mkdir -p build
cd build
cmake -DSQISIGN_BUILD_TYPE=ref ..
make benchmark_sign
```

Test:
```sh
./benchmark_sign
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
cd snova-submission-round2/SNOVA_Round2/Reference_Implementation
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
cd uov-submission-round2/Reference_Implementation
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
