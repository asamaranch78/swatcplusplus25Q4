#include <iostream>
#include <iomanip>

#include "vehicle.h"
#include "constants.h"

void Vehicle::info(void) {
    std::cout << std::left;
    std::cout << std::setw(WIDE_GAP) << manufacturer;
    std::cout << std::setw(GAP) << model;
    std::cout << std::setw(GAP) << year;
    std::cout << std::setw(GAP) << weight;
    std::cout << std::setw(WIDE_GAP) << fuelEfficiency;
    
    switch (fuelType) {
        case FuelTypes::DIESEL:
            std::cout << std::setw(WIDE_GAP) << "Diesel";
            break;
        case FuelTypes::ELECTRIC:
            std::cout << std::setw(WIDE_GAP) << "Electric";
            break;
        case FuelTypes::GASOLINE:
            std::cout << std::setw(WIDE_GAP) << "Gasoline";
            break;
    }
}

void Vehicle::askUserData(void) {
    fuelEfficiency = 0.0;
    std::cout << "What is the manufacturer? ";
    std::cin >> manufacturer;
    std::cout << "What is the model? ";
    std::cin >> model;
    std::cout << "What year? ";
    std::cin >> year;
    std::cout << "What is the weight? ";
    std::cin >> weight; 
}


