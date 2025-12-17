
/*
    Author: Juan M Lagostena
    Dec 16, 2025
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::deque;

bool is_palindrome(const string &text)
{
    deque<char> d {};
    
    for (char c: text)
    {
        if (std::isalpha(c))
        {
            d.push_back(c);
        }
    }

    while (d.size() > 1)
    {
        char cFront = d.front();
        char cBack = d.back();

        d.pop_front();
        d.pop_back();

        if (cFront != cBack) 
        {
            return false;
        }
    }
            
    return true;
}
                   
int main()
{
    vector<string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
    
    cout << std::boolalpha;
    
    for (auto s: test_strings)
    {
        cout << std::setw(40) << std::right << s << " - Palindrome: " << std::setw(5) << std::right << is_palindrome(s) << endl;
    }
        
    return 0;
}