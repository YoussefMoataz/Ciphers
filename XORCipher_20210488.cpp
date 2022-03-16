/*

---XOR cipher and decipher---

This program is used to encrypt and decrypt text by XORing it with a secret key
The secret key here is "P"
User can decipher text from hexaDecimal input also

@Date: March 13, 2022
@Author: Youssef Moataz
@Version: v1.1.4

*/

#include <iostream>
#include <string>
using namespace std;

int getCipherSecretKey() {

    return (int)'P';

}

// declare the function, initialized later
void callDecryptionFromHexa();

// convert decimal values to hexa (one by one)
string decToHex(int num) {

    int decimalNum, rem;

    // this will be the output
    string hexaNnum = "";

    // define hexa values
    char hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

    decimalNum = num;

    // basic algorithm to convert deecimal number to hexa
    while (decimalNum > 0)
    {
        rem = decimalNum % 16;
        hexaNnum = hex[rem] + hexaNnum;
        decimalNum = decimalNum / 16;
    }

    // the output
    return hexaNnum;

}

// START
// Ciphering and deciphering
// makes the XOR operation (one by one)
int encrypt(int num) {

    // not only XORing
    // discovered the added 96 values from the outputs of "Cipher and Calculator Description" algorithm 8
    return (num ^ getCipherSecretKey()) + 96;

}

// returns a ciphered text to normal text by re-XORing the ciphered text
int decrypt(int num) {

    // the opposite of the encrypt function
    return ((num - 96) ^ getCipherSecretKey());

}

// used to decipher from hexa
void decipher(string cipher) {

    char hexaPair [] = " ";
    int hexaCounter = 0;

    try
    {

        // add leading zero to make even text length
        if (cipher.length() % 2 != 0) {
                cipher = "0" + cipher;
        }

        // split the string after two characters
        for (int i = 0; i < cipher.length(); i++) {

            // hexaPair contains two characters only
            if (hexaCounter < 2) {
                   hexaPair[hexaCounter] = cipher[i];
                   hexaCounter += 1;
            }

            // print the character of the corresonding hexa value
            if (hexaCounter == 2) {
                 cout << ((char)(((int)stoi(hexaPair, 0, 16) - 96) ^ 80));

                 // reset the values for new hexa code
                 hexaPair[0] = ' ';
                 hexaPair[1] = ' ';
                 hexaCounter = 0;
            }

        }

       
    }
    catch (const std::exception&)
    {
        // if not convertable to integer -> call the input function again
        callDecryptionFromHexa();
    }
    

}
// End
// Ciphering and deciphering


// contains code for action #1
void callEncryption() {

    string userInput = "";

    cout << "Enter message to cipher : ";
    cin >> userInput;

    // capitalize the input to be fillable in hexa range (00 - FF)
    // as capitals value is less than smalls value by 32
    for (int j = 0; j < userInput.length(); j++) {
        userInput[j] = toupper(userInput[j]);
    }

    string cipher = "";

    // encypt the input
    for (int i = 0; i < userInput.length(); i++) {
        cipher += (char)encrypt((int)userInput[i]);
    }

    // print the encrypted input (ciphered text)
    cout << cipher;

    cout << endl;

    // print the hexa representation
    for (int i = 0; i < userInput.length(); i++) {
        cout << decToHex((char)encrypt((int)userInput[i]));
    }

}

// contains code for action #1
void callDecryption() {

    string userInput = "";

    cout << "Enter message to decipher : ";
    cin >> userInput;

    string cipher = "";

    // decrypt the input
    for (int i = 0; i < userInput.length(); i++) {
        cipher += (char)decrypt((int)userInput[i]);
    }

    // print the decrypted text (normal text)
    cout << cipher;

}

// contains code for action #1
void callDecryptionFromHexa() {

    string userInput = "";

    cout << "Enter message to decipher as hexa : ";
    cin >> userInput;

    decipher(userInput);

}

// First-to-call function
void getUserChoice() {

    int userChoice = 0;

    cout << "\n\n";
    cout << "Ahlan ya user ya habibi." << endl << "What do you like to do today ?" << endl;
    cout << "1 - Cipher a message" << endl;
    cout << "2 - Decipher a message" << endl;
    cout << "3 - Decipher a message from hexa" << endl;
    cout << "4 - End" << endl;

    cin >> userChoice;

    switch (userChoice)
    {
    case 1: // action #1
        callEncryption();

        // re-get the user coice
        getUserChoice();
        break;

    case 2: // action #2
        callDecryption();

        // re-get the user coice
        getUserChoice();
        break;

    case 3: // action #3
        callDecryptionFromHexa();

        // re-get the user coice
        getUserChoice();
        break;

    case 4: // action #4
        // finishes the program
        exit(0);

    default:
        break;
    }


}

// ### MAIN ###
int main()
{
    
    // master function
    getUserChoice();

    return 0;
}
