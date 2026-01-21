
#include <string>
#include <cctype>

std::string remove_whitespace(const std::string& input) {
    std::string out;
    out.reserve(input.size());

    for (unsigned char c : input) {
        if (!std::isspace(c)) {   // removes ' ', '\t', '\n', '\r', etc.
            out.push_back(c);
        }
    }
    return out;
}

