# Objective
Digital signatures are cryptographic tools used to ensure the authenticity, integrity, and non-repudiation of electronic messages or documents. This lab aims to provide an understanding of how digital signatures work and how they are implemented in cryptographic systems.
# Algorithm
**Key Generation**
1. Generate a pair of public and private keys using an asymmetric cryptographic algorithm such as RSA or Elliptic Curve Cryptography (ECC).

**Signing**
1. Hash the message using a cryptographic hash function like SHA-256 to create a fixed-length message digest.
2. Encrypt the message digest using the private key to create the digital signature.

**Verification**

1.Decrypt the digital signature using the sender's public key to retrieve the original message digest.

2. Hash the received message using the same cryptographic hash function.

4. Compare the decrypted message digest with the newly computed message digest:
   - If they match, the signature is valid, and the message is authenticated.
   - If they do not match, the signature is invalid, indicating tampering or forgery.

# Explanation
1. **Key Pair Generation:** A unique pair of keys (public and private) is generated for each user. The private key is kept secret, while the public key is shared openly.
2. **Signing Process:** The sender uses their private key to sign the hash of the message, ensuring the signature is unique to both the message and the sender.
3. **Verification Process:** The receiver uses the sender's public key to verify the signature, ensuring that the message is authentic and has not been altered during transmission.
4. **Security:** Digital signatures rely on the mathematical difficulty of reversing the encryption process without the private key, providing strong security guarantees.
