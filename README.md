# Cryptography and Network Security (CSA51 / CSA5116)

**Saveetha School of Engineering | Saveetha Institute of Medical and Technical Sciences (SIMATS)**  
Department of Information Technology  
**Student:** M.S. Livesh Vetrivel | Reg No: 192521023  

---

## 📂 Repository Structure

```
├── LAB OBSERVATION/          # Complete implementations of all 40 laboratory exercises
│   ├── prog01_caesar.c
│   ├── prog02_monoalphabetic.c
│   ├── ...
│   ├── prog40_mono_top10.c
│   ├── Makefile
│   └── README.md
│
├── CO1_AT3/                  # Course Outcome 1 Assessment Task 3: Technical Presentation
│   ├── presentation_photo.jpg
│   └── README.md
│
├── Makefile                  # Root Makefile
└── README.md
```

---

## 🚀 Modules

### 1. [LAB OBSERVATION](LAB%20OBSERVATION/)
Contains all 40 C programs covering:
- **Classical Ciphers:** Caesar, Monoalphabetic, Playfair, Vigenère, Hill Cipher, Affine Cipher, One-Time Pad
- **Cryptanalysis:** Frequency analysis, known-plaintext attacks, linear modular solving
- **Modern Block Ciphers:** DES, S-DES, 3DES in ECB, CBC, and CTR modes, block padding
- **Asymmetric Cryptography:** RSA key generation, factorization attacks, dictionary attacks, Diffie-Hellman
- **Hash Functions & MACs:** SHA-3 (Keccak) sponge capacity, CBC-MAC forgery, CMAC subkey derivation
- **Digital Signatures:** DSA per-message nonce vulnerability vs RSA deterministic signatures

### 2. [CO1_AT3 (Technical Presentation)](CO1_AT3/)
- **Topic:** *Security Attacks, Threats, Risks and Their Impact on Security Goals*
- Presentation evidence photograph
- Detailed coverage of CIA Triad, Passive vs Active Attacks, Risk Analysis, Real-World Incidents (WannaCry, Mirai, Target), Threat Analysis Tools, and Defense-in-Depth Countermeasures.

---

## 🛠️ Build & Run

To compile all 40 programs from the repository root:
```bash
make
```
To clean binaries:
```bash
make clean
```
