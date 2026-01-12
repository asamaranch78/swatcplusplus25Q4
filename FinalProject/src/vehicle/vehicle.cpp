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
    
}

std::string Vehicle::getFuelType(void) {
    switch (fuelType) {
        case FuelTypes::DIESEL:
            return "Diesel";
        case FuelTypes::ELECTRIC:
            return "Electric";
        case FuelTypes::GASOLINE:
            return "Gasoline";
    }
    return "Unknown";
}

std::string Vehicle::getType(void) {
    switch (type) {
        case Types::CAR:
            return "Car";
        case Types::ELECTRIC_CAR:
            return "Electric Car";
        case Types::MOTORBIKE:
            return "Motorbike";
        case Types::TRUCK:
            return "Truck";
    }
    return "Unknown";
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
