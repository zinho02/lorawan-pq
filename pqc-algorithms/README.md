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
```sh
cd hawk-submission-round2/NIST-SUBMISSION/Reference_Implementation/hawk512
make benchmark_sign
```

Test:
```sh
./benchmark_sign
```
