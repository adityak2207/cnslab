// Code for vigenere cipher
#include <bits/stdc++.h>
using namespace std;

string vigenereCipher(string ps, string key, char option);

int main() {
    string ps, key, option;
    while(1) {

        cout << "Enter plaintext : "; 
        getline(cin, ps);
        cout << "Enter key : ";
        getline(cin, key);
        cout << "Enter option : ";
        getline(cin, option);

        cout << vigenereCipher(ps, key, option[0]) << "\n\n";
    }
}

int mod(int a, int b){
    int r=a%b;
    return r>0 ? r : r+b;
}

string vigenereCipher(string ps, string key, char option) {
    //Encryption
    // First check if both plaintext and key are characters or not
    string ciphertext = "";
    int keyPos = 0;

    for(auto c1 = ps.begin(); c1!=ps.end(); c1++) {
        keyPos %= key.length();
        char c2 = key[keyPos];
        if(*c1 >= 'a' && *c1 <= 'z' && c2 >= 'a' && c2 <= 'z') {
            int pos;
            int shift = key[keyPos] - 'a';
             if(option == 'e') {
                pos = mod((*c1 - 'a' + shift), 26) + 'a';
             }
             else if(option == 'd') {
                pos = mod((*c1 - 'a' - shift), 26) + 'a';
             }
             ciphertext += (char) pos;
        }
        else if(isspace(*c1)) {
            ciphertext += *c1;
            keyPos--;
        }
        keyPos++;
    }

    return ciphertext;
}