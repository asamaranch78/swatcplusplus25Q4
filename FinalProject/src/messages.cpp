#include "constants.h"
#include <iostream>
#include <iomanip>

void printListHeader(void) {
    std::cout << std::left;
    std::cout << std::setw(SHORT_GAP) << "i";
    std::cout << std::setw(WIDE_GAP) << "Manufacturer";
    std::cout << std::setw(GAP) << "Model";
    std::cout << std::setw(GAP) << "Year";
    std::cout << std::setw(GAP) << "Weight";
    std::cout << std::setw(WIDE_GAP) << "Fuel Effi.";
    std::cout << std::setw(WIDE_GAP) << "Fuel Type";
    std::cout << std::setw(GAP) << "Type";
    std::cout << std::setw(GAP) << "Special";
    std::cout << std::endl;
}
