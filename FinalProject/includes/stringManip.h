#ifndef __STRING_MANIP_H__
#define __STRING_MANIP_H__

#include <string>

std::string remove_whitespace(const std::string input);
void rtrim_in_place(std::string& s);
void ltrim_in_place(std::string& s);
std::string trim(std::string s);
void normalize_newlines(std::string& s);
bool equal(std::string a, std::string b);
std::string cleanUp(std::string s);

#endif
