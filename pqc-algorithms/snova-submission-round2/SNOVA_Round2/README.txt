# SNOVA

This folder contains the digital content of the proposal


Submitted to the NISTPQC: Call for Additional Digital Signature Schemes for the Post-Quantum Cryptography Standardization Process

by 

Lih-Chung Wang,
Chun-Yen Chou,
Jintai Ding,
Yen-Liang Kuan,
Jan Adriaan Leegwater,
Ming-Siou Li,
Bo-Shu Tseng,
Po-En Tseng,
Chia-Chun Wang.

## This folder contains the subfolders
1. Statements
2. Supporting_Documentation
4. KAT
5. Reference_Implementation
6. Optimized_Implementation
7. Alternative_Implementation

## Statement"
This folder contains the files "Statement by Each Submitter.pdf" and "Statement by Reference and Optimized Implementations’Owner(s).pdf" containg the intellectual property statements of each submitters (aim at the requirement in Sec. 2.D).

## Supporting Documentation
This folder contains the file SNOVA_Round2.pdf,
containing the algorithm specification, performance analysis and performance data, parameter settings, security analysis and advantages and limitations (aim at Sec.2.B.1, 2.B.2, 2.B.4, Sec.2.B.5, Sec.2.B.6 of the requirement, respectively) of our SNOVA scheme.

## KAT
This folder contains the Known Answer Test values of our implementation.
More information on the content of this folder as well as an explanation how to generate the KATs

## Reference_Implementation
This folder contains the c-code of our Reference implementation of SNOVA.
More information on the content of this folder as well as an explanation how to use the code can be found in `Reference_Implementation/readme.md`

## Optimized_Implementation
This folder contains the c-code of our implementations of SNOVA optimized for
amd64 architecture. More information on the content of the folder
and how to use the code can be found in `Optimized_Implementation/readme.md`

## Alternative_Implementation
This folder contains the c-code of our implementations of SNOVA optimized for
avx2 architecture. More information on the content of the folder
and how to use the code can be found in `Alternative_Implementation/avx2/readme.md`

## About the difference between Reference_Implementation, Optimized_Implementation and Alternative_Implementation
The first line of the makefile used to generate known-answer tests is the only difference between the implementation folders.
Example: 
    Optimized_Implementation/makefile line:1 platform := ref
    Reference_Implementation/makefile line:1 platform := opt
    Alternative_Implementation/avx2/makefile line:1 platform := avx2



