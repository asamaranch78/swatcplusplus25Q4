#include <cstdint>
#include <iostream>
#include <iomanip>

#include "vehicle.h"
#include "constants.h"
#include "messages.h"

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

void Vehicle::askUserData(Msg *msg) {
    fuelEfficiency = 0.0;
    std::cout << msg->askManufacturer;
    std::cin >> manufacturer;
    std::cout << msg->askModel;
    std::cin >> model;
    std::cout << msg->askYear;
    std::cin >> year;
    std::cout << msg->askWeight2;
    std::cin >> weight; 
}

FuelTypes Vehicle::askFuelType(Msg *msg) {
    uint16_t userInput;

    printMessage(&(msg->menuFuelTypeSelection));
    std::cin >> userInput;

    switch (userInput) {
        case 1:
            return FuelTypes::DIESEL;
        case 2:
            return FuelTypes::GASOLINE;
        default:
            std::cout << "Bad selection";
            return FuelTypes::DIESEL;
    }
}
