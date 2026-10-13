# SIMATS ENGINEERING
## ASSESSMENT TOOL 1 (CO1_AT1)

**Course Name:** Cryptography and Network Security  
**Course Code:** CSA5116  
**Course Outcome Covered:** CO1: Apply classical encryption techniques using symmetric and asymmetric ciphers to encrypt and decrypt data for ensuring data security (BL3, BL4)  
**Assessment Tool Weightage:** 40%  
**Total Marks:** 50  

**Student Name:** M.S. Livesh Vetrivel  
**Register No:** 192521023  
**Department:** Department of B.Tech Information Technology  
**Institution:** Saveetha School of Engineering, SIMATS  

---

## Annexure A: Application-Based Questions & Complete Solutions

---

### Question 1: Scenario – Event Communication Security
> A student organization is preparing to share confidential event details with its core members using a simple classical encryption method. During testing, a message **"MEET AT NOON"** is transformed into an encoded version using a fixed shift pattern.  
> a. Reconstruct how the encrypted message might appear if a shift of 4 positions is applied.  
> b. Explain how an authorized member, aware of the encoding rule, would retrieve the original message.

#### Solution:
**Encryption Algorithm:** Caesar Cipher with key $k = 4$:
$$C = (P + k) \pmod{26}$$

#### Part (a): Step-by-Step Transformation
| Plaintext Letter | Alphabet Index ($P$) | $(P + 4) \pmod{26}$ | Ciphertext Letter ($C$) |
|:---:|:---:|:---:|:---:|
| **M** | 12 | $(12 + 4) = 16$ | **Q** |
| **E** | 4  | $(4 + 4) = 8$   | **I** |
| **E** | 4  | $(4 + 4) = 8$   | **I** |
| **T** | 19 | $(19 + 4) = 23$ | **X** |
| *(space)* | — | — | *(space)* |
| **A** | 0  | $(0 + 4) = 4$   | **E** |
| **T** | 19 | $(19 + 4) = 23$ | **X** |
| *(space)* | — | — | *(space)* |
| **N** | 13 | $(13 + 4) = 17$ | **R** |
| **O** | 14 | $(14 + 4) = 18$ | **S** |
| **O** | 14 | $(14 + 4) = 18$ | **S** |
| **N** | 13 | $(13 + 4) = 17$ | **R** |

- **Encrypted Message:** `QIIX EX RSSR`

#### Part (b): Message Retrieval Process
An authorized recipient performs modular subtraction by applying the inverse shift:
$$P = (C - k + 26) \pmod{26} = (C - 4 + 26) \pmod{26}$$
Alternatively, shifting forward by $26 - 4 = 22$ positions retrieves the original text:
- `Q` (16) $\rightarrow (16 - 4) = 12 \rightarrow$ **M**
- `I` (8) $\rightarrow (8 - 4) = 4 \rightarrow$ **E**
- `I` (8) $\rightarrow (8 - 4) = 4 \rightarrow$ **E**
- `X` (23) $\rightarrow (23 - 4) = 19 \rightarrow$ **T**
- **Recovered Plaintext:** `MEET AT NOON`

---

### Question 2: Scenario – Intercepted Suspicious Message
> A cybersecurity intern intercepts the coded message: **"GSRH RH Z HVXIVG"** during network monitoring. The structure of the text suggests a simple substitution mechanism rather than complex encryption.  
> a. Deduce the most likely original message.  
> b. Justify your answer by analyzing repeating patterns, letter structures, or known cipher characteristics.

#### Solution:

#### Part (a): Deduce Original Message
- **Intercepted Ciphertext:** `GSRH RH Z HVXIVG`
- **Decoded Original Message:** `THIS IS A SECRET`

#### Part (b): Cryptanalytic Justification
1. **Single-Letter Word Analysis:**
   - In the English language, the only common single-letter words are **"A"** and **"I"**.
   - Here, the third word is `Z`. In the classical **Atbash Cipher** (reciprocal substitution where $A \leftrightarrow Z$, $B \leftrightarrow Y$, etc.):
     $$\text{Plain} = 25 - \text{Cipher}$$
     Therefore, `Z` (index 25) maps directly to `A` (index 0).
2. **Two-Letter Word Analysis:**
   - The second word is `RH`. Using Atbash:
     - `R` (17) $\rightarrow 25 - 17 = 8 \rightarrow$ **I**
     - `H` (7) $\rightarrow 25 - 7 = 18 \rightarrow$ **S**
     - Result: **"IS"**, one of the most common English words.
3. **Four-Letter Word with Repeating End:**
   - `GSRH`:
     - `G` (6) $\rightarrow 25 - 6 = 19 \rightarrow$ **T**
     - `S` (18) $\rightarrow 25 - 18 = 7 \rightarrow$ **H**
     - `R` (17) $\rightarrow 25 - 17 = 8 \rightarrow$ **I**
     - `H` (7) $\rightarrow 25 - 7 = 18 \rightarrow$ **S**
     - Result: **"THIS"**.
4. **Six-Letter Patterned Word:**
   - `HVXIVG`:
     - `H` $\rightarrow$ **S**, `V` $\rightarrow$ **E**, `X` $\rightarrow$ **C**, `I` $\rightarrow$ **R**, `V` $\rightarrow$ **E**, `G` $\rightarrow$ **T**
     - The repeating letter `V` maps to the repeated vowel `E`.
     - Result: **"SECRET"**.

---

### Question 3: Scenario – Secure Messaging System
> A company deploys a keyword-based encryption technique for internal communication. An employee sends the word **"HELLO"** using the keyword **"KEY"** to ensure confidentiality.  
> a. Demonstrate how the encryption process transforms the message step-by-step.  
> b. Explain how the repeating keyword influences each character of the ciphertext.

#### Solution:
**Encryption Algorithm:** Vigenère Cipher:
$$C_i = (P_i + K_i) \pmod{26}$$

#### Part (a): Step-by-Step Transformation
- **Plaintext ($P$):** `H E L L O`
- **Repeated Keyword ($K$):** `K E Y K E`

| Index ($i$) | Plaintext ($P_i$) | Value ($P_i$) | Key ($K_i$) | Value ($K_i$) | $(P_i + K_i) \pmod{26}$ | Ciphertext ($C_i$) |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1 | **H** | 7  | **K** | 10 | $(7 + 10) = 17$ | **R** |
| 2 | **E** | 4  | **E** | 4  | $(4 + 4) = 8$   | **I** |
| 3 | **L** | 11 | **Y** | 24 | $(11 + 24) = 35 \equiv 9$ | **J** |
| 4 | **L** | 11 | **K** | 10 | $(11 + 10) = 21$ | **V** |
| 5 | **O** | 14 | **E** | 4  | $(14 + 4) = 18$ | **S** |

- **Resulting Ciphertext:** `RIJVS`

#### Part (b): Influence of the Repeating Keyword
- **Polyalphabetic Dispersion:** In monoalphabetic ciphers, identical plaintext characters always yield identical ciphertext characters. In this Vigenère cipher:
  - The first `L` (index 3) is aligned with key letter `Y`, producing **`J`**.
  - The second `L` (index 4) is aligned with key letter `K`, producing **`V`**.
- Because multiple Caesar shift alphabets are interleaved based on keyword positions, unigram frequency distributions are flattened, masking letter repetition and frustrating simple frequency cryptanalysis.

---

### Question 4: Scenario – Suspicious Digital Asset Investigation
> During a digital forensic audit, investigators suspect that a company logo file may contain hidden confidential information embedded within it. The file appears normal upon casual inspection.  
> a. Analyze how investigators could detect the presence of hidden data within the image.  
> b. Recommend two techniques that could strengthen the security of such hidden communications against detection or extraction.

#### Solution:

#### Part (a): Detection Methods (Steganalysis)
1. **Statistical LSB Steganalysis (Chi-Square $\chi^2$ & RS Analysis):**
   - Natural uncompressed or lossless images exhibit smooth, structured gradients among adjacent pixel color values.
   - Sequential Least Significant Bit (LSB) embedding alters the parity of pixel bytes, artificially equalizing the distribution of odd and even values (Pairs of Values - PoVs). Statistical $\chi^2$ tests reliably flag this unnatural binomial distribution.
2. **Visual Bit-Plane Slicing (Plane 0 Inspection):**
   - Extracting and rendering only the 0th bit plane reveals random high-frequency white noise or structured data patterns in modified regions, contrasting sharply with the natural smooth tonal variations of clean regions.
3. **File Anomaly & Checksum Auditing:**
   - Comparing the image's file size, compression structure, and SHA-256 hash against clean baseline corporate asset repositories. Any data appended beyond the End-Of-File (EOF) marker (e.g., JPEG `FF D9`) is immediately detectable.

#### Part (b): Techniques to Strengthen Covert Communication
1. **Cryptographic Pre-Encryption (Defense-in-Depth):**
   - Always encrypt the confidential payload using **AES-256-GCM** before steganographic embedding. The resulting ciphertext has maximal information entropy and is statistically indistinguishable from true random noise, preventing unauthorized reading even if extracted.
2. **Pseudorandom Spread Spectrum / Stego-Key Dispersal:**
   - Rather than embedding into sequential pixel bytes, use a cryptographically secure PRNG (CSPRNG) seeded with a shared secret *stego-key* to scatter embedded bits across non-consecutive pseudorandom pixel coordinates and high-variance edge areas. This resists spatial and statistical detection.

---

### Question 5: Scenario – Legacy Encryption in Corporate Communication
> A legacy system in a company still uses a transposition-based encryption method with three levels of arrangement. A received message appears as: **"WECRLTEERDSOEEFEAOCAIVDEN"**.  
> a. Determine the most probable original message by reversing the encryption process.  
> b. Critically evaluate why such a method is vulnerable in modern communication systems.  
> c. Propose one practical enhancement to improve the confidentiality of messages in this scenario.

#### Solution:

#### Part (a): Reversing the Rail Fence Transposition (Depth = 3)
- **Ciphertext:** `WECRLTEERDSOEEFEAOCAIVDEN`
- **Length:** $N = 25$ characters
- **Depth (Rails):** $d = 3$
- **Cycle Period:** $2 \times (3 - 1) = 4$

Traversing a zigzag pattern of depth 3 across 25 indices partitions the characters across the rails:
- **Rail 0** (indices 0, 4, 8, 12, 16, 20, 24) $\rightarrow$ **7 characters**: `W E C R L T E`
- **Rail 1** (indices 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23) $\rightarrow$ **12 characters**: `E R D S O E E F E A O C`
- **Rail 2** (indices 2, 6, 10, 14, 18, 22) $\rightarrow$ **6 characters**: `A I V D E N`

Reconstructing character by character along the zigzag rails:

```
Rail 0: W . . . E . . . C . . . R . . . L . . . T . . . E
Rail 1: . E . R . D . S . O . E . E . F . E . A . O . C .
Rail 2: . . A . . . I . . . V . . . D . . . E . . . N . .
```

Reading sequentially in column/zigzag order:
1. Rail 0: **W**
2. Rail 1: **E**
3. Rail 2: **A**
4. Rail 1: **R**
5. Rail 0: **E**
6. Rail 1: **D**
7. Rail 2: **I**
8. Rail 1: **S**
9. Rail 0: **C**
10. Rail 1: **O**
11. Rail 2: **V**
12. Rail 1: **E**
13. Rail 0: **R**
14. Rail 1: **E**
15. Rail 2: **D**
16. Rail 1: **F**
17. Rail 0: **L**
18. Rail 1: **E**
19. Rail 2: **E**
20. Rail 1: **A**
21. Rail 0: **T**
22. Rail 1: **O**
23. Rail 2: **N**
24. Rail 1: **C**
25. Rail 0: **E**

- **Original Plaintext:** `WE ARE DISCOVERED FLEE AT ONCE`

#### Part (b): Vulnerability in Modern Systems
1. **Preservation of Letter Frequencies:** Transposition only permutes character order without altering their identities. An eavesdropper can see unigram letter distributions matching natural English text (high count of E, T, A, O, I, N).
2. **Extremely Small Key Space:** For a Rail Fence cipher on a message of length $N$, the depth $d \in [2, N-1]$ provides fewer than $N$ possible keys, allowing instantaneous brute-force recovery.
3. **Vulnerable to Anagramming & Digram Analysis:** Automated solvers reconstruct the text using bigram/trigram transition probabilities without human intervention.

#### Part (c): Practical Enhancement
- **Implement a Product Cipher (Shannon's Confusion & Diffusion):**
  Combine transposition with a cryptographically secure substitution layer (e.g., modern **AES-256 in GCM mode**), ensuring that characters are both non-linearly substituted (confusion) and bit-permutated across blocks (diffusion), along with cryptographic integrity verification.

---

## Concept Maps & Theoretical Syntheses

---

### Concept Map 1: Substitution Techniques

```
                    ┌────────────────────────┐
                    │  SUBSTITUTION CIPHERS  │
                    │  Plaintext letters     │
                    │  replaced by others    │
                    └───────────┬────────────┘
                                │
        ┌───────────────────────┴───────────────────────┐
        ▼                                               ▼
┌─────────────────────────┐                   ┌─────────────────────────┐
│      CAESAR CIPHER      │                   │  MONOALPHABETIC CIPHER  │
│ Key: Single shift k     │                   │ Key: Full A-Z           │
│ C = (P + k) mod 26      │                   │      permutation table  │
│ Complexity: Very Low    │                   │ Complexity: 26! keys    │
│ (25 possible keys)      │                   │ (~ 4 × 10^26 keys)      │
│ Security: WEAKEST       │                   │ Security: Weak          │
│ (Brute-force & freq)    │                   │ (Letter frequency leaks)│
└───────────┬─────────────┘                   └───────────┬─────────────┘
            │ [Single shift -> Keyword]                   │ [Single table -> Matrix]
            ▼                                             ▼
┌─────────────────────────┐                   ┌─────────────────────────┐
│     VIGENÈRE CIPHER     │                   │       HILL CIPHER       │
│ Key: Repeated keyword   │                   │ Key: n × n matrix K     │
│ C_i = (P_i + K_i) mod 26│                   │      gcd(det K, 26) = 1 │
│ Complexity: Medium      │                   │ C = K · P mod 26        │
│ (26^m key space)        │                   │ Complexity: High        │
│ Security: Medium        │                   │ (Matrix inversion mod26)│
│ (Kasiski / IC attack)   │                   │ Security: STRONGEST     │
└─────────────────────────┘                   └─────────────────────────┘

  ══════════════════════════════════════════════════════════════════════
  Relative Strength Hierarchy:
  Caesar  <  Monoalphabetic  <  Vigenère  <  Hill Cipher (Strongest)
  ══════════════════════════════════════════════════════════════════════
```

#### Detailed Evaluation: Why Hill Cipher is the Most Secure
1. **Multi-Letter Block Encryption:** Hill cipher encrypts blocks of $n$ characters simultaneously as vectors, effectively flattening single-letter frequency spikes.
2. **High Diffusion:** Every ciphertext character depends on **all $n$** plaintext characters in the vector multiplied through the key matrix.
3. **Contrast with Others:** Caesar has only 25 keys; Monoalphabetic leaks identical single-letter frequencies; Vigenère remains susceptible to Kasiski examination and Index of Coincidence (IC) periodic key length deduction.
4. **Known Limitation:** Because Hill cipher is mathematically linear ($C = K \cdot P \pmod{26}$), it is vulnerable to a known-plaintext attack with $n$ linearly independent plaintext-ciphertext pairs. It is best used as a component combined with non-linear substitution.

---

### Concept Map 2: Number Theory in Cryptography

```
┌─────────────────────────────────┐       ┌─────────────────────────────────┐
│         MODULAR INVERSE         │       │    EXTENDED EUCLID ALGORITHM    │
│  a · a^(-1) ≡ 1 (mod n)         │◄─────►│  Finds x, y such that:          │
│  Exists iff gcd(a, n) = 1       │       │    a·x + n·y = gcd(a, n)        │
│  Role: Modular division,        │       │  Role: Derives private key      │
│        Hill key inversion       │       │        d = e^(-1) mod phi(n)    │
└────────────────┬────────────────┘       └────────────────┬────────────────┘
                 │                                         │
                 ▼                                         ▼
┌─────────────────────────────────┐       ┌─────────────────────────────────┐
│     FERMAT'S LITTLE THEOREM     │       │         EULER'S THEOREM         │
│  p prime, gcd(a, p) = 1         │       │  gcd(a, n) = 1                  │
│    a^(p-1) ≡ 1 (mod p)          │       │    a^phi(n) ≡ 1 (mod n)         │
│  Role: Miller-Rabin primality,  │       │  Role: Powers RSA decryption,   │
│        Diffie-Hellman, ElGamal  │       │        recovers message M       │
└─────────────────────────────────┘       └────────────────┬────────────────┘
                                                           ▲
                                                           │
                                          ┌────────────────┴────────────────┐
                                          │      EULER'S PHI FUNCTION       │
                                          │  phi(p) = p - 1                 │
                                          │  phi(p·q) = (p - 1)(q - 1)      │
                                          │  Role: Sets RSA exponent modulus│
                                          └─────────────────────────────────┘
```

#### How They Work Together in RSA Public-Key Cryptography:
1. **Key Generation:**
   - Select large primes $p$ and $q$; compute modulus $n = p \cdot q$.
   - Compute **Euler's Totient:** $\phi(n) = (p - 1)(q - 1)$.
   - Choose public exponent $e$ such that $\gcd(e, \phi(n)) = 1$.
   - Compute private exponent $d$ as the **Modular Inverse** of $e$ modulo $\phi(n)$ using the **Extended Euclidean Algorithm**:
     $$d = e^{-1} \pmod{\phi(n)} \iff e \cdot d \equiv 1 \pmod{\phi(n)}$$
2. **Encryption:** $C = M^e \pmod n$
3. **Decryption:** $M = C^d \pmod n$
4. **Mathematical Guarantee:**
   By **Euler's Theorem**, since $e \cdot d = 1 + k \cdot \phi(n)$:
   $$C^d = (M^e)^d = M^{ed} = M^{1 + k \cdot \phi(n)} = M \cdot (M^{\phi(n)})^k \equiv M \cdot (1)^k \equiv M \pmod n$$
   Keeping the factorization of $n$ (and thus $\phi(n)$) secret guarantees the security of the private key $d$.
