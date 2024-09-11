#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to encrypt the given text using the Rail Fence Cipher
string encryptRailFence(string text, int key) {
    vector<string> rail(key);
    int dir = 1; // Direction of movement: 1 for down, -1 for up
    int row = 0; // Current row (rail)

    // Fill the rail matrix by zig-zagging
    for (char ch : text) {
        rail[row].push_back(ch);
        row += dir;

        // Change direction at the top or bottom
        if (row == 0 || row == key - 1) {
            dir = -dir;
        }
    }

    // Read the matrix row-wise to generate the encrypted text
    string result;
    for (const string& r : rail) {
        result += r;
    }

    return result;
}

// Function to decrypt the given text using the Rail Fence Cipher
string decryptRailFence(string cipher, int key) {
    vector<vector<char>> rail(key, vector<char>(cipher.size(), '\n'));

    int dir = 1;
    int row = 0;
    int idx = 0;

    // Mark the positions where characters will go
    for (int i = 0; i < cipher.size(); i++) {
        rail[row][i] = '*';
        row += dir;

        if (row == 0 || row == key - 1) {
            dir = -dir;
        }
    }

    // Fill the matrix with characters of the cipher text
    for (int r = 0; r < key; r++) {
        for (int i = 0; i < cipher.size(); i++) {
            if (rail[r][i] == '*' && idx < cipher.size()) {
                rail[r][i] = cipher[idx++];
            }
        }
    }

    // Read the matrix by zig-zagging to decrypt
    string result;
    row = 0;
    dir = 1;
    for (int i = 0; i < cipher.size(); i++) {
        result.push_back(rail[row][i]);
        row += dir;

        if (row == 0 || row == key - 1) {
            dir = -dir;
        }
    }

    return result;
}

int main() {
    string text;
    int key;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the key (number of rails): ";
    cin >> key;

    string encrypted = encryptRailFence(text, key);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = decryptRailFence(encrypted, key);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
