#pragma once

#include <exception>

class InvalidOptionException : public std::exception
{
    public:
        InvalidOptionException() = default;
        ~InvalidOptionException() = default;

        virtual const char *what() const noexcept
        {
            return "Option invalid. Please, try again.";
        }        
};