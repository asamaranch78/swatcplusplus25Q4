#include <iostream>
#include "Movie.h"

void Movie::display() const {
    std::cout << name << ", " << peggy << ", " << watched << std::endl;
}