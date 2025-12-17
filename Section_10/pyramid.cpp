/*
    Author: Juan M. Lagostena
    Nov 27, 2025
*/

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {

    string userInput{};
    string trimmedInput{};

    do {
        cout << "Enter your text (or enter to exit): ";
        getline(cin, userInput);

        if (userInput.empty()) {
            break;
        }

        // At this point, userInput can contain spaces.
        // We iterate to delete them.
        for (auto c: userInput) {
            if (c != ' ') {
                trimmedInput += c;
            }
        }

        // At this point, userInput has no spaces!!!
        string sPrint {};
        string tempStr {};
        string revPart {};

        int i {};
        for (auto c: trimmedInput) {
            /*
                Ej: ABC

                i   tempStr     spaceStr    revPart    sPrint
                0   A           __                      __A__
                1   AB          _           A           _ABA_
                2   ABC                     BA          ABCBA
            */            
            tempStr += c;
            revPart = (i > 0) ? tempStr.at(i - 1) + revPart : "";
            
            string spaceStr((trimmedInput.length() - tempStr.length()), ' ');
            sPrint = spaceStr + tempStr + revPart + spaceStr; 

            cout << sPrint << endl;
            ++i;
        }

    } while (true);

    cout << "Goodbye!" << endl << endl;

    return 0;
}
