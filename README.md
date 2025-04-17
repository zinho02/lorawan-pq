Repository for the paper _Enhancing LoRaWAN Security: Addressing Static Root Keys with Post-Quantum Cryptography_  

# CSV

Each csv file corresponds to the measured data used in the paper.

## [CSIDH](csv/csidh.csv)
CSIDH time (ms) and energy (J) consumption.

## [Hash](csv/hash.csv)
Ascon-Hash256 hash function time (ms) and energy (J) consumption.

## [KeyID ToA](csv/keyid_toa.csv)
Time-on-Air (ms) of the 48 KeyID bits for each Data Rate (DR).

## [Public Key + Signature ToA](csv/pk_sig_toa.csv)
Time-on-Air (ms) of the Public Key with the Signature for each Data Rate (DR).

## [Public Key ToA](csv/pk_toa.csv)
Time-on-Air (ms) of the Public Key for each Data Rate (DR).

## [Post-quantum Key Generation Metrics](csv/pq_key_gen.csv)
Time (ms) and energy (J) consumption of the post-quantum signature algorithms Key Generation operation.

## [Post-quantum Signing Metrics](csv/pq_sig.csv)
Time (ms) and energy (J) consumption of the post-quantum signature algorithms Signing operation.

## [Post-quantum Verification Metrics](csv/pq_ver.csv)
Time (ms) and energy (J) consumption of the post-quantum signature algorithms Verification operation.

## [Signature + CSIDH Public Key ToA](csv/sig_csidh_toa.csv)
Time-on-Air (ms) of the Signature with the CSIDH Public Key for each Data Rate (DR).

## [Total Key Pair Update Procedure Time](csv/total_key_pair.csv)
Total time (ms) of the Key Pair Update Procedure for each Data Rate (DR).

## [Total Root Key Renewal Procedure Time](csv/total_root_keys.csv)
Total time (ms) of the Root Key Renewal Procedure for each Data Rate (DR).
