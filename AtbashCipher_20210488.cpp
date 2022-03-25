///*
//
//FCAI - Programming 1 - 2022 - Assignment 2
//Program Name: AtbashCipher_20210488.cpp
//Program Description: This program ciphers and deciphers messages by replacing characters (A -> Z), (B -> Y)
//
//Last Modification Date: March 19, 2022
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
//#include <cstring>
//
//using namespace std;
//
//// ---DO NOT CHANGE--- alphabet characters and reversed
//static char *const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//static char *const alphabetReversed = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
//// ---DO NOT CHANGE---
//
//// get index of character in char array , string
//int indexOf(char arr[], char character) {
//
//    for (int i = 0; i < strlen(arr); i++) {
//
//        if (character == arr[i]) {
//            return i;
//        }
//
//    }
//
//    return 0;
//}
//
//void getInputAndCipher(){
//
//    string message;
//
//    cout << "Enter the message :" << endl;
//
//    // get message
//    getline(cin, message);
//
//    // Encryption goes here
//    for(int i = 0; i < message.length(); i++){
//
//        // print spaces as is
//        if (isspace(message[i])){
//            cout << " ";
//
//        // print the character by getting its index from the alphabet and using the index in the reverse alphabet
//        // convert to upper case
//        }else{
//            cout << alphabetReversed[indexOf(alphabet, toupper(message[i]))];
//        }
//
//    }
//
//}
//
//void getInputAndDecipher(){
//
//    string message;
//
//    cout << "Enter the cipher :" << endl;
//
//    // get message
//    getline(cin, message);
//
//    // Decryption goes here
//    for(int i = 0; i < message.length(); i++){
//
//        // print spaces as is
//        if (isspace(message[i])){
//            cout << " ";
//
//        // print the character by getting its index from the reversed alphabet and using the index in the alphabet
//        // convert to upper case
//        }else{
//            cout << alphabet[indexOf(alphabetReversed, toupper(message[i]))];
//        }
//
//    }
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
//int main(){
//
//    getUserChoice();
//
//    return 0;
//}