//// FCAI - Programming 1 - 2022 - Assignment 2
//// Program name: CeaserCipher.cpp
//// Program Description: encrypt a message alphabetic letters only with respect to a certain shift key and reserves spaces.
//// Last Modification Date: 15/3/2022
//// Author: Hend Ahmed Kamal
//// ID: 20211111
//// Group: A
//
//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//    string word;
//    int secret_shift;
//    int n;
//    int button;
//    int size = word.size();
//    cout << "Welcome to Encryption Program !" << endl;
//    cout << "Press '1' to encrypt your message || press '-1' to decrypt your message:";
//    cin >> button;
//    cout << "Press '0' if your message is lowercase || Press '1' if your message is uppercase:" << endl;
//    cin >> n;
//    cout << "Please enter the secret shift key: " << endl;
//    cin >> secret_shift;
//    cout << "Please enter your message: " << endl;
//    cin.clear();
//    cin.sync();
//    getline(cin, word);
//
//    if (secret_shift < 0)
//        secret_shift = ((secret_shift % 26) + 26) % 26;
//    else
//        secret_shift = secret_shift;
//
//    // Encrypting message
//    if (button == 1) {
//        for (int i = 0; word[i] != '\0'; i++) {    // loop until the string is over
//            char chr = word[i];
//            // lowercase encryption
//            if (n == 0) {
//                if (chr >= 'a' && chr <= 'z') {
//                    chr = chr + secret_shift;
//                    if (chr > 'z') {
//                        chr = chr - 'z' + 'a' - 1;
//                    }
//                    word[i] = chr;
//                }
//            }
//                // uppercase encryption
//            else if (n == 1) {
//                 if (chr >= 'A' && chr <= 'Z') {
//                     chr = chr + secret_shift;
//                     if (chr > 'Z') {
//                         chr = chr - 'Z' + 'A' - 1;
//                     }
//                        word[i] = chr;
//                    }
//                }
//        }
//        cout << "Encrypted message = " << word << endl;
//    }
//        // Decrypting message
//    else if (button == -1) {
//        for (int i = 0; word[i] != '\0'; i++) {    // loop until the string is over
//            char chr = word[i];
//            // lowercase decryption
//            if (n == 0) {
//                if (chr >= 'a' && chr <= 'z') {
//                    chr = chr - secret_shift;
//                    if (chr < 'a') {
//                        chr = chr + 'z' - 'a' + 1;
//                    }
//                    word[i] = chr;
//                }
//            }
//            // uppercase decryption
//            else if (n == 1) {
//                if (chr >= 'A' && chr <= 'Z') {
//                    chr = chr - secret_shift;
//                    if (chr < 'A') {
//                        chr = chr + 'Z' - 'A' +1;
//                    }
//                    word[i] = chr;
//                }
//            }
//        }
//        cout << "Decrypted message = " << word << endl;
//    }
//}