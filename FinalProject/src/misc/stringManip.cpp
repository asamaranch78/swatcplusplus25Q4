#include "stringManip.h"
#include <cctype>

std::string remove_whitespace(const std::string input) {
    std::string out;

    for (unsigned char c : input) {
        if (!std::isspace(c)) {   // removes ' ', '\t', '\n', '\r', etc.
            out.push_back(c);
        }
    }
    return out;
}

void rtrim_in_place(std::string& s) {
    while (!s.empty() && (s.back() == ' ' || s.back() == '\t' ||
                          s.back() == '\n' || s.back() == '\r' ||
                          s.back() == '\f' || s.back() == '\v' || s.back() == '\0')) {
        s.pop_back();
    }
}

void ltrim_in_place(std::string& s) {
    size_t i = 0;
    while (i < s.size() && (s[i] == ' ' || s[i] == '\t' ||
                            s[i] == '\n' || s[i] == '\r' ||
                            s[i] == '\f' || s[i] == '\v')) {
        ++i;
    }
    if (i) s.erase(0, i);
}

std::string trim(std::string s) {
    rtrim_in_place(s);
    ltrim_in_place(s);
    return s;
}


void normalize_newlines(std::string& s) {
    std::string out;
    out.reserve(s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '\r') {
            if (i + 1 < s.size() && s[i+1] == '\n') ++i; // skip the \n after \r
            out.push_back('\n');
        } else {
            out.push_back(s[i]);
        }
    }
    s.swap(out);
}


bool equal(std::string a, std::string b) {
    rtrim_in_place(a);
    ltrim_in_place(a);
    rtrim_in_place(b);
    ltrim_in_place(b);
    normalize_newlines(a);
    normalize_newlines(b);
    return  a == b;
}

std::string cleanUp(std::string s) {
    rtrim_in_place(s);
    ltrim_in_place(s);
    normalize_newlines(s);
    return s;
}

