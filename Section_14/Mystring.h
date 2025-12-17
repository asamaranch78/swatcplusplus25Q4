#pragma once

class Mystring
{
    // Friends
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &is, Mystring &rhs);

    private:
        char *str;

    public:
        // Constructors
        Mystring();
        Mystring(const char *s);
        
        // Destructor
        ~Mystring();
        
        // Copy constructor
        Mystring(const Mystring &source);

        // Copy assignment
        Mystring &operator=(const Mystring &rhs);

        // Move assignment
        Mystring &operator=(Mystring &&rhs);

        // Operator - overload as member function
        Mystring operator-() const;

        // Operator + overload as member function
        Mystring operator+(const Mystring &rhs) const;

        // Operator += overload as member function
        Mystring operator+=(const Mystring &rhs);

        // Operator == overload as member function
        bool operator==(const Mystring &rhs) const;

        // Operator != overload as member function
        bool operator!=(const Mystring &rhs) const;

        // Operator < overload as member function
        bool operator<(const Mystring &rhs) const;

        // Operator > overload as member function
        bool operator>(const Mystring &rhs) const;

        // Operator * overload as member function
        Mystring operator*(int n);

        // Operator *= overload as member function
        Mystring operator*=(int n);

        // Operator ++ pre-increment overload as member function
        Mystring &operator++();

        // Operator ++ post-increment overload as member function
        Mystring operator++(int n);
};