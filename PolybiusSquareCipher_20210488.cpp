/*

FCAI - Programming 1 - 2022 - Assignment 2
Program Name: PolybiusSquareCipher_20210488.cpp
Program Description: This program is used to encrypt and decrypt text from Polybius square with a secret key

Last Modification Date: March 18, 2022
Version: v1.1.4
Author: Youssef Moataz
ID: 20210488
Group: A
Teaching Assistant: Not Yet
Purpose: Cipher and Decipher messages

*/

#include <iostream>
#include <string>

using namespace std;

// ---DO NOT CHANGE--- alphabet characters forming the square
const char characters[5][5] = {{'a', 'b', 'c', 'd', 'e'},
                               {'f', 'g', 'h', 'i', 'k'},
                               {'l', 'm', 'n', 'o', 'p'},
                               {'q', 'r', 's', 't', 'u'},
                               {'v', 'w', 'x', 'y', 'z'}};
// ---DO NOT CHANGE--- alphabet characters forming the square


// get index of a character from int array
int indexOf(int arr[], char digit) {

    for (int i = 0; i < 5; i++) {

        if (digit == arr[i]) {
            return i;
        }

    }

    return 0;
}

string inputKeyAndCheckDigits() {

    string key;
    bool valid = true;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;

    cout << "Enter the secret key";

    // get the key
    getline(cin, key);

    if (key.length() == 5) {

        for (char d: key) {

            // if the character is not digit stop the loop
            if (!isdigit(d)) {
                valid = false;
                break;
            }

            if (d == '1') {
                count1++;
            } else if (d == '2') {
                count2++;
            } else if (d == '3') {
                count3++;
            } else if (d == '4') {
                count4++;
            } else if (d == '5') {
                count5++;
            }

        }

        // key must have exactly ONE (1, 2, 3, 4, 5)
        if ((count1 != 1) || (count2 != 1) || (count3 != 1) || (count4 != 1) || (count5 != 1)) {
            valid = false;
        }

        // recall the function if not valid input
        if (!valid) {
            inputKeyAndCheckDigits();

        // return the key ONLY if valid key is entered
        } else {
            return key;
        }

    // recall the function if not valid input
    } else {
        inputKeyAndCheckDigits();
    }

}

// encrypt
void getInputAndCipher() {

    // start key

    int secretKey[5];

    string key = inputKeyAndCheckDigits();

    // convert key characters to integers
    for (int i = 0; i < 5; ++i) {

        secretKey[i] = stoi(to_string(key[i]));

    }

    // end key

    string message;

    cout << "Enter the message:" << endl;

    // get the message
    getline(cin, message);

    int counter = 0;

    // convert the message to lower case and replace Js with Is (lower case also)
    for (int i = 0; i < message.length(); i++) {

        message[i] = tolower(message[i]);

        if (message[i] == 'j') {
            message[i] = 'i';
        }

    }

    // Encryption goes here
    // get the character with its indices
    // replace the those indices with the indices from the key's array.
    // Loop the message
    for (char c: message) {

        // loop the alphabet array - Rows
        for (int i = 0; i < 5; i++) {

            // loop the alphabet array - Columns
            for (int j = 0; j < 5; j++) {

                if (c == characters[i][j]) {
                    cout << key[i] << key[j];
                    counter++;
                }
            }

        }

        // print the space as is
        if (isspace(c)) {
            cout << c;
            counter++;
        }

    }

}

// decrypt
void getInputAndDecipher() {

    // start key

    int secretKey[5];

    string key = inputKeyAndCheckDigits();

    // convert key characters to integers
    for (int i = 0; i < 5; ++i) {

        secretKey[i] = stoi(to_string(key[i]));

    }

    // end key

    string cipher;

    cout << "Enter the cipher text:" << endl;

    // get the cipher text
    getline(cin, cipher);


    // Split the cipher and decrypt each Two digits together
    int pairCounter = 0;
    char codePair[] = " ";

    for (int i = 0; i < cipher.length(); i++) {

        // print the space as is
        if (isspace(cipher[i])) {

            cout << " ";
            continue;

        }

        // codePair contains two characters only
        if (pairCounter < 2) {
            codePair[pairCounter] = cipher[i];
            pairCounter += 1;
        }

        // print the character after getting its real indices from the alphabet array
        if (pairCounter == 2) {

            cout << characters[indexOf(secretKey, codePair[0])][indexOf(secretKey, codePair[1])];

            // reset the values for new hexa code
            codePair[0] = ' ';
            codePair[1] = ' ';
            pairCounter = 0;
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

        default:
            break;
    }


}

int main() {

    getUserChoice();

    return 0;
}
