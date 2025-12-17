/*
    Author: Juan M. Lagostena
    Dec 17, 2025
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::set;

// Used for Part1
// Display the word and count from the 
// std::map<std::string, int>

void display_words(const map<string, int> &words) 
{
    cout << std::setw(12) << std::left << "\nWord"
                << std::setw(7) << std::right << "Count"<< std::endl;
    cout << "===================" << std::endl;
    for (auto pair: words)
        cout << std::setw(12) << std::left << pair.first 
                       << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurences from the 
// std::map<std::string, std::set<int>>

void display_words(const map<string, std::set<int>> &words)
{
     cout << std::setw(12) << std::left << "\nWord"
                << "Occurrences"<< std::endl;
    cout << "=====================================================================" << std::endl;
    for (auto pair: words) {
        cout << std::setw(12) << std::left << pair.first 
                       << std::left << "[ ";
        for (auto i: pair.second) 
            cout << i << " ";
        cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
string clean_string(const string &s) 
{
    string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file

void part1() 
{
    map<string, int> words;
    string line;       
    string word;   
    std::ifstream in_file {"words.txt"};

    if (in_file) 
    {
        while (in_file >> word)
        {
            words[clean_string(word)]++;
        }
        
        in_file.close();
        display_words(words);
    } 
    else 
    {
        std::cerr << "Error opening input file" << endl;
    }
}
    
// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2() 
{
    map<string, set<int>> words;
    string line;
    string word;
    std::ifstream in_file {"words.txt"};
    int lineNumber {};

    if (in_file) 
    {
        while (std::getline(in_file, line))
        {
            ++lineNumber;
            std::stringstream ss {line};

            while (ss >> word)
            {
                words[clean_string(word)].insert(lineNumber);
            }
        }
            
        in_file.close();
        display_words(words);
    } 
    else 
    {
        std::cerr << "Error opening input file" << endl;
    }
}

int main() 
{
    //part1();
    part2();

    return 0;
}

