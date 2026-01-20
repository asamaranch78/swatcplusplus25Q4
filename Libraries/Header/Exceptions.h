#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <exception>

class IncorrectUserInputException : public std::exception {
public:
    IncorrectUserInputException() noexcept = default;
    ~IncorrectUserInputException() = default;
    virtual const char *what() const noexcept {
        return "Incorrect input selected by the user";
    }
};

class IncorrectStringException : public std::exception {
public:
    IncorrectStringException() noexcept = default;
    ~IncorrectStringException() = default;
    virtual const char *what() const noexcept {
        return " -> Incorrect char included in this string";
    }
};

class IncorrectIntegerException : public std::exception {
public:
    IncorrectIntegerException() noexcept = default;
    ~IncorrectIntegerException() = default;
    virtual const char *what() const noexcept {
        return " -> Incorrect Integer selected, it's out of the valid range";
    }
};

class InvalidReadFileDataException : public std::exception {
public:
    InvalidReadFileDataException() noexcept = default;
    ~InvalidReadFileDataException() = default;
    virtual const char *what() const noexcept {
        return "Read Data file contains invalid data";
    }
};

class InvalidWriteFileDataException : public std::exception {
public:
    InvalidWriteFileDataException() noexcept = default;
    ~InvalidWriteFileDataException() = default;
    virtual const char *what() const noexcept {
        return "Read Data file contains invalid data";
    }
};

#endif // __EXCEPTIONS_H__
