#include <iostream>
#include <iomanip>

#include "car.h"
#include "vehicle.h"
#include "constants.h"

void Car::info(void) {
    Vehicle::info();
    std::cout << std::setw(GAP) << "Car";
    std::cout << "Doors: " << doors;
    std::cout << "\t";
    std::cout << "Trunk Capacity: " << trunkCapacity;
    std::cout << std::endl;
}

void Car::fuelEfficiencyCalc(void) {
    return;
}

void Car::saveToFile(void) {
    return;
}

void Car::askUserData(void) {
    uint8_t userInput;
    type = Types::CAR;
    Vehicle::askUserData();
    
    std::cout << "Choose fuel type, DIESEL (1) or GASOLINE (2)? ";
    std::cin >> userInput;

    switch (userInput) {
        case 1:
            fuelType = FuelTypes::DIESEL;
            break;
        case 2:
            fuelType = FuelTypes::GASOLINE;
            break;
        default:
            std::cout << "Bad selection";
            fuelType = FuelTypes::DIESEL;
            break;
    }

    std::cout << "How many doors? ";
    std::cin >> doors;
    std::cout << "Trunk capacity? ";
    std::cin >> trunkCapacity;
}

void Car::loadFromFile(void) {
    return;
}
