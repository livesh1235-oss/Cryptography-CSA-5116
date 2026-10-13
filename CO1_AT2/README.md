# SIMATS ENGINEERING
## ASSESSMENT TOOL 2 (CO1_AT2)

**Course Name:** Cryptography and Network Security  
**Course Code:** CSA5116  
**Course Outcome Covered:** CO1: Apply classical encryption techniques using symmetric and asymmetric ciphers to encrypt and decrypt data for ensuring data security (BL3, BL4)  
**Assessment Tool Weightage:** 20%  
**Total Marks:** 50  

**Student Name:** M.S. Livesh Vetrivel  
**Register No:** 192521023  
**Department:** Department of B.Tech Information Technology  
**Institution:** Saveetha School of Engineering, SIMATS  

---

## Annexure A: Concept Mapping Tasks & Comprehensive Analyses

---

### Task 1: Security Attacks, Threats, Risks & Security Goals

#### Concept Map:

```
                           ┌─────────────────────────┐
                           │    CYBERSECURITY CORE   │
                           └────────────┬────────────┘
                                        │
           ┌────────────────────────────┴────────────────────────────┐
           ▼                                                         ▼
┌──────────────────────────────────────┐  exploit   ┌──────────────────────────────────────┐
│           SECURITY ATTACKS           ├───────────►│            SECURITY THREATS          │
│                                      │            │                                      │
│ • Passive: Eavesdropping, Sniffing,  │            │ • Unauthorized eavesdropping         │
│   Traffic Analysis                   │            │ • Identity impersonation / Spoofing  │
│ • Active: Masquerade, Replay,        │            │ • Data tampering / Corruption        │
│   Message Modification, DoS          │            │ • Service outage / Ransomware        │
└──────────────────┬───────────────────┘            └──────────────────┬───────────────────┘
                   │                                                   │
                   │ generates                                         │ leads to
                   ▼                                                   ▼
┌──────────────────────────────────────┐            ┌──────────────────────────────────────┐
│            SECURITY RISKS            │            │            SECURITY GOALS            │
│  (Risk = Likelihood × Impact)        │  mitigated │             (CIA Triad +2)           │
│                                      │    by      │                                      │
│ • Financial loss & Extortion         │◄───────────┤ • Confidentiality (Encryption, RBAC) │
│ • Regulatory non-compliance (GDPR)   │            │ • Integrity (Hashing, Digital Sigs)  │
│ • Critical service downtime          │            │ • Availability (Redundancy, Backups) │
│ • Reputational damage & IP theft     │            │ • Authentication & Non-Repudiation   │
└──────────────────────────────────────┘            └──────────────────────────────────────┘
```

#### a. How Each Attack Leads to Specific Threats and Risks:
1. **Passive Attacks (Eavesdropping & Traffic Analysis):**
   - *Threat:* Interception of confidential data across unencrypted communication links.
   - *Risk:* Intellectual property theft, exposure of personal customer information, and severe regulatory fines (e.g., GDPR, HIPAA).
2. **Active Attacks (Masquerade & Replay):**
   - *Threat:* Unauthorized entities forging credentials or retransmitting authenticated messages.
   - *Risk:* Fraudulent financial transactions, unauthorized privilege escalation, and loss of trust.
3. **Active Attacks (Message Modification):**
   - *Threat:* Malicious modification of critical parameters in transit.
   - *Risk:* Erroneous business execution, financial distortion, and compromised system integrity.
4. **Active Attacks (Denial of Service - DoS/DDoS):**
   - *Threat:* Resource exhaustion of servers, network pipes, or databases.
   - *Risk:* Operational paralysis, critical infrastructure outage, and direct revenue loss.

#### b. How Security Goals Mitigate Them with Real-World Examples:
| Security Goal | Primary Threat Mitigated | Mitigation Mechanism | Real-World Incident / Example |
|---|---|---|---|
| **Confidentiality** | Eavesdropping / Packet Sniffing | End-to-end encryption (TLS 1.3, AES-256) | **Equifax Breach (2017):** Unencrypted sensitive PII exposure avoided today via ubiquitous database & transport encryption. |
| **Integrity** | Message Tampering / Malware Injection | Cryptographic hashing (SHA-256) & HMACs | **SolarWinds (2020):** Strong multi-stage code signing and hash verification prevent unauthorized backdoor injection. |
| **Availability** | Denial of Service (DoS/DDoS) | Anycast DNS, Load balancing, Redundancy | **Mirai Botnet (2016):** DNS provider Dyn overwhelmed; mitigated today using modern Cloudflare/Akamai Anycast scrubbing centers. |
| **Authentication** | Masquerade / Credential Stuffing | Multi-Factor Authentication (MFA), PKI | **Colonial Pipeline (2021):** Compromised single-factor password caused shutdown; mitigated by mandatory hardware MFA. |

---

### Task 2: Comparison of Classical Substitution Techniques

#### Concept Map:

```
                            ┌──────────────────────────┐
                            │   SUBSTITUTION CIPHERS   │
                            │ Letters replaced based   │
                            │ on a key mechanism       │
                            └────────────┬─────────────┘
                                         │
         ┌───────────────────────────────┴───────────────────────────────┐
         ▼                                                               ▼
┌───────────────────────────────┐                               ┌───────────────────────────────┐
│         CAESAR CIPHER         │                               │     MONOALPHABETIC CIPHER     │
│ • Key: 1 scalar shift k∈[0,25]│                               │ • Key: 26-letter permutation  │
│ • Formula: C=(P+k) mod 26     │                               │ • Key space: 26! ≈ 4 × 10^26  │
│ • Key space: 25 possible keys │                               │ • Formula: Arbitrary bijection│
│ • Complexity: O(1) negligible │                               │ • Complexity: O(1) lookup     │
│ • Security: WEAKEST           │                               │ • Security: Weak              │
│   (Trivial brute-force)       │                               │   (Frequency analysis breaks) │
└───────────────┬───────────────┘                               └───────────────┬───────────────┘
                │ [Shift -> Keyword]                                            │ [1-to-1 -> Matrix]
                ▼                                                               ▼
┌───────────────────────────────┐                               ┌───────────────────────────────┐
│        VIGENÈRE CIPHER        │                               │          HILL CIPHER          │
│ • Key: Keyword of length m    │                               │ • Key: n × n matrix K mod 26  │
│ • Formula: C_i=(P_i+K_i)mod 26│                               │ • Formula: C = K · P mod 26   │
│ • Key space: 26^m             │                               │ • Complexity: Matrix inverse  │
│ • Complexity: Moderate        │                               │ • Security: STRONGEST OF ALL  │
│ • Security: Moderate          │                               │   (Polygraphic diffusion      │
│   (Kasiski / IC attack)       │                               │    flattens frequency spikes) │
└───────────────────────────────┘                               └───────────────────────────────┘

  ═════════════════════════════════════════════════════════════════════════════════
  Security Hierarchy: Caesar < Monoalphabetic < Vigenère < Hill Cipher (Strongest)
  ═════════════════════════════════════════════════════════════════════════════════
```

#### Comparative Matrix:
| Feature | Caesar Cipher | Monoalphabetic Cipher | Vigenère Cipher | Hill Cipher |
|---|:---:|:---:|:---:|:---:|
| **Key Type** | Single integer shift $k$ | 26-character permutation | Keyword / phrase of length $m$ | Invertible $n \times n$ matrix |
| **Key Space** | $25$ | $26! \approx 4.03 \times 10^{26}$ | $26^m$ | Huge ($2^{84}$ for $5 \times 5$) |
| **Cipher Type** | Monoalphabetic | Monoalphabetic | Polyalphabetic | Polygraphic Block |
| **Complexity** | Extremely Low | Low | Medium | High (Matrix operations) |
| **Vulnerability** | Exhaustive Brute-Force | Single-letter Frequency | Kasiski examination, IC | Known-Plaintext Attack |

#### Analysis: Why the Hill Cipher is the Most Secure
1. **Polygraphic Multi-Letter Transformation:**
   Unlike Caesar, Monoalphabetic, and Vigenère ciphers which operate on single characters at a time, the Hill cipher encrypts blocks of $n$ letters as a unified algebraic vector.
2. **Shannon's Principle of Diffusion:**
   Each ciphertext letter is a linear combination of **all $n$ plaintext letters** in the block. Changing a single plaintext letter alters every letter in the resulting ciphertext block.
3. **Frequency Flattening:**
   It completely eliminates unigram letter frequency signatures. For an $n \times n$ Hill cipher, frequency analysis requires analyzing frequencies of $n$-grams ($26^n$ combinations), which is computationally intractable for reasonable block sizes.
4. **Limitation:**
   Being purely linear ($C = K \cdot P \pmod{26}$), it is vulnerable to a Known-Plaintext Attack with $n$ distinct linearly independent blocks.

---

### Task 3: Classical Schemes – Substitution vs. Transposition

#### Concept Map:

```
                            ┌───────────────────────────┐
                            │    CLASSICAL CIPHERS      │
                            └─────────────┬─────────────┘
                                          │
                  ┌───────────────────────┴───────────────────────┐
                  ▼                                               ▼
┌───────────────────────────────────┐           ┌───────────────────────────────────┐
│      SUBSTITUTION TECHNIQUES      │           │     TRANSPOSITION TECHNIQUES      │
│                                   │           │                                   │
│ • Principle: Alters letter identity│          │ • Principle: Rearranges letter    │
│ • Positions: Preserved            │           │   positions                       │
│ • Data Structure:                 │           │ • Identities: Preserved           │
│   Symbol-to-symbol replacement    │           │ • Data Structure:                 │
│ • Examples: Caesar, Playfair,     │           │   Permutation matrix / grid       │
│   Vigenère, Hill                  │           │ • Examples: Rail Fence,           │
│ • Flaw: Frequency leaks           │           │   Columnar Transposition          │
└─────────────────┬─────────────────┘           └─────────────────┬─────────────────┘
                  │                                               │
                  └───────────────────────┬───────────────────────┘
                                          ▼
                        ┌───────────────────────────────────┐
                        │          PRODUCT CIPHER           │
                        │ Combines Substitution (Confusion) │
                        │ with Transposition (Diffusion)    │
                        │ -> Foundation of Modern AES & DES │
                        └───────────────────────────────────┘
```

#### a. Differences and Similarities:
- **Data Structure Impact:**
  - *Substitution:* Changes the value of symbols while preserving their positions within the sequence. Text length and geometric layout remain identical.
  - *Transposition:* Preserves the exact character set (an exact anagram of the plaintext) while rearranging character coordinates across arrays, grids, or geometric trajectories.
- **Similarities:**
  - Both are symmetric classical schemes requiring shared secret keys.
  - Both, when used in isolation, leak statistical language properties.

#### b. Vulnerability Analysis: Which is More Vulnerable and Why?
- **Standalone Transposition (e.g., Rail Fence) is more vulnerable in simple configurations:**
  1. *Complete Frequency Preservation:* An eavesdropper immediately identifies that the message is an anagram because character frequencies match standard English (count of E, T, A, O remains unchanged).
  2. *Tiny Key Space:* Rail fence depth $d \in [2, N-1]$ has fewer than $N$ keys, broken in microseconds.
- **Monoalphabetic Substitution is similarly vulnerable** due to direct substitution mapping against standard frequency charts.
- **The Modern Solution:** Shannon's **Product Cipher** combines both techniques into alternating rounds of **Confusion** (non-linear substitution via S-Boxes) and **Diffusion** (transposition via P-Boxes or MixColumns), which forms the core architecture of **DES** and **AES**.

---

### Task 4: Steganography Concepts – Data Hiding, Watermarking & Survivability

#### Concept Map:

```
                          ┌─────────────────────────────┐
                          │   INFORMATION HIDING CORE   │
                          └──────────────┬──────────────┘
                                         │
         ┌───────────────────────────────┼───────────────────────────────┐
         ▼                               ▼                               ▼
┌─────────────────────────┐   ┌─────────────────────────┐   ┌─────────────────────────┐
│       DATA HIDING       │   │      WATERMARKING       │   │      SURVIVABILITY      │
│     (STEGANOGRAPHY)     │   │                         │   │      (ROBUSTNESS)       │
│                         │   │ • Goal: Authenticate &  │   │ • Goal: Preserve hidden │
│ • Goal: Conceal the     │   │   protect copyright     │   │   data against attacks  │
│   existence of the      │   │ • Visibility: Robust or │   │ • Resists: Compression, │
│   communication         │   │   fragile marks         │   │   cropping, filtering,  │
│ • Focus: High capacity, │   │ • Focus: Ownership proof│   │   noise injection,      │
│   maximal imperceptibility  │   & integrity audit     │   │   re-sampling           │
└────────────┬────────────┘   └────────────┬────────────┘   └────────────┬────────────┘
             │                             │                             │
             └─────────────────────────────┼─────────────────────────────┘
                                           ▼
                      ┌─────────────────────────────────────────┐
                      │    THE INFORMATION HIDING TRIANGLE      │
                      │   Capacity  ◄───►  Robustness           │
                      │          ▲         ▲                    │
                      │           \       /                     │
                      │         Imperceptibility                │
                      │ (Optimizing one trades off the others)  │
                      └─────────────────────────────────────────┘
```

#### a. Relationships Between These Concepts:
- **Data Hiding (Steganography)** prioritizes **imperceptibility and payload capacity**—making the communication completely invisible to third parties.
- **Watermarking** prioritizes **ownership assertion and tamper detection**—the mark may be invisible or visible, but must bind irrevocably to the carrier asset.
- **Survivability** is the operational metric that determines whether the hidden data (whether stego payload or watermark) endures signal transformations, lossy compression (JPEG, MP3), geometric distortion, or intentional attacks.

#### b. Contribution to Secure Communication:
- Steganography enables covert transmission under strict censorship or surveillance where the mere use of encryption is prohibited or flagged.
- Watermarking provides forensic non-repudiation and chain-of-custody verification.
- Survivability guarantees that security guarantees remain intact through real-world transmission channels.

#### c. Real-World Applications:
1. **Data Hiding:** Dissident or military covert communications embedding operational intelligence inside innocuous JPEG/PNG images posted on public web forums.
2. **Watermarking:** Digital Rights Management (DRM) and forensic tracking by streaming platforms (Netflix, Sony, Spotify) embedding imperceptible subscriber IDs to trace unauthorized leaks.
3. **Survivability:** Medical image security (DICOM imaging) embedding patient identity and diagnostic metadata inside ultrasound/MRI scans that survives radiological lossy compression and formatting.

---

### Task 5: Number Theory in Cryptography

#### Concept Map:

```
┌──────────────────────────────────────┐       ┌──────────────────────────────────────┐
│           MODULAR INVERSE            │       │      EXTENDED EUCLID ALGORITHM       │
│  a · a^(-1) ≡ 1 (mod m)              │◄─────►│  Finds integers x and y such that:   │
│  Exists iff gcd(a, m) = 1            │       │    a · x + m · y = gcd(a, m)         │
│  Role: Enables modular division in   │       │  Role: Derives RSA private exponent  │
│        decryption operations         │       │        d = e^(-1) mod phi(n)         │
└──────────────────┬───────────────────┘       └──────────────────┬───────────────────┘
                   │                                              │
                   ▼                                              ▼
┌──────────────────────────────────────┐       ┌──────────────────────────────────────┐
│       FERMAT'S LITTLE THEOREM        │       │           EULER'S THEOREM            │
│  If p is prime and gcd(a, p) = 1:    │       │  If gcd(a, n) = 1:                   │
│    a^(p-1) ≡ 1 (mod p)               │       │    a^phi(n) ≡ 1 (mod n)              │
│  Role: Primality testing             │       │  Role: Powers RSA decryption,        │
│        (Miller-Rabin), Diffie-Hellman│       │        proves M^(ed) ≡ M (mod n)     │
└──────────────────────────────────────┘       └──────────────────┬───────────────────┘
                                                                  ▲
                                                                  │
                                               ┌──────────────────┴───────────────────┐
                                               │        EULER'S PHI FUNCTION          │
                                               │  phi(p) = p - 1                      │
                                               │  phi(p·q) = (p - 1)(q - 1)           │
                                               │  Role: Defines order of group        │
                                               │        and RSA private key modulus   │
                                               └──────────────────────────────────────┘
```

#### a. How Each Concept is Mathematically Connected:
1. **Extended Euclid $\rightarrow$ Modular Inverse:**
   When $\gcd(a, m) = 1$, Extended Euclid yields $a \cdot x + m \cdot y = 1$, reducing modulo $m$ to $a \cdot x \equiv 1 \pmod m$. Hence, $x$ is the modular multiplicative inverse $a^{-1}$.
2. **Fermat's Little Theorem $\rightarrow$ Euler's Theorem:**
   Fermat's theorem states $a^{p-1} \equiv 1 \pmod p$ for prime $p$. Euler generalized this to any modulus $n$ using the totient $\phi(n)$: $a^{\phi(n)} \equiv 1 \pmod n$. When $n = p$ is prime, $\phi(p) = p - 1$, and Euler's theorem simplifies directly to Fermat's.
3. **Euler's Phi Function $\rightarrow$ RSA Key Setup:**
   For modulus $n = p \cdot q$, the multiplicative group size is $\phi(n) = (p-1)(q-1)$. This provides the modulus for computing the private exponent $d \equiv e^{-1} \pmod{\phi(n)}$.

#### b. Role in Encryption and Decryption:
- **Extended Euclid & Modular Inverse:** Used to calculate the decryption key $d$ in RSA and the inverse matrix $K^{-1}$ in the Hill cipher.
- **Fermat's Little Theorem:** Powers primality generation (guaranteeing that $p$ and $q$ are cryptographically prime) and forms the basis for Diffie-Hellman key exchange and ElGamal encryption.
- **Euler's Theorem:** Powers the decryption identity of RSA:
  $$C^d \equiv (M^e)^d \equiv M^{ed} \equiv M^{1 + k \cdot \phi(n)} \equiv M \cdot (M^{\phi(n)})^k \equiv M \cdot (1)^k \equiv M \pmod n$$

#### c. Which Concept is Most Critical for Public-Key Cryptography?
**Answer: Euler's Totient Function $\phi(n)$ and Euler's Theorem.**

**Justification:**
- The entire security and operational foundation of the RSA asymmetric cryptosystem depends on the **asymmetry of computing $\phi(n)$**:
  1. If the prime factors $p$ and $q$ are known, computing $\phi(n) = (p-1)(q-1)$ is trivial ($O(1)$ operations).
  2. If only $n$ is known, computing $\phi(n)$ is as hard as factoring $n$, which is computationally intractable for 2048/4096-bit numbers.
- Without Euler's Theorem, there would be no mathematical mechanism to create a **trapdoor one-way permutation** where public encryption is efficient for everyone, yet decryption is possible only for the holder of the secret factorized totient.
