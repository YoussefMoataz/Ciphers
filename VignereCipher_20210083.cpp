////FCAI - Programming 1 - 2022 - Assignment 2
////Vignere Cipher
////Program Description: It takes a message from the user and cipher it if he chooses 1 and
////decipher it if he chooses 2.
////Lat Modification Date: 3/15/2022
////Author: Aya Ali Hassan
////ID: 20210083
////Group: A
////Teaching Assistant: Not yet
////Purpose: cipher and decipher messages.
//#include <iostream>
//#include<algorithm>
//using namespace std;
//int main() {
//    int unchanged,choice;
//    cout<<"-if you want to cipher a message choose 1"<<endl<<"-if you want to decipher a message choose 2"<<endl<<"-if you want to exit the program choose 3"<<endl;
//    while(choice != 3){
//        string message,keyword="",keyword2="",cipher,decipher;
//        int unchanged,choice;
//        cout<<"choice :"<<endl;
//        cin>>choice;
//        while(choice != 1 and choice != 2 and choice != 3){
//            cout<<"Please choose 1 or 2 :"<<endl;
//            cin>>choice;
//        }
//        if (choice == 1) {
//            cout << "Enter your message :" << endl;
//            getline(cin >> ws, message, '\n');
//            while (message.length() > 80) {
//                cout << "Please enter another message its length is less than 80 :" << endl;
//                getline(cin >> ws, message, '\n');
//            }
//            cout << "Enter the keyword :" << endl;
//            cin >> keyword;
//            while (keyword.length() > 8) {
//                cout << "Please enter another keyword its length is less than 8 :" << endl;
//                getline(cin >> ws, keyword, '\n');
//            }
//            while (keyword.length() < message.length()) {
//                keyword += keyword;
//            }
//            for (int j = 0; j < message.length(); j++) {
//                keyword2 += keyword[j];
//            }
//            for (int i = 0; i < message.length(); i++) {
//                cipher += (((int(toupper(message[i])) + int(toupper(keyword[i]))) % 26) + 65);
//                if (isspace(message[i]) or isdigit(message[i]) or ispunct(message[i])) {
//                    unchanged = i;
//                    cipher[i] = char(message[unchanged]);
//                }
//            }
//            cout << "the ciphered message :" <<endl<< cipher<<endl;
//        } else if(choice ==2) {
//            cout << "Enter your deciphered message :" << endl;
//            getline(cin >> ws, message, '\n');
//            while (message.length() > 80) {
//                cout << "Please enter another message its length is less than 80 :" << endl;
//                getline(cin >> ws, message, '\n');
//            }
//            cout << "Enter the keyword :" << endl;
//            cin >> keyword;
//            while (keyword.length() > 8) {
//                cout << "Please enter another keyword its length is less than 8 :" << endl;
//                getline(cin >> ws, keyword, '\n');
//            }
//            while (keyword.length() < message.length()) {
//                keyword += keyword;
//            }
//            for (int j = 0; j < message.length(); j++) {
//                keyword2 += keyword[j];
//            }
//            for (int h = 0; h < keyword2.length(); h++) {
//                if (isspace(message[h]) or isdigit(message[h]) or ispunct(message[h])) {
//                    unchanged = h;
//                    decipher += char(message[unchanged]);
//                }
//                for (int i = 65; i <= 90; i++) {
//                    if ((((i + toupper(keyword2[h])) % 26) + 65) == toupper(message[h])) {
//                        decipher += char(i);
//                    }
//                }
//            }
//            cout << "the deciphered message :" <<endl<< decipher<<endl;
//        }}
//    return 0;
//}
//
