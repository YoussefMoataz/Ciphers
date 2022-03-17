///*
//
//FCAI - Programming 1 - 2022 - Assignment 2
//Program Name: MorseCode_20210488.cpp
//Program Description: This program ciphers and deciphers messages to and from morse code ( dots and dashes )
//
//Last Modification Date: March 16, 2022
//Version: v1.0.0
//Author: Youssef Moataz
//ID: 20210488
//Group: A
//Teaching Assistant: Not Yet
//Purpose: Cipher and Decipher messages
//
//*/
//
//#include <iostream>
//#include <map>
//using namespace std;
//
//// this function is used to encrypt a character/digit and return its morse representation
//string encryptMorse(char input) {
//
//    // define the character-morse representation
//    switch (input) {
//        case 'a':
//            return ".-";
//        case 'b':
//            return "-...";
//        case 'c':
//            return "-.-.";
//        case 'd':
//            return "-..";
//        case 'e':
//            return ".";
//        case 'f':
//            return "..-.";
//        case 'g':
//            return "--.";
//        case 'h':
//            return "....";
//        case 'i':
//            return "..";
//        case 'j':
//            return ".---";
//        case 'k':
//            return "-.-";
//        case 'l':
//            return ".-..";
//        case 'm':
//            return "--";
//        case 'n':
//            return "-.";
//        case 'o':
//            return "---";
//        case 'p':
//            return ".--.";
//        case 'q':
//            return "--.-";
//        case 'r':
//            return ".-.";
//        case 's':
//            return "...";
//        case 't':
//            return "-";
//        case 'u':
//            return "..-";
//        case 'v':
//            return "...-";
//        case 'w':
//            return ".--";
//        case 'x':
//            return "-..-";
//        case 'y':
//            return "-.--";
//        case 'z':
//            return "--..";
//        case '1':
//            return ".----";
//        case '2':
//            return "..---";
//        case '3':
//            return "...--";
//        case '4':
//            return "....-";
//        case '5':
//            return ".....";
//        case '6':
//            return "-....";
//        case '7':
//            return "--...";
//        case '8':
//            return "---..";
//        case '9':
//            return "----.";
//        case '0':
//            return "-----";
//        default:
//            return " ";
//    }
//}
//
//// get message from user and encrypt it
//void getInputAndCipher(){
//    string text;
//
//    cout << "Enter the message" << endl;
//
//    getline(cin, text);
//
//    // loop over the characters of the message and encrypt each character then print it
//    for (char i : text) {
//
//        cout << encryptMorse(tolower(i)) << " ";
//
//    }
//
//}
//
//// this function is used to decrypt a morse character and returns a character/digit
//char decryptMorse(string morse) {
//
//    map<string, char> morseCharacters;
//
//    // define the morse-character representation
//    morseCharacters.insert(pair<string, char>(".-", 'a'));
//    morseCharacters.insert(pair<string, char>("-...", 'b'));
//    morseCharacters.insert(pair<string, char>("-.-.", 'c'));
//    morseCharacters.insert(pair<string, char>("-..", 'd'));
//    morseCharacters.insert(pair<string, char>(".", 'e'));
//    morseCharacters.insert(pair<string, char>("..-.", 'f'));
//    morseCharacters.insert(pair<string, char>("--.", 'g'));
//    morseCharacters.insert(pair<string, char>("....", 'h'));
//    morseCharacters.insert(pair<string, char>("..", 'i'));
//    morseCharacters.insert(pair<string, char>(".---", 'j'));
//    morseCharacters.insert(pair<string, char>("-.-", 'k'));
//    morseCharacters.insert(pair<string, char>(".-..", 'l'));
//    morseCharacters.insert(pair<string, char>("--", 'm'));
//    morseCharacters.insert(pair<string, char>("-.", 'n'));
//    morseCharacters.insert(pair<string, char>("---", 'o'));
//    morseCharacters.insert(pair<string, char>(".--.", 'p'));
//    morseCharacters.insert(pair<string, char>("--.-", 'q'));
//    morseCharacters.insert(pair<string, char>(".-.", 'r'));
//    morseCharacters.insert(pair<string, char>("...", 's'));
//    morseCharacters.insert(pair<string, char>("-", 't'));
//    morseCharacters.insert(pair<string, char>("..-", 'u'));
//    morseCharacters.insert(pair<string, char>("...-", 'v'));
//    morseCharacters.insert(pair<string, char>(".--", 'w'));
//    morseCharacters.insert(pair<string, char>("-..-", 'x'));
//    morseCharacters.insert(pair<string, char>("-.--", 'y'));
//    morseCharacters.insert(pair<string, char>("--..", 'z'));
//    morseCharacters.insert(pair<string, char>(".----", '1'));
//    morseCharacters.insert(pair<string, char>("..---", '2'));
//    morseCharacters.insert(pair<string, char>("...--", '3'));
//    morseCharacters.insert(pair<string, char>("....-", '4'));
//    morseCharacters.insert(pair<string, char>(".....", '5'));
//    morseCharacters.insert(pair<string, char>("-....", '6'));
//    morseCharacters.insert(pair<string, char>("--...", '7'));
//    morseCharacters.insert(pair<string, char>("---..", '8'));
//    morseCharacters.insert(pair<string, char>("----.", '9'));
//    morseCharacters.insert(pair<string, char>("-----", '0'));
//
//    return morseCharacters[morse];
//}
//
//// gets morse code from the user and decrypt it
//void getInputAndDecipher(){
//
//    string morse;
//
//    cout << "Enter the morse code" << endl;
//
//    getline(cin, morse);
//
//    string morseCharacter = "";
//
//    // morse code is separated by spaces
//    // loop till finding a space and pass the morse code to the function
//    for (char c : morse) {
//
//        if (c == ' '){
//            cout << decryptMorse(morseCharacter);
//            morseCharacter = "";
//        }else{
//            morseCharacter += c;
//        }
//
//    }
//    // decrypt the remaining morse character after the last space
//    cout << decryptMorse(morseCharacter);
//
//}
//
//// get what the user needs to do
//void getUserChoice() {
//
//    int userChoice = 0;
//
//    cout << "\n\n";
//    cout << "Ahlan ya user ya habibi." << endl << "What do you like to do today ?" << endl;
//    cout << "1 - Cipher a message" << endl;
//    cout << "2 - Decipher a message" << endl;
//    cout << "3 - End" << endl;
//
//    cin >> userChoice;
//
//    cin.ignore();
//
//    switch (userChoice) {
//        case 1: // action #1
//            getInputAndCipher();
//
//            // re-get the user coice
//            getUserChoice();
//            break;
//
//        case 2: // action #2
//            getInputAndDecipher();
//
//            // re-get the user coice
//            getUserChoice();
//            break;
//
//        case 3: // action #3
//            // finishes the program
//            exit(0);
//    }
//
//}
//
//int main() {
//
//    getUserChoice();
//
//    return 0;
//}