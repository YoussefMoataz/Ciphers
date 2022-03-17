#include <iostream>
#include <string>

using namespace std;

char characters [5][5] = { {'a', 'b', 'c', 'd', 'e'},
                           {'f', 'g', 'h', 'i', 'k'},
                           {'l', 'm', 'n', 'o', 'p'},
                           {'q', 'r', 's', 't', 'u'},
                           {'v', 'w', 'x', 'y', 'z'}};

int main() {

    int key [] = {5, 1, 4, 2, 3};

    string message = "code";

    int counter = 0;

    for (char c : message) {
        for (int i = 0; i < 5; i++) {

            for (int j = 0; j < 5; j++) {

                if (c == characters[i][j]) {
                    cout << key[i] << key[j];
                    counter++;
                }

            }

        }
    }
    return 0;
}
