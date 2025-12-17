// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::queue;
using std::stringstream;

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a stack and a queue to solve the problem.
    stringstream ss { s };
    string word {};

    stack<char> sChr;
    queue<char> qChr;

    if (s.size() == 1) return true;

    while (ss >> word)
    {
        for (auto c: word)
        {
            if (std::isalpha(c))
            {
                sChr.push(std::tolower(c));
                qChr.push(std::tolower(c));
            }
        }
    }

    while (!sChr.empty())
    {
        if (sChr.top() == qChr.front())
        {
            sChr.pop();
            qChr.pop();
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(10) << std::left << "Result" << std::setw(30) << std::right << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(10) << std::left << is_palindrome(s) << std::setw(30) << std::right << s << std::endl;
    }
    //std::cout << std::setw(10) << std::left << is_palindrome("Amore, Roma") << std::setw(30) << std::right << "Amore, Roma" << std::endl;
    
    std::cout << std::endl;
    return 0;
}