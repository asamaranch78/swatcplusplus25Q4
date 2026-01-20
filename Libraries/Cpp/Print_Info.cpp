#include <iostream>
#include "Print_Info.h"

std::ostream &operator<<(std::ostream &os, const Print_Info &obj){
    obj.info(os);
    return os;
}