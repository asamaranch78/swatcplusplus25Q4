/*
    Author: Juan M Lagostena
    Dec 15, 2025
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;

int main()
{
    std::ifstream in_file {"romeoandjuliet.txt"};

    if (!in_file)
    {
        cerr << " Unable to open the input file" << endl;
        return -1;
    }

    std::ofstream out_file("copied_file.txt");

    if (!out_file)
    {
        in_file.close();

        cerr << " Unable to create the output file" << endl;
        return -2;
    }

    string iLine {};
    int nLines {};
    // Allows one or more empty lines together. emptyLines < 1 ensures there's only one empty line, < 2 ensures 2 empty lines and so forth...
    int emptyLines {};

    while (std::getline(in_file, iLine))
    {
        if (!iLine.empty())
        {
            ++nLines;
            out_file << std::setw(5) << std::right << nLines << "  ";

            emptyLines = 0;
        }
        
        if (emptyLines < 1)
        {
            out_file << iLine << endl;
            emptyLines = (iLine.empty()) ? emptyLines + 1 : emptyLines;
        }
    }

    // DO NOT FORGET!!!
    in_file.close();
    out_file.close();

    return 0;
}