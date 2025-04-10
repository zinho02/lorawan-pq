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
make all

```

Test:
```sh
./benchmark_sign
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
cd less-submission-round2/perk/Utilities/Benchmarking
mkdir build
cd build
cmake -DUSE_REFERENCE=1 ..
make benchmark_sign252_68
```

Test:
```sh
./benchmark_sign252_68
```
