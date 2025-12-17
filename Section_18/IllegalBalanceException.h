#pragma once

#include <exception>

class IllegalBalanceException : public std::exception
{
    public:
        IllegalBalanceException() = default;
        ~IllegalBalanceException() = default;

        virtual const char *what() const noexcept
        {
            return "Illegal balance exception";
        }
};