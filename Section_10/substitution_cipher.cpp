/*
    Author: Juan M. Lagostena
    Nov 27, 2025
*/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {

    const string src {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.,:;!?-$0123456789"};
    const string key {"Q?AzplWs6xJOkTm8E;dCIjNRyfvuSHbtg92!Pq4XowieU$:rY5LaKDhFGMnZcV17,0-.3B"};

    string userMessage {};
    string encryptedMessage {};
    string decryptedMessage {};
    
    do {
        
        if (key.length() != src.length()) {
            cout << "ERROR: Strings are not equal! key: " << key.length() << ", src: " << src.length() << endl << endl;
            break;
        }

        cout << "=========== Messages encrypter ===========" << endl << endl;
        cout << "Enter your message (or enter to quit): ";
        getline(cin, userMessage);

        if (userMessage.empty()) {
            cout << "Goodbye!" << endl << endl;
            cout << "==========================================" << endl << endl;

            break;
        }

        cout << endl;
        cout << "Encrypting message... " << endl << endl;

        for (auto i = 0; i < userMessage.length(); ++i) {

            if (userMessage.at(i) == ' ') {
                encryptedMessage += ' ';
            } else {
                auto cIndex = src.find(userMessage.at(i));
                encryptedMessage += key.at(cIndex);
            }

        }

        cout << "Encrypted message: " << encryptedMessage << endl << endl;
        cout << "Decrypting message... " << endl << endl;

        for (auto i = 0; i < encryptedMessage.length(); ++i) {

            if (encryptedMessage.at(i) == ' ') {
                decryptedMessage += ' ';
            } else {
                auto cIndex = key.find(encryptedMessage.at(i));
                decryptedMessage += src.at(cIndex);
            }

        }
        
        cout << "Decrypted message: " << decryptedMessage << endl << endl;

        cout << "==========================================" << endl;

        userMessage.clear();
        encryptedMessage.clear();
        decryptedMessage.clear();

    } while (true);

}