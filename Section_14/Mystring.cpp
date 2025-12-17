#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} 
{
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr}     
{
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Destructor
Mystring::~Mystring() 
{
    delete [] str;
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
: str {nullptr} 
{

    str = new char[strlen(source.str) + 1];
    std::strcpy(this->str, source.str);
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) 
{
    if (this == &rhs) {
        return *this;
    }

    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);

    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) 
{

    if (this == &rhs) {
        return *this;
    }

    delete [] this->str;
    this->str = rhs.str;

    rhs.str = nullptr;

    return *this;
}

// Operator - member function
Mystring Mystring::operator-() const 
{
    char *buff = new char[std::strlen(this->str) + 1];
    std::strcpy(buff, this->str);

    for (size_t i {0}; i < std::strlen(buff); ++i) {
        buff[i] = std::tolower(buff[i]);
    }

    Mystring temp {buff};
    delete [] buff;

    return temp;
}

// Operator + member function
Mystring Mystring::operator+(const Mystring &rhs) const 
{
    char *buff = new char[strlen(this->str) + strlen(rhs.str) + 1];
    std::strcpy(buff, this->str);
    std::strcat(buff, rhs.str);
    
    Mystring temp {buff};
    delete [] buff;

    return temp;
}

// Operator += member function
Mystring Mystring::operator+=(const Mystring &rhs)
{
    *this = *this + rhs;
    return *this;
}

// Operator == member function
bool Mystring::operator==(const Mystring &rhs) const 
{
    return (std::strcmp(this->str, rhs.str) == 0);
}

// Operator != member function
bool Mystring::operator!=(const Mystring &rhs) const
{
    return (std::strcmp(this->str, rhs.str) != 0);
}

// Operator < member function
bool Mystring::operator<(const Mystring &rhs) const
{
    return (std::strcmp(this->str, rhs.str) < 0);
}

// Operator > member function
bool Mystring::operator>(const Mystring &rhs) const
{
    return (std::strcmp(this->str, rhs.str) > 0);
}

// Operator * member function
Mystring Mystring::operator*(int n) 
{
    Mystring temp;

    for (int i {0}; i <= n; ++i)
    {
        temp = temp + *this;
    }

    return temp;
}

// Operator *= member function
Mystring Mystring::operator*=(int n)
{
    *this = *this * n;
    return *this;
}

// Operator ++ pre-increment member function
Mystring &Mystring::operator++()
{
    for (size_t i {0}; i < strlen(this->str); ++i)
    {
        this->str[i] = std::toupper(this->str[i]);
    }

    return *this;
}

// Operator ++ post-increment member function
Mystring Mystring::operator++(int n)
{
    Mystring temp {*this};
    operator++();

    return temp;
}

// Insertion operator overload (not a member function)
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) 
{
    os << rhs.str;
    return os;
}

// Extraction operator overload (not a member function)
std::istream &operator>>(std::istream &is, Mystring &rhs)
{
    is >> rhs.str;
    return is;
}