// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: AffineCipher.cpp
// Last Modification Date: 25/3/2022
// Author1 and ID and Group: Hend Ahmed Kamal - 20211111 - A
// Teaching Assistant: Eng.Afaf
// Purpose: Encrypt and Decrypt messages according to Affine Cipher.
#include <iostream>
#include <string>

using namespace std;
// key values according to the given cipher\decipher equation.
const int a = 5, b = 8;

// Encrypt message (upper or lowercase)
string cipherMsg(string msg) {
    string cipher = "";
    for (int i = 0; i < msg.length(); i++) {
        if (msg[i] != ' ') {
            cipher = cipher + (char) ((((a * (msg[i] - 'A')) + b) % 26) + 'A');
        }
            // considering spaces
        else {
            cipher = cipher + msg[i];
        }
    }
    return cipher;
}

// Decrypt message (upper or lowercase)
string decipher(string cipher) {
    // Check if (a*c)%26 == 1
    string msg = "";
    int j = 0;
    int b = 0;
    for (int i = 0; i <= 25; i++) {
        b = (a * i) % 26;
        if (b == 1) {
            j = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++) {
        if (cipher[i] != ' ') {
            msg = msg + (char) (((j * ((cipher[i] + 'A' - b)) % 26)) + 'A');
        } else {
            msg = msg + cipher[i];
        }
    }
    return msg;
}

void getInput() {
    string msg;
    cout << "Please, enter your message :" << endl;
    getline(cin, msg);
    // Cipher function
    string cipherText = cipherMsg(msg);
    cout << "Encrypted Message = " << cipherText << endl;
    // Decipher function
    cout << "Decrypted Message = " << msg << endl;

    if (msg == "Exit" || msg == "exit") {
        exit(0);
    } else {
        getInput();
    }
}

int main() {

    getInput();

    return 0;

}
