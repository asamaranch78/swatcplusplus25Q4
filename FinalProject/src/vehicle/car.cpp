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

void Car::askUserData(Msg *msg) {
    type = Types::CAR;
    Vehicle::askUserData(msg);

    fuelType = Vehicle::askFuelType(msg);
    std::cout << "How many doors? ";
    std::cin >> doors;
    std::cout << "Trunk capacity? ";
    std::cin >> trunkCapacity;
}

void Car::loadFromFile(void) {
    return;
}
