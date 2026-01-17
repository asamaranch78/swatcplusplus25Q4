#include <iostream>
#include <iomanip>

#include "truck.h"
#include "vehicle.h"
#include "constants.h"

void Truck::info(void) {
    Vehicle::info();
    std::cout << std::setw(GAP) << "Truck";
    std::cout << "Axles: " << axles;
    std::cout << "\t";
    std::cout << "Paylod Capacity: " << payloadCapacity;
    std::cout << std::endl;
}

std::string Truck::getSpecial(void) {
    std::string special {};
    special = "Axles: " + std::to_string(axles);
    special += "\t";
    special += "Payload capacity: " + std::to_string(payloadCapacity);
    return special;
}

void Truck::fuelEfficiencyCalc(void) {
    return;
}

void Truck::saveToFile(void) {
    return;
}

void Truck::loadFromFile(void) {
    return;
}
