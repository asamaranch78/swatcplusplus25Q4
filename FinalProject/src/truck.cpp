#include <iostream>
#include <iomanip>

#include "truck.h"
#include "vehicle.h"
#include "constants.h"

void Truck::info(void) {
    Vehicle::info();
    std::cout << std::setw(GAP) << "Car";
    std::cout << "Axles: " << axles;
    std::cout << "\t";
    std::cout << "Paylod Capacity: " << payloadCapacity;
    std::cout << std::endl;
}

void Truck::fuelEfficiencyCalc(void) {
    return;
}

void Truck::saveToFile(void) {
    return;
}

void Truck::askUserData(void) {
    type = Types::TRUCK;
    Vehicle::askUserData();
    fuelType = FuelTypes::DIESEL;

    std::cout << "How many axles? ";
    std::cin >> axles;
    std::cout << "Payload capacity? ";
    std::cin >> payloadCapacity;
}

void Truck::loadFromFile(void) {
    return;
}
