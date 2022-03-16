/*

FCAI - Programming 1 - 2022 - Assignment 2
Program Name: SimpleSubstitutionCipher_20210488.cpp
Program Description: This program ciphers messages by getting a secret key and shifts the alphabet
 by removing the secret key's characters from the alphabet and replaces the message characters' index from the alphabet

Last Modification Date: March 16, 2022
Version: v1.0.0
Author: Youssef Moataz
ID: 20210488
Group: A
Teaching Assistant: Not Yet
Purpose: Cipher and Decipher messages

*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// define the characters list
const string alphabetMain = "abcdefghijklmnopqrstuvwxyz";
// this will be changed to secret key
string alphabet = "abcdefghijklmnopqrstuvwxyz";

// define the functions
void cipher(string text, string secretKey);

void decipher(string text, string secretKey);

// action #1
void getInputAndCipher() {

    string key;

    cout << "Enter the secret key" << endl;

    getline(cin, key);

    for (int i = 0; i < key.length(); i++) {
        key[i] = tolower(key[i]);
    }

    for (int i = 0; i < key.length(); i++) {
        auto position = remove(alphabet.begin(), alphabet.end(), key[i]);
        alphabet.erase(position, alphabet.end());
    }


    string secretKey = key + alphabet;
    cout << "The secret key is: " << secretKey << endl;

    string message;

    cout << "Enter the message" << endl;

    getline(cin, message);

    for (int i = 0; i < message.length(); i++) {
        message[i] = tolower(message[i]);
    }

    cipher(message, secretKey);

}

void cipher(string text, string secretKey) {

    for (int i = 0; i < text.length(); i++) {

        for (int j = 0; j < alphabetMain.length(); j++) {

            if (text[i] == alphabetMain[j]) {
                cout << secretKey[j];
            }

        }

        if (!isalpha(text[i])) {
            cout << text[i];
        }

    }

}

// action #1
void getInputAndDecipher() {

    string key;

    cout << "Enter the secret key" << endl;

    getline(cin, key);

    for (int i = 0; i < key.length(); i++) {
        key[i] = tolower(key[i]);
    }

    for (int i = 0; i < key.length(); i++) {
        auto position = remove(alphabet.begin(), alphabet.end(), key[i]);
        alphabet.erase(position, alphabet.end());
    }

    string secretKey = key + alphabet;
    cout << "The secret key is: " << secretKey << endl;

    string message;

    cout << "Enter the message" << endl;

    getline(cin, message);

    for (int i = 0; i < message.length(); i++) {
        message[i] = tolower(message[i]);
    }

    decipher(message, secretKey);

}

void decipher(string text, string secretKey) {

    for (int i = 0; i < text.length(); i++) {

        for (int j = 0; j < secretKey.length(); j++) {

            if (text[i] == secretKey[j]) {
                cout << alphabetMain[j];
            }

        }

        if (!isalpha(text[i])) {
            cout << text[i];
        }

    }

}

void getUserChoice() {

    int userChoice = 0;

    cout << "\n\n";
    cout << "Ahlan ya user ya habibi." << endl << "What do you like to do today ?" << endl;
    cout << "1 - Cipher a message" << endl;
    cout << "2 - Decipher a message" << endl;
    cout << "3 - End" << endl;

    cin >> userChoice;

    cin.ignore();

    switch (userChoice) {
        case 1: // action #1
            getInputAndCipher();

            // re-get the user coice
            getUserChoice();
            break;

        case 2: // action #2
            getInputAndDecipher();

            // re-get the user coice
            getUserChoice();
            break;

        case 3: // action #3
            // finishes the program
            exit(0);
    }

}

int main() {

//    getInputAndCipher();
//    getInputAndDecipher();

    getUserChoice();

    return 0;
}