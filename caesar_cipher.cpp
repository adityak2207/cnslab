// Code for caesar cipher in c++
#include <bits/stdc++.h>
using namespace std;

int mod(int a, int b) {
    int r = a%b;
    return r>=0 ? r : r+b;
}

string caesarCipher(string ps, int key, char option) {
    //Encryption
    //First check if each character belongs to the english alphabet
    string ciphertext = "";
    for(auto c = ps.begin(); c!=ps.end(); c++) {
        if(*c >= 'a' && *c <= 'z') {
            if(option == 'e')
                ciphertext += mod((*c - 'a' + key), 26) + 'a';
            else if(option == 'd')
                ciphertext += mod((*c - 'a' - key), 26) + 'a';          
        }
        else if(isspace(*c))
            ciphertext += *c;
    }
    return ciphertext;
}

int main() {
    string ps, key, option, text;
    while(1) {
        cout << "Enter the plaintext : ";
        getline(cin, ps);
        cout << "Enter the key : ";
        getline(cin, key);

        cout << "Enter the option : ";
        getline(cin, option);
        text = caesarCipher(ps, stoi(key), option[0]);
        cout << text <<endl;
    }
}
