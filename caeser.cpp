#include <bits/stdc++.h>
using namespace std;

// Encryption Function
void Encrypt(string inputText, int shift) {

    // Iterate through each character
    for(char &s: inputText) {

        // Check for alphabet
        if(isalpha(s)) {

            // Check for uppercase or lowercase
            if(s<'a') {
                s+=shift;           // Shift ascii value right
                if(s>'Z') s-=26;    // If shift exceeds z, cycle start from a
            } else {
                s+=shift;           // Same procedure as above
                if(s>'z') s-=26;
            }
        } 
    }

    cout << "The encoded message is " << inputText << "\n";
}

//Decryption Function
void Decrypt(string inputText, int shift) {

    // Iterate through each character
    for(char &s: inputText) {

        // Check for alphabet
        if(isalpha(s)) {

            // Check for uppercase or lowercase
            if(s<'a') {
                s-=shift;           // Shift ascii value left
                if(s<'A') s+=26;    // If shift preceeds a, cycle back from z
            } else {
                s-=shift;           // Same procedure as above
                if(s<'a') s+=26;
            }
        }
    }

    cout << "The decoded message is " << inputText << "\n";
}
void chisquare(string inputText, int shift) {

    // Iterate through each character
    for(char &s: inputText) {

        // Check for alphabet
        if(isalpha(s)) {

            // Check for uppercase or lowercase
            if(s<'a') {
                s-=shift;           // Shift ascii value left
                if(s<'A') s+=26;    // If shift preceeds a, cycle back from z
            } else {
                s-=shift;           // Same procedure as above
                if(s<'a') s+=26;
            }
        }
    }

    cout << "The decoded message is " << inputText << "\n";
}

void DictionaryCreation(string inputText, int shift) {
    string dict1[];
    int itemsDict;
    cout<< "";
    }

void DictionaryMatch(string inputText, int shift) {
    string dict[];
    }

    cout << "The decoded message is " << inputText << "\n";
    cout << "The key is" << shift << "\n";
}

int main() {
    
    string inputText;
    int shift,operation;
    char c;

    cout << "Type \n'1' to encrypt \n'2' to decrypt\n:";
    cin >> operation;
    
    // Invalid case
    if((operation != 1) && (operation != 2)) {
        cout << "Invalid input\n";
        return 0;
    }

    cout << "Type the message: ";
    cin >> inputText;

    cout << "Enter the key(lowercase alphabet): ";
    cin >> c;
    shift=(int)c;
    shift-=97;

    if(operation == 1) Encrypt(inputText,shift);
    else Decrypt(inputText,shift);

    return 0;
}
