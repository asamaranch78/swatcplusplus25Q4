#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__
#include <exception>

class IllegalBalanceException: public std::exception
{
public:
    IllegalBalanceException() {}
    ~IllegalBalanceException() {}
    const char* what() const noexcept override {
        return "Balance must be a positive integer";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
