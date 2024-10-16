#include <iostream>
#include <string>
#include <random>
#include <cctype> 
using namespace std;// For isalpha, toupper

string generateKey(int length) {
    string key;
    random_device rd;  // Obtain a random number from hardware
    mt19937 generator(rd());  // Seed the generator
    uniform_int_distribution<int> distribution(0, 25);  // Uniform distribution for A-Z

    for (int i = 0; i < length; ++i) {
        // Generate a random uppercase letter (A-Z)
        char randomChar = 'A' + distribution(generator);
        key += randomChar;
    }
    return key;
}

string preprocess(const string& text, bool& isValid) {
    string result;
    for (char c : text) {
        if (isalpha(c)) {
            result += toupper(c); // Convert to uppercase and ignore non-alpha
        } else {
            result += c; // Preserve non-alpha characters (like spaces)
        }
    }
    isValid = !result.empty();
    return result;
}

string encrypt(const string& plaintext, const string& key) {
    string ciphertext;
    int keyIndex = 0;

    for (char c : plaintext) {
        if (isalpha(c)) {
            // Encrypt using modular addition
            char encryptedChar = 'A' + (toupper(c) - 'A' + key[keyIndex] - 'A') % 26;
            ciphertext += encryptedChar;
            keyIndex++; // Move to the next character in the key
        } else {
            ciphertext += c; // Preserve non-alpha characters
        }
    }
    return ciphertext;
}

string decrypt(const string& ciphertext, const string& key) {
    string decryptedText;
    int keyIndex = 0;

    for (char c : ciphertext) {
        if (isalpha(c)) {
            // Decrypt using modular subtraction
            char decryptedChar = 'A' + (c - 'A' - (key[keyIndex] - 'A') + 26) % 26;
            decryptedText += decryptedChar;
            keyIndex++; // Move to the next character in the key
        } else {
            decryptedText += c; // Preserve non-alpha characters
        }
    }
    return decryptedText;
}

int main() {
    string plaintext;
    cout << "Enter plaintext (any characters allowed): ";
    getline(cin, plaintext); // Read the entire line

    bool isValid;
    string processedPlaintext = preprocess(plaintext, isValid);

    if (!isValid) {
        cout << "Invalid input. No alphabetic characters found." << endl;
        return 1;
    }

    // Generate a key of the same length as the processed plaintext
    string key = generateKey(processedPlaintext.length());

    string ciphertext = encrypt(processedPlaintext, key);
    string decryptedText = decrypt(ciphertext, key);

    cout << "Generated Key: " << key << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
