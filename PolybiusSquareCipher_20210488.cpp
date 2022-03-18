
#include <iostream>
#include <string>

using namespace std;

char characters[5][5] = {{'a', 'b', 'c', 'd', 'e'},
                         {'f', 'g', 'h', 'i', 'k'},
                         {'l', 'm', 'n', 'o', 'p'},
                         {'q', 'r', 's', 't', 'u'},
                         {'v', 'w', 'x', 'y', 'z'}};

int indexOf(int x[], char digit) {

    for (int i = 0; i < 5; i++) {

        if (digit == x[i]) {
            return i;
        }

    }

}

string inputKeyAndCheckDigits(){

    string key;
    bool valid = true;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;

    cout << "Enter the secret key";

    getline(cin, key);

    if (key.length() == 5) {

        for (char d: key) {

            if (!isdigit(d)) {
                valid = false;
                break;
            }

            if (d == '1'){
                count1++;
            }else if(d == '2'){
                count2++;
            }else if(d == '3'){
                count3++;
            }else if(d == '4'){
                count4++;
            }else if(d == '5'){
                count5++;
            }

        }

        if ((count1 != 1) || (count2 != 1) || (count3 != 1) || (count4 != 1) || (count5 != 1)){
            valid = false;
        }

        if (!valid){
            inputKeyAndCheckDigits();
        }else{
            return key;
        }

    }else{
        inputKeyAndCheckDigits();
    }

}

void getInputAndCipher() {

    // start key

    int secretKey[5];

    string key = inputKeyAndCheckDigits();

    for (int i = 0; i < 5; ++i) {

        secretKey[i] = stoi(to_string(key[i]));

    }

    // end key

    string message;

    cout << "Enter the message:" << endl;

    getline(cin, message);

    int counter = 0;

    for (int i = 0; i < message.length(); i++) {

        message[i] = tolower(message[i]);

        if (message[i] == 'j'){
            message[i] = 'i';
        }

    }

    for (char c: message) {

        for (int i = 0; i < 5; i++) {

            for (int j = 0; j < 5; j++) {

                if (c == characters[i][j]) {
                    cout << key[i] << key[j];
                    counter++;
                }
            }

        }

        if (isspace(c)) {
            cout << c;
            counter++;
        }

    }

}

void getInputAndDecipher() {

    // start key

    int secretKey[5];
    string key = inputKeyAndCheckDigits();

    for (int i = 0; i < 5; ++i) {

        secretKey[i] = stoi(to_string(key[i]));

    }

    // end key

    string cipher;

    cout << "Enter the cipher text:" << endl;

    getline(cin, cipher);

    int pairCounter = 0;
    char codePair[] = " ";

    // split the string after two characters
    for (int i = 0; i < cipher.length(); i++) {

        if (isspace(cipher[i])) {

            cout << " ";
            continue;

        }

        // hexaPair contains two characters only
        if (pairCounter < 2) {
            codePair[pairCounter] = cipher[i];
            pairCounter += 1;
        }

        // print the character of the corresonding hexa value
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
