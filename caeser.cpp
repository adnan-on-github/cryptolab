#include <bits/stdc++.h>
#include <vector>
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

int DictionaryCreation(){
    vector<string> dict;
    string item;
    int x,lengthofdict;
    cout<<"enter the no.of elements in your dictionary: ";
    cin>>lengthofdict;
    cout<< "Enter the words of your dictionary\n";
    for(int i=0;i<lengthofdict;i++){
        cin>>item;
        dict.push_back(item);
    }
    cout<<"your dictionary is\n";
    for(auto x : dict){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}

void DictionaryMatch(string inputText, int shift) {
    

    cout << "The decoded message is " << inputText << "\n";
    cout << "The key is" << shift << "\n";
}

int main() {
    
    string inputText;
    int shift,operation;
    char c;

    cout << "Type \n'1' to encrypt \n'2' to decrypt\n'3'for dictionary creation\n:";
    cin >> operation;
    
    //Invalid case
    if((operation != 1) && (operation != 2)) {
       cout << "Invalid input\n";
        return 0;
    }
    if((operation == 1) || (operation == 2)) {
        cout << "Type the message: ";
        cin >> inputText;

        cout << "Enter the key(lowercase alphabet): ";
        cin >> c;
        shift=(int)c;
        shift-=97;

        if(operation == 1) Encrypt(inputText,shift);
        else Decrypt(inputText,shift);
    }
    if(operation == 3) {
        DictionaryCreation();
    }
    return 0;
}
