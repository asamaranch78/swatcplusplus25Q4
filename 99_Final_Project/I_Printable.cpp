#include <iostream>

#include "I_Printable.h"

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
    obj.get_info(os);
    return os;
}