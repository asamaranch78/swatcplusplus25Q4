// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    //Add parameters to a deque
    std::deque<char> d;

    for(char c : s) {
        char upperC = std::toupper(c);
        if(std::isalpha(upperC)) { d.push_back(upperC); }
    }

    char d1, d2;

    // Go from the front and the back comparing thery are equal
    while (d.size() > 1) {
        d1 = d.front();
        d2 = d.back();
        if (d1 != d2) { return false; }
        d.pop_back();
        d.pop_front();
    }
    
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
