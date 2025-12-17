#pragma once

#include <exception>

class InsufficientFundsException : public std::exception
{
    public:
        InsufficientFundsException() = default;
        ~InsufficientFundsException() = default;

        virtual const char *what() const noexcept
        {
            return "Insufficient funds exception";
        }
};

