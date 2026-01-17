#include <cstdint>
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

