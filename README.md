Repository for the paper _Enhancing LoRaWAN Security: Addressing Static Root Keys with Post-Quantum Cryptography_  

Each csv file corresponds to the measured data used in the paper.

# [csidh.csv](csidh.csv)
CSIDH time (ms) and energy (J) consumption.

# [hash.csv](hash.csv)
Ascon hash function time (ms) and energy (J) consumption.

# [keyid_toa.csv](keyid_toa.csv)
Time-on-Air (ms) of the 48 KeyID bits for each Data Rate (DR).

# [pk_sig_toa.csv](pk_sig_toa.csv)
Time-on-Air (ms) of the Public Key plus Signature for each Data Rate (DR).

# [pk_toa.csv](pk_toa.csv)
Time-on-Air (ms) of the Public Key for each Data Rate (DR).

# [pki_ack_toa.csv](pki_ack_toa.csv)
Time-on-Air (ms) of the 1 byte confimation message from the PKI server for each Data Rate (DR).

# [pq_key_gen.csv](pq_key_gen.csv)
Time (ms) and energy (J) consumption of the post-quantum signature algorithms Key Generation operation.

# [pq_sig.csv](pq_sig.csv)
Time (ms) and energy (J) consumption of the post-quantum signature algorithms Signing operation.

# [pq_ver.csv](pq_ver.csv)
Time (ms) and energy (J) consumption of the post-quantum signature algorithms Verification operation.

# [sig_csidh_toa.csv](sig_csidh_toa.csv)
Time-on-Air (ms) of the Signature plus the CSIDH Public Key for each Data Rate (DR).

# [total_key_pair.csv](total_key_pair.csv)
Total time (ms) of the Update Key Pair Procedure for each Data Rate (DR).

# [total_root_keys.csv](total_root_keys.csv)
Total time (ms) of the Update Root Keys Procedure for each Data Rate (DR).
