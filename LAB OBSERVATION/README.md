# LAB OBSERVATION: Cryptography & Network Security

**Course:** Cryptography and Network Security  
**Course Code:** CSA51 / CSA5116  
**Department:** B.Tech Information Technology  
**Student:** M.S. Livesh Vetrivel | Reg No: 192521023  
**Institution:** Saveetha School of Engineering, SIMATS  

Complete C implementations of all 40 laboratory exercises:

| No. | File | Algorithm / Exercise |
|---|---|---|
| 1 | [`prog01_caesar.c`](prog01_caesar.c) | Caesar cipher with variable shift key $k \in [1, 25]$ |
| 2 | [`prog02_monoalphabetic.c`](prog02_monoalphabetic.c) | Monoalphabetic substitution cipher with unique key permutation |
| 3 | [`prog03_playfair.c`](prog03_playfair.c) | Playfair cipher 5x5 digraph substitution algorithm |
| 4 | [`prog04_polyalphabetic.c`](prog04_polyalphabetic.c) | Polyalphabetic (Vigenère) cipher with repeating keyword |
| 5 | [`prog05_affine.c`](prog05_affine.c) | Affine Caesar cipher validity analysis and implementation |
| 6 | [`prog06_affine_break.c`](prog06_affine_break.c) | Affine cipher cryptanalysis using high-frequency letters (B, U) |
| 7 | [`prog07_gold_bug.c`](prog07_gold_bug.c) | Edgar Allan Poe "The Gold-Bug" substitution cipher decryption |
| 8 | [`prog08_keyword_mono.c`](prog08_keyword_mono.c) | Keyword monoalphabetic substitution (Keyword: CIPHER) |
| 9 | [`prog09_pt109_playfair.c`](prog09_pt109_playfair.c) | PT-109 Australian wireless station Playfair decryption |
| 10 | [`prog10_playfair_cadogan.c`](prog10_playfair_cadogan.c) | Playfair encryption with specific 5x5 key matrix |
| 11 | [`prog11_playfair_keyspace.c`](prog11_playfair_keyspace.c) | Theoretical vs effectively unique Playfair key space ($25!$ vs $24!$) |
| 12 | [`prog12_hill_cipher.c`](prog12_hill_cipher.c) | Hill cipher $2 \times 2$ encryption, matrix inverse, and decryption |
| 13 | [`prog13_hill_known_pt.c`](prog13_hill_known_pt.c) | Known plaintext attack on $2 \times 2$ Hill cipher |
| 14 | [`prog14_vigenere_otp.c`](prog14_vigenere_otp.c) | One-time pad (Vigenère stream) encryption and key deduction |
| 15 | [`prog15_additive_freq_attack.c`](prog15_additive_freq_attack.c) | Unigram frequency analysis on additive cipher (Top 10 candidates) |
| 16 | [`prog16_mono_freq_attack.c`](prog16_mono_freq_attack.c) | Frequency analysis on monoalphabetic substitution cipher |
| 17 | [`prog17_des_key_schedule.c`](prog17_des_key_schedule.c) | DES decryption key schedule and reverse round subkey order |
| 18 | [`prog18_des_disjoint_halves.c`](prog18_des_disjoint_halves.c) | DES subkey 24-bit disjoint half derivation (PC-1 & PC-2) |
| 19 | [`prog19_cbc_3des.c`](prog19_cbc_3des.c) | 3DES in CBC mode; security and performance comparison |
| 20 | [`prog20_error_propagation.c`](prog20_error_propagation.c) | Bit error propagation analysis in ECB vs CBC modes |
| 21 | [`prog21_block_padding.c`](prog21_block_padding.c) | Block cipher bit padding (1 followed by 0s) and motivation |
| 22 | [`prog22_sdes_cbc.c`](prog22_sdes_cbc.c) | Simplified DES (S-DES) encryption and decryption in CBC mode |
| 23 | [`prog23_sdes_ctr.c`](prog23_sdes_ctr.c) | Simplified DES (S-DES) in Counter (CTR) mode |
| 24 | [`prog24_rsa_priv_key.c`](prog24_rsa_priv_key.c) | RSA private key derivation ($e = 31, n = 3599$) |
| 25 | [`prog25_rsa_common_factor.c`](prog25_rsa_common_factor.c) | RSA vulnerability when plaintext shares a common factor with $n$ |
| 26 | [`prog26_rsa_compromised_key.c`](prog26_rsa_compromised_key.c) | Insecurity of reusing RSA modulus $n$ after private key compromise |
| 27 | [`prog27_rsa_char_dictionary.c`](prog27_rsa_char_dictionary.c) | RSA codebook dictionary vulnerability for single-character encryption |
| 28 | [`prog28_diffie_hellman.c`](prog28_diffie_hellman.c) | Diffie-Hellman discrete root variant vulnerability analysis |
| 29 | [`prog29_sha3_sponge.c`](prog29_sha3_sponge.c) | SHA-3 Keccak capacity lane diffusion analysis |
| 30 | [`prog30_cbc_mac_extension.c`](prog30_cbc_mac_extension.c) | CBC MAC two-block extension forgery demonstration |
| 31 | [`prog31_cmac_subkeys.c`](prog31_cmac_subkeys.c) | CMAC subkey derivation ($K_1, K_2$) in GF($2^b$) with $R_b$ constants |
| 32 | [`prog32_dsa_signature_nonce.c`](prog32_dsa_signature_nonce.c) | DSA per-message random nonce $k$ vs deterministic RSA signatures |
| 33 | [`prog33_des_full.c`](prog33_des_full.c) | Complete 64-bit block Data Encryption Standard (DES) algorithm |
| 34 | [`prog34_padding_motivation.c`](prog34_padding_motivation.c) | Analysis: Why full padding block is mandatory for exact block multiples |
| 35 | [`prog35_otp_vigenere.c`](prog35_otp_vigenere.c) | Vigenère stream cipher one-time pad verification |
| 36 | [`prog36_affine_validity.c`](prog36_affine_validity.c) | Affine Caesar cipher parameter constraints |
| 37 | [`prog37_mono_freq.c`](prog37_mono_freq.c) | Automated monoalphabetic substitution frequency cryptanalysis |
| 38 | [`prog38_hill_kpa.c`](prog38_hill_kpa.c) | Known plaintext matrix recovery for Hill cipher |
| 39 | [`prog39_additive_top10.c`](prog39_additive_top10.c) | Top 10 plaintext candidates ranking for additive ciphers |
| 40 | [`prog40_mono_top10.c`](prog40_mono_top10.c) | Monoalphabetic substitution frequency ranking |

---

## Compilation

```bash
make
```
Or for an individual file:
```bash
gcc -Wall -O2 prog01_caesar.c -o prog01_caesar
./prog01_caesar
```
