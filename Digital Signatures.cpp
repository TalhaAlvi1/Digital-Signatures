#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd
            result = (result * base) % mod;
        }
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return -1;
}

int main() {
    // Step 1: Key Generation
    int p = 61, q = 53; // Two prime numbers
    int n = p * q;      // Modulus
    int phi = (p - 1) * (q - 1); // Euler's totient function

    int e = 17; // Public key exponent
    while (gcd(e, phi) != 1) {
        e++; // Ensure e is coprime with phi
    }

    int d = modInverse(e, phi); // Private key exponent

    cout << "Public Key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private Key (d, n): (" << d << ", " << n << ")" << endl;

    // Step 2: Signing a Message
    int message;
    cout << "Enter a message to sign (as a number): ";
    cin >> message;

    int signature = modExp(message, d, n); // Sign the message
    cout << "Digital Signature: " << signature << endl;

    // Step 3: Verifying the Signature
    int decryptedMessage = modExp(signature, e, n); // Verify the signature
    if (decryptedMessage == message) {
        cout << "Signature is valid. Message authenticated!" << endl;
    } else {
        cout << "Invalid signature. Message tampered!" << endl;
    }

    return 0;
}
