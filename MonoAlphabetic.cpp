#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <ctime>
#include <string>
#include <cctype>
#include <iomanip>
#include <unordered_map>

using namespace std;

// Function to generate a random key for encryption
map<char, char> generateKey() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string shuffled = alphabet;

    random_device rd;
    mt19937 g(rd());
    shuffle(shuffled.begin(), shuffled.end(), g);

    map<char, char> key;
    for (size_t i = 0; i < alphabet.size(); i++) {
        key[alphabet[i]] = shuffled[i];
    }

    return key;
}

// Function to encrypt the plaintext
string encrypt(const string& plaintext, map<char, char>& key) {
    string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            char lowerC = tolower(c);
            ciphertext += isupper(c) ? toupper(key[lowerC]) : key[lowerC];
        } else {
            ciphertext += c;  // Keep non-alphabet characters unchanged
        }
    }
    return ciphertext;
}

// Function to decrypt the ciphertext
string decrypt(const string& ciphertext, map<char, char>& key) {
    map<char, char> reverseKey;
    for (auto& pair : key) {
        reverseKey[pair.second] = pair.first;
    }

    string decryptedText = "";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char lowerC = tolower(c);
            decryptedText += isupper(c) ? toupper(reverseKey[lowerC]) : reverseKey[lowerC];
        } else {
            decryptedText += c;
        }
    }
    return decryptedText;
}

// Function to perform frequency analysis on a text
void frequencyAnalysis(const string& text) {
    unordered_map<char, int> frequency;
    int totalLetters = 0;

    // Count the frequency of each letter
    for (char c : text) {
        if (isalpha(c)) {
            char lowerC = tolower(c);
            frequency[lowerC]++;
            totalLetters++;
        }
    }

    // Display the frequency of each letter
    cout << "Frequency Analysis:\n";
    for (char c = 'a'; c <= 'z'; c++) {
        double freq = (double)frequency[c] / totalLetters * 100;
        cout << c << ": " << setw(5) << frequency[c] << " (" << fixed << setprecision(2) << freq << "%)\n";
    }
}

int main() {
    // Input plaintext
    string plaintext;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Generate key and display it
    map<char, char> key = generateKey();
    cout << "\nGenerated Key (for encryption):\n";
    for (auto& pair : key) {
        cout << pair.first << " -> " << pair.second << "\n";
    }

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, key);
    cout << "\nEncrypted Text: " << ciphertext << endl;

    // Decrypt the ciphertext
    string decryptedText = decrypt(ciphertext, key);
    cout << "\nDecrypted Text: " << decryptedText << endl;

    // Perform frequency analysis
    cout << "\nFrequency Analysis on Encrypted Text:\n";
    frequencyAnalysis(ciphertext);

    return 0;
}
