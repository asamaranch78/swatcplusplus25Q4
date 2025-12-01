#include <iostream>
#include <string>

using namespace std;

int main (void) {
    string input {};
    string subInput {};
    string mirror {};
    char letter {};
    cout << "Input a string to build the pyramid:";
    cin >> input;

    for (size_t i=0; i < input.length(); i++) {
        for (size_t j=0; j < input.length() - i; j++) {
            cout << " ";
        }
        subInput = input.substr(0,i+1);
        for (size_t j=0; j < subInput.length(); j++) {
            letter = subInput.at(j);
            if (j < subInput.length()-1) { mirror = letter + mirror;}
            cout << letter;
            
        }
        cout << mirror;
        mirror.clear();
        cout << endl;
    }

    return 0;
}
