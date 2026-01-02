#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H__
#define __INSUFFICIENT_FUNDS_EXCEPTION_H__
#include <exception>

class InsufficientFundsException: public std::exception
{
public:
    InsufficientFundsException() = default;
    ~InsufficientFundsException() = default;
    const char* what() const noexcept override {
        return "Not Enough money in the account";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
