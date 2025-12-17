/*
    Author: Juan M Lagostena
    Dec 12, 2025
*/

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;

string user_word() 
{
    string w {};

    cout << " Enter a word to search: ";
    cin >> w;

    return w;
}

bool find_substring(const std::string &word_to_find, const std::string &target) {
    std::size_t found = target.find(word_to_find);
    return (found != std::string::npos);
}

int main()
{
    string word {};

    std::ifstream target_file {"romeoandjuliet.txt"};

    if (!target_file)
    {
        cerr << " File not found." << endl;
        
        return -1;
    }

    cout << "==========================" << endl;
    word = user_word();

    if (word.empty())
    {
        cout << " No word to search for" << endl;
        cout << "==========================" << endl;
        
        return -2;
    }

    string fLine {};

    int nWords {};
    int timesFound {};

    timesFound = 0;
    size_t lPos {};

    // Read a word
    while (target_file >> fLine)
    {
        if (find_substring(word, fLine)) {
           ++timesFound;
        }

        ++nWords;
    }

    // DO NOT FORGET!!!
    target_file.close();

    cout << " File contains '" << word << "' " << timesFound << " times" << endl;
    cout << " Words in file: " << nWords << endl;
    cout << "==========================" << endl;

    return 0;
}