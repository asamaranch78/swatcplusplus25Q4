#pragma once

#include <exception>

class EmptyArgumentException : std::exception
{
    public:
        EmptyArgumentException() = default;
        ~EmptyArgumentException() = default;

        virtual const char * what() const noexcept
        {
            return "Empty answer is not allowed, please try again.";
        }
};