# ElGamal-asymmetric-encryption
## created by Carlo Leiva

### discrption of ElGamal

ElGamal encryption is a public-key cryptosystem based on the Diffie-Hellman key exchange principle. It's designed for secure data encryption and relies on the discrete logarithm problem for its security, making it computationally infeasible to break with current technology. Here’s a quick summary of its key aspects:

Key Generation: Involves choosing a large prime number \(p\), a generator \(g\) of the multiplicative group of integers modulo \(p\), a private key \(x\) randomly selected from \(1\) to \(p-2\), and a public key \(y = g^x \mod p\).

Encryption: Uses the recipient's public key to encrypt a message \(m\) into a ciphertext \((c_1, c_2)\), where \(c_1 = g^k \mod p\) and \(c_2 = m \cdot y^k \mod p\), with \(k\) being a randomly chosen number for each encryption process.

Decryption: Uses the private key \(x\) to decrypt the ciphertext \((c_1, c_2)\) back into the original message \(m\), by computing the shared secret \(s = c_1^x \mod p\) and its inverse to finally recover \(m = c_2 \cdot s^{-1} \mod p\).

Security: Predicated on the difficulty of solving the discrete logarithm problem, ensuring that decrypting the message without the private key or deducing the private key from the public key is extremely hard.

ElGamal is notable for its semantic security, non-deterministic encryption (producing different ciphertexts for the same message on different occasions), and its foundational use in other cryptographic applications, such as digital signatures.


### Plan
Algorithm I worte for how to execute the ElGamal asymetric encryption and how to decrypt it sucesfuly. 
<img width="756" alt="image" src="https://github.com/Vidacelinda/ElGamal-asymmetric-encryption/assets/87499194/2b118fde-72da-4fa3-8798-9c27a39f9e78">

### Functionality 
Key Generation: The program starts by generating a key pair (private and public keys) and displaying them.

Encryption: It prompts the user to input a message (within the valid range) and the public key of the receiver (for simplicity, the program uses the generated public key). It then encrypts the message and outputs the ciphertext, consisting of two numbers (Y1 and Y2).

Decryption: Finally, the program decrypts the ciphertext using the private key and displays the original message, demonstrating the end-to-end encryption and decryption process.

### terminal out put 
<img width="784" alt="image" src="https://github.com/Vidacelinda/ElGamal-asymmetric-encryption/assets/87499194/deec8149-2d38-47c0-a9b8-86b04b87ab86">
