#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

// Start Cipher 0

// key values according to the given cipher\decipher equation.
const int a = 5, b = 8;

// Encrypt message (upper or lowercase)
string cipherMsgC0(string msg) {
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
string decipherC0(string cipher) {
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

void getInputC0() {
    string msg;
    cout << "Please, enter your message :" << endl;
    getline(cin, msg);
    // Cipher function
    string cipherText = cipherMsgC0(msg);
    cout << "Encrypted Message = " << cipherText << endl;
    // Decipher function
    cout << "Decrypted Message = " << msg << endl;

    if (msg == "Exit" || msg == "exit") {
        exit(0);
    } else {
        getInputC0();
    }
}

// End Cipher 0


// Start Cipher 1

void cipherC1() {

    string word;
    int secret_shift;
    int n;
    int button;
    int size = word.size();
    cout << "Welcome to Encryption Program !" << endl;
    cout << "Press '1' to encrypt your message || press '-1' to decrypt your message:";
    cin >> button;
    cout << "Press '0' if your message is lowercase || Press '1' if your message is uppercase:" << endl;
    cin >> n;
    cout << "Please enter the secret shift key: " << endl;
    cin >> secret_shift;
    cout << "Please enter your message: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, word);

    if (secret_shift < 0)
        secret_shift = ((secret_shift % 26) + 26) % 26;
    else
        secret_shift = secret_shift;

    // Encrypting message
    if (button == 1) {
        for (int i = 0; word[i] != '\0'; i++) {    // loop until the string is over
            char chr = word[i];
            // lowercase encryption
            if (n == 0) {
                if (chr >= 'a' && chr <= 'z') {
                    chr = chr + secret_shift;
                    if (chr > 'z') {
                        chr = chr - 'z' + 'a' - 1;
                    }
                    word[i] = chr;
                }
            }
                // uppercase encryption
            else if (n == 1) {
                if (chr >= 'A' && chr <= 'Z') {
                    chr = chr + secret_shift;
                    if (chr > 'Z') {
                        chr = chr - 'Z' + 'A' - 1;
                    }
                    word[i] = chr;
                }
            }
        }
        cout << "Encrypted message = " << word << endl;
    }
        // Decrypting message
    else if (button == -1) {
        for (int i = 0; word[i] != '\0'; i++) {    // loop until the string is over
            char chr = word[i];
            // lowercase decryption
            if (n == 0) {
                if (chr >= 'a' && chr <= 'z') {
                    chr = chr - secret_shift;
                    if (chr < 'a') {
                        chr = chr + 'z' - 'a' + 1;
                    }
                    word[i] = chr;
                }
            }
                // uppercase decryption
            else if (n == 1) {
                if (chr >= 'A' && chr <= 'Z') {
                    chr = chr - secret_shift;
                    if (chr < 'A') {
                        chr = chr + 'Z' - 'A' + 1;
                    }
                    word[i] = chr;
                }
            }
        }
        cout << "Decrypted message = " << word << endl;
    }

}

// End Cipher 1


// Start Cipher 2

// ---DO NOT CHANGE--- alphabet characters and reversed
static char *const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char *const alphabetReversed = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
// ---DO NOT CHANGE---

// get index of character in char array , string
int indexOfC2(char arr[], char character) {

    for (int i = 0; i < strlen(arr); i++) {

        if (character == arr[i]) {
            return i;
        }

    }

    return 0;
}

void getInputAndCipherC2() {

    string message;

    cout << "Enter the message :" << endl;

    // get message
    getline(cin, message);

    // Encryption goes here
    for (int i = 0; i < message.length(); i++) {

        // print spaces as is
        if (isspace(message[i])) {
            cout << " ";

            // print the character by getting its index from the alphabet and using the index in the reverse alphabet
            // convert to upper case
        } else {
            cout << alphabetReversed[indexOfC2(alphabet, toupper(message[i]))];
        }

    }

}

void getInputAndDecipherC2() {

    string message;

    cout << "Enter the cipher :" << endl;

    // get message
    getline(cin, message);

    // Decryption goes here
    for (int i = 0; i < message.length(); i++) {

        // print spaces as is
        if (isspace(message[i])) {
            cout << " ";

            // print the character by getting its index from the reversed alphabet and using the index in the alphabet
            // convert to upper case
        } else {
            cout << alphabet[indexOfC2(alphabetReversed, toupper(message[i]))];
        }

    }

}

// get what the user needs to do
void getUserChoiceC2() {

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
            getInputAndCipherC2();

            // re-get the user coice
            getUserChoiceC2();
            break;

        case 2: // action #2
            getInputAndDecipherC2();

            // re-get the user coice
            getUserChoiceC2();
            break;

        case 3: // action #3
            // finishes the program
            exit(0);
    }

}


// End Cipher 2


// Start Cipher 3

void cipherC3() {

    int unchanged, choice;
    cout << "-if you want to cipher a message choose 1" << endl << "-if you want to decipher a message choose 2" << endl
         << "-if you want to exit the program choose 3" << endl;
    while (choice != 3) {
        string message, keyword = "", keyword2 = "", cipher, decipher;
        int unchanged, choice;
        cout << "choice :" << endl;
        cin >> choice;
        while (choice != 1 and choice != 2 and choice != 3) {
            cout << "Please choose 1 or 2 :" << endl;
            cin >> choice;
        }
        if (choice == 1) {
            cout << "Enter your message :" << endl;
            getline(cin >> ws, message, '\n');
            while (message.length() > 80) {
                cout << "Please enter another message its length is less than 80 :" << endl;
                getline(cin >> ws, message, '\n');
            }
            cout << "Enter the keyword :" << endl;
            cin >> keyword;
            while (keyword.length() > 8) {
                cout << "Please enter another keyword its length is less than 8 :" << endl;
                getline(cin >> ws, keyword, '\n');
            }
            while (keyword.length() < message.length()) {
                keyword += keyword;
            }
            for (int j = 0; j < message.length(); j++) {
                keyword2 += keyword[j];
            }
            for (int i = 0; i < message.length(); i++) {
                cipher += (((int(toupper(message[i])) + int(toupper(keyword[i]))) % 26) + 65);
                if (isspace(message[i]) or isdigit(message[i]) or ispunct(message[i])) {
                    unchanged = i;
                    cipher[i] = char(message[unchanged]);
                }
            }
            cout << "the ciphered message :" << endl << cipher << endl;
        } else if (choice == 2) {
            cout << "Enter your deciphered message :" << endl;
            getline(cin >> ws, message, '\n');
            while (message.length() > 80) {
                cout << "Please enter another message its length is less than 80 :" << endl;
                getline(cin >> ws, message, '\n');
            }
            cout << "Enter the keyword :" << endl;
            cin >> keyword;
            while (keyword.length() > 8) {
                cout << "Please enter another keyword its length is less than 8 :" << endl;
                getline(cin >> ws, keyword, '\n');
            }
            while (keyword.length() < message.length()) {
                keyword += keyword;
            }
            for (int j = 0; j < message.length(); j++) {
                keyword2 += keyword[j];
            }
            for (int h = 0; h < keyword2.length(); h++) {
                if (isspace(message[h]) or isdigit(message[h]) or ispunct(message[h])) {
                    unchanged = h;
                    decipher += char(message[unchanged]);
                }
                for (int i = 65; i <= 90; i++) {
                    if ((((i + toupper(keyword2[h])) % 26) + 65) == toupper(message[h])) {
                        decipher += char(i);
                    }
                }
            }
            cout << "the deciphered message :" << endl << decipher << endl;
        }
    }


}

// End Cipher 3


// Start Cipher 4



// End Cipher 4


// Start Cipher 5

// define the characters list
const string alphabetMain = "abcdefghijklmnopqrstuvwxyz";
// this will be changed to secret key
string alphabet5 = "abcdefghijklmnopqrstuvwxyz";

// define the functions
void cipherC5(string text, string secretKey);

void decipherC5(string text, string secretKey);

// action #1
void getInputAndCipherC5() {

    string key;

    cout << "Enter the secret key" << endl;

    getline(cin, key);

    // convert key to lower case
    for (int i = 0; i < key.length(); i++) {
        key[i] = tolower(key[i]);
    }

    // remove the key characters from the alphabet
    for (int i = 0; i < key.length(); i++) {
        auto position = remove(alphabet5.begin(), alphabet5.end(), key[i]);
        alphabet5.erase(position, alphabet5.end());
    }

    // add the key at the beginning of the remaining alphabet
    string secretKey = key + alphabet;

    // print the secret key
    cout << "The secret key is: " << secretKey << endl;

    string message;

    cout << "Enter the message" << endl;

    getline(cin, message);

    // convert message to lower case
    for (int i = 0; i < message.length(); i++) {
        message[i] = tolower(message[i]);
    }

    cipherC5(message, secretKey);

}

void cipherC5(string text, string secretKey) {

    // loop over the message characters
    for (int i = 0; i < text.length(); i++) {

        // loop over the full alphabet
        for (int j = 0; j < alphabetMain.length(); j++) {

            // encrypting process
            if (text[i] == alphabetMain[j]) {
                cout << secretKey[j];
            }

        }

        // print the non-alphabet characters as is
        if (!isalpha(text[i])) {
            cout << text[i];
        }

    }

}

// action #1
void getInputAndDecipherC5() {

    string key;

    cout << "Enter the secret key" << endl;

    getline(cin, key);

    // convert key to lower case
    for (int i = 0; i < key.length(); i++) {
        key[i] = tolower(key[i]);
    }

    // remove the key characters from the alphabet
    for (int i = 0; i < key.length(); i++) {
        auto position = remove(alphabet5.begin(), alphabet5.end(), key[i]);
        alphabet5.erase(position, alphabet5.end());
    }

    // add the key at the beginning of the remaining alphabet
    string secretKey = key + alphabet;

    // print the secret key
    cout << "The secret key is: " << secretKey << endl;

    string message;

    cout << "Enter the message" << endl;

    getline(cin, message);

    // convert message to lower case
    for (int i = 0; i < message.length(); i++) {
        message[i] = tolower(message[i]);
    }

    decipherC5(message, secretKey);

}

void decipherC5(string text, string secretKey) {

    // loop over the message characters
    for (int i = 0; i < text.length(); i++) {

        // loop over the secret key
        for (int j = 0; j < secretKey.length(); j++) {

            // decryption process
            if (text[i] == secretKey[j]) {
                cout << alphabetMain[j];
            }

        }

        // print the non-alphabet characters as is
        if (!isalpha(text[i])) {
            cout << text[i];
        }

    }

}

void getUserChoiceC5() {

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
            getInputAndCipherC5();

            // re-get the user coice
            getUserChoiceC5();
            break;

        case 2: // action #2
            getInputAndDecipherC5();

            // re-get the user coice
            getUserChoiceC5();
            break;

        case 3: // action #3
            // finishes the program
            exit(0);
    }

}


// End Cipher 5


// Start Cipher 6

// ---DO NOT CHANGE--- alphabet characters forming the square
const char characters[5][5] = {{'a', 'b', 'c', 'd', 'e'},
                               {'f', 'g', 'h', 'i', 'k'},
                               {'l', 'm', 'n', 'o', 'p'},
                               {'q', 'r', 's', 't', 'u'},
                               {'v', 'w', 'x', 'y', 'z'}};
// ---DO NOT CHANGE--- alphabet characters forming the square


// get index of a character from int array
int indexOfC6(int arr[], char digit) {

    for (int i = 0; i < 5; i++) {

        if (digit == arr[i]) {
            return i;
        }

    }

    return 0;
}

string inputKeyAndCheckDigitsC6() {

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
            inputKeyAndCheckDigitsC6();

        // return the key ONLY if valid key is entered
        } else {
            return key;
        }

    // recall the function if not valid input
    } else {
        inputKeyAndCheckDigitsC6();
    }

}

// encrypt
void getInputAndCipherC6() {

    // start key

    int secretKey[5];

    string key = inputKeyAndCheckDigitsC6();

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
void getInputAndDecipherC6() {

    // start key

    int secretKey[5];

    string key = inputKeyAndCheckDigitsC6();

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

            cout << characters[indexOfC6(secretKey, codePair[0])][indexOfC6(secretKey, codePair[1])];

            // reset the values for new hexa code
            codePair[0] = ' ';
            codePair[1] = ' ';
            pairCounter = 0;
        }

    }

}

void getUserChoiceC6() {

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
            getInputAndCipherC6();

            // re-get the user coice
            getUserChoiceC6();
            break;

        case 2: // action #2
            getInputAndDecipherC6();

            // re-get the user coice
            getUserChoiceC6();
            break;

        case 3: // action #3
            // finishes the program
            exit(0);

        default:
            break;
    }


}

// End Cipher 6


// Start Cipher 7

// this function is used to encrypt a character/digit and return its morse representation
string encryptMorseC7(char input) {

    // define the character-morse representation
    switch (input) {
        case 'a':
            return ".-";
        case 'b':
            return "-...";
        case 'c':
            return "-.-.";
        case 'd':
            return "-..";
        case 'e':
            return ".";
        case 'f':
            return "..-.";
        case 'g':
            return "--.";
        case 'h':
            return "....";
        case 'i':
            return "..";
        case 'j':
            return ".---";
        case 'k':
            return "-.-";
        case 'l':
            return ".-..";
        case 'm':
            return "--";
        case 'n':
            return "-.";
        case 'o':
            return "---";
        case 'p':
            return ".--.";
        case 'q':
            return "--.-";
        case 'r':
            return ".-.";
        case 's':
            return "...";
        case 't':
            return "-";
        case 'u':
            return "..-";
        case 'v':
            return "...-";
        case 'w':
            return ".--";
        case 'x':
            return "-..-";
        case 'y':
            return "-.--";
        case 'z':
            return "--..";
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";
        case '0':
            return "-----";
        default:
            return " ";
    }
}

// get message from user and encrypt it
void getInputAndCipherC7(){
    string text;

    cout << "Enter the message" << endl;

    getline(cin, text);

    // loop over the characters of the message and encrypt each character then print it
    for (char i : text) {

        cout << encryptMorseC7(tolower(i)) << " ";

    }

}

// this function is used to decrypt a morse character and returns a character/digit
char decryptMorseC7(string morse) {

    map<string, char> morseCharacters;

    // define the morse-character representation
    morseCharacters.insert(pair<string, char>(".-", 'a'));
    morseCharacters.insert(pair<string, char>("-...", 'b'));
    morseCharacters.insert(pair<string, char>("-.-.", 'c'));
    morseCharacters.insert(pair<string, char>("-..", 'd'));
    morseCharacters.insert(pair<string, char>(".", 'e'));
    morseCharacters.insert(pair<string, char>("..-.", 'f'));
    morseCharacters.insert(pair<string, char>("--.", 'g'));
    morseCharacters.insert(pair<string, char>("....", 'h'));
    morseCharacters.insert(pair<string, char>("..", 'i'));
    morseCharacters.insert(pair<string, char>(".---", 'j'));
    morseCharacters.insert(pair<string, char>("-.-", 'k'));
    morseCharacters.insert(pair<string, char>(".-..", 'l'));
    morseCharacters.insert(pair<string, char>("--", 'm'));
    morseCharacters.insert(pair<string, char>("-.", 'n'));
    morseCharacters.insert(pair<string, char>("---", 'o'));
    morseCharacters.insert(pair<string, char>(".--.", 'p'));
    morseCharacters.insert(pair<string, char>("--.-", 'q'));
    morseCharacters.insert(pair<string, char>(".-.", 'r'));
    morseCharacters.insert(pair<string, char>("...", 's'));
    morseCharacters.insert(pair<string, char>("-", 't'));
    morseCharacters.insert(pair<string, char>("..-", 'u'));
    morseCharacters.insert(pair<string, char>("...-", 'v'));
    morseCharacters.insert(pair<string, char>(".--", 'w'));
    morseCharacters.insert(pair<string, char>("-..-", 'x'));
    morseCharacters.insert(pair<string, char>("-.--", 'y'));
    morseCharacters.insert(pair<string, char>("--..", 'z'));
    morseCharacters.insert(pair<string, char>(".----", '1'));
    morseCharacters.insert(pair<string, char>("..---", '2'));
    morseCharacters.insert(pair<string, char>("...--", '3'));
    morseCharacters.insert(pair<string, char>("....-", '4'));
    morseCharacters.insert(pair<string, char>(".....", '5'));
    morseCharacters.insert(pair<string, char>("-....", '6'));
    morseCharacters.insert(pair<string, char>("--...", '7'));
    morseCharacters.insert(pair<string, char>("---..", '8'));
    morseCharacters.insert(pair<string, char>("----.", '9'));
    morseCharacters.insert(pair<string, char>("-----", '0'));

    return morseCharacters[morse];
}

// gets morse code from the user and decrypt it
void getInputAndDecipherC7(){

    string morse;

    cout << "Enter the morse code" << endl;

    getline(cin, morse);

    string morseCharacter = "";

    // morse code is separated by spaces
    // loop till finding a space and pass the morse code to the function
    for (char c : morse) {

        if (c == ' '){
            cout << decryptMorseC7(morseCharacter);
            morseCharacter = "";
        }else{
            morseCharacter += c;
        }

    }
    // decrypt the remaining morse character after the last space
    cout << decryptMorseC7(morseCharacter);

}

// get what the user needs to do
void getUserChoiceC7() {

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
            getInputAndCipherC7();

            // re-get the user coice
            getUserChoiceC7();
            break;

        case 2: // action #2
            getInputAndDecipherC7();

            // re-get the user coice
            getUserChoiceC7();
            break;

        case 3: // action #3
            // finishes the program
            exit(0);
    }

}


// End Cipher 7


// Start Cipher 8

int getCipherSecretKeyC8() {

    return (int)'P';

}

// declare the function, initialized later
void callDecryptionFromHexaC8();

// convert decimal values to hexa (one by one)
string decToHexC8(int num) {

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
int encryptC8(int num) {

    // not only XORing
    // discovered the added 96 values from the outputs of "Cipher and Calculator Description" algorithm 8
    return (num ^ getCipherSecretKeyC8()) + 96;

}

// returns a ciphered text to normal text by re-XORing the ciphered text
int decryptC8(int num) {

    // the opposite of the encrypt function
    return ((num - 96) ^ getCipherSecretKeyC8());

}

// used to decipher from hexa
void decipherFromHexaC8(string cipher) {

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

            // print the character of the corresponding hexa value
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
        callDecryptionFromHexaC8();
    }


}
// End
// Ciphering and deciphering


// contains code for action #1
void callEncryptionC8() {

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
        cipher += (char)encryptC8((int)userInput[i]);
    }

    // print the encrypted input (ciphered text)
    cout << cipher;

    cout << endl;

    // print the hexa representation
    for (int i = 0; i < userInput.length(); i++) {
        cout << decToHexC8((char)encryptC8((int)userInput[i]));
    }

}

// contains code for action #1
void callDecryptionC8() {

    string userInput = "";

    cout << "Enter message to decipher : ";
    cin >> userInput;

    string cipher = "";

    // decrypt the input
    for (int i = 0; i < userInput.length(); i++) {
        cipher += (char)decryptC8((int)userInput[i]);
    }

    // print the decrypted text (normal text)
    cout << cipher;

}

// contains code for action #1
void callDecryptionFromHexaC8() {

    string userInput = "";

    cout << "Enter message to decipher as hexa : ";
    cin >> userInput;

    decipherFromHexaC8(userInput);

}

// First-to-call function
void getUserChoiceC8() {

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
        callEncryptionC8();

        // re-get the user coice
        getUserChoiceC8();
        break;

    case 2: // action #2
        callDecryptionC8();

        // re-get the user coice
        getUserChoiceC8();
        break;

    case 3: // action #3
        callDecryptionFromHexaC8();

        // re-get the user coice
        getUserChoiceC8();
        break;

    case 4: // action #4
        // finishes the program
        exit(0);

    default:
        break;
    }


}

// End Cipher 8


// Start Cipher 9

// End Cipher 9


// MAIN input function
void getMainUserChoice(){

    int userChoice = 0;

    cout << "\n";
    cout << "Habibaaaay habiby habiby habiby." << endl << "What do you like to do ya expensive?" << endl;
    cout << "0 - Affine Cipher" << endl;
    cout << "1 - Caesar Cipher" << endl;
    cout << "2 - Atbash Cipher" << endl;
    cout << "3 - Vignere Cipher" << endl;
    cout << "4 - Baconian Cipher" << endl;
    cout << "5 - Simple Substitution Cipher" << endl;
    cout << "6 - Polybius Square Cipher" << endl;
    cout << "7 - Morse Code" << endl;
    cout << "8 - XOR Cipher" << endl;
    cout << "9 - Rail-fence Cipher" << endl;
    cout << "-1 - Exit" << endl;

    cin >> userChoice;

    switch (userChoice)
    {
        case 0:

            getInputC0();

            break;

        case 1:

            cipherC1();

            break;

        case 2:

            getUserChoiceC2();

            break;

        case 3:

            cipherC3();

            break;

        case 4:

            // add c4

            break;

        case 5:

            getUserChoiceC5();

            break;

        case 6:

            getUserChoiceC6();

            break;

        case 7:

            getUserChoiceC7();

            break;

        case 8:

            getUserChoiceC8();

            break;

        case 9:

            // add c4

            break;

        case -1:
            // finishes the program
            exit(0);

        default:
            break;
    }


}

int main() {

    // Call the main input function
    getMainUserChoice();

    return 0;
}
