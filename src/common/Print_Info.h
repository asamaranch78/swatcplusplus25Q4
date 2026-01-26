#ifndef _PRINT_INFO_H_
#define _PRINT_INFO_H_
#include <iostream>

class Print_Info
{
    friend std::ostream &operator<<(std::ostream &os, const Print_Info &obj);
public:
    virtual void info(std::ostream &os) const = 0;
    virtual ~Print_Info() = default;
};

#endif // _PRINT_INFO_H_