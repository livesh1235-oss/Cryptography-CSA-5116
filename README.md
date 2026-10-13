# Cryptography and Network Security (CSA51 / CSA5116)

**Saveetha School of Engineering | Saveetha Institute of Medical and Technical Sciences (SIMATS)**  
Department of Information Technology  
**Student:** M.S. Livesh Vetrivel | Reg No: 192521023  

---

## 📂 Repository Structure

```
├── CO1_AT1/                  # Assessment Tool 1: Application-Based Questions (Weightage: 40%)
│   ├── q1_caesar_event.c
│   ├── q2_atbash_deduction.c
│   ├── q3_vigenere_hello.c
│   ├── q5_railfence_discover.c
│   ├── Makefile
│   └── README.md
│
├── CO1_AT2/                  # Assessment Tool 2: Concept Mapping (Weightage: 20%)
│   ├── number_theory_demo.c
│   ├── Makefile
│   └── README.md
│
├── CO1_AT3/                  # Assessment Tool 3: Technical Presentation
│   ├── presentation_photo.jpg
│   └── README.md
│
├── LAB OBSERVATION/          # Complete implementations of all 40 laboratory exercises
│   ├── prog01_caesar.c
│   ├── prog02_monoalphabetic.c
│   ├── ...
│   ├── prog40_mono_top10.c
│   ├── Makefile
│   └── README.md
│
├── Makefile                  # Root Makefile
├── README.md
└── .gitignore
```

---

## 📚 Curriculum Breakdown

### 1. [CO1_AT1 (Assessment Tool 1)](CO1_AT1/)
- **Weightage:** 40% | **Marks:** 50
- Comprehensive step-by-step solutions and verified C implementations for all 5 application-based scenarios:
  1. *Event Communication Security* (Caesar Cipher $k=4$, `MEET AT NOON` $\rightarrow$ `QIIX EX RSSR`)
  2. *Intercepted Suspicious Message* (Atbash Cryptanalysis, `GSRH RH Z HVXIVG` $\rightarrow$ `THIS IS A SECRET`)
  3. *Secure Messaging System* (Vigenère Cipher, `HELLO` + `KEY` $\rightarrow$ `RIJVS`)
  4. *Suspicious Digital Asset Investigation* (LSB Steganalysis, Chi-Square, AES-256 pre-encryption)
  5. *Legacy Corporate Communication* (Rail Fence Depth 3, `WECRLTEERDSOEEFEAOCAIVDEN` $\rightarrow$ `WE ARE DISCOVERED FLEE AT ONCE`)
- Concept Map 1: Classical Substitution Techniques comparison
- Concept Map 2: Number Theory linkages in RSA public-key cryptography

### 2. [CO1_AT2 (Assessment Tool 2)](CO1_AT2/)
- **Weightage:** 20% | **Marks:** 50
- Deep conceptual mapping and formal analyses across 5 key areas:
  1. *Attacks, Threats, Risks & CIA Goals* (with real-world case studies: Equifax, SolarWinds, Mirai, Colonial Pipeline)
  2. *Substitution Techniques Comparison* (Caesar vs. Monoalphabetic vs. Vigenère vs. Hill Cipher)
  3. *Classical Encryption Schemes* (Substitution vs. Transposition, Product Ciphers)
  4. *Steganography Architecture* (Data Hiding, Robust/Fragile Watermarking, Survivability Triangle)
  5. *Number Theory Foundations* (Modular Inverse, Extended Euclid, Fermat's Little Theorem, Euler's Totient $\phi(n)$, Euler's Theorem in RSA) + C demonstration

### 3. [CO1_AT3 (Assessment Tool 3)](CO1_AT3/)
- **Technical Presentation:** *Security Attacks, Threats, Risks and Their Impact on Security Goals*
- Presentation evidence photograph
- Detailed coverage of CIA Triad (+2), Passive vs Active Attacks, Risk Analysis Matrix, Real-World Incidents (WannaCry, Mirai, Target), Analysis Tools, and Countermeasures.

### 4. [LAB OBSERVATION](LAB%20OBSERVATION/)
- All 40 classical and modern cryptography laboratory programs in standard C with dedicated compilation makefile.

---

## 🛠️ Build & Verification

To compile all modules simultaneously:
```bash
make
```
To clean all binaries:
```bash
make clean
```
