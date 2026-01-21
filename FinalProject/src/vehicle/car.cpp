#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>

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

std::string Car::getSpecial(void) {
    std::string special {};
    special = "Doors: " + std::to_string(doors);
    special += "\t";
    special += "Trunk capacity: " + std::to_string(trunkCapacity);
    return special;
}

YAML::Node Car::getYaml() {
    YAML::Node node = Vehicle::getYaml();

    node["Doors"] = doors;
    node["TrunkCapacity"] = trunkCapacity;

    return node;
}

void Car::loadYaml(YAML::Node node) {
    type = Types::CAR;
    Vehicle::loadYaml(node);

    doors = node["Doors"].as<uint16_t>();
    trunkCapacity = node["TrunkCapacity"].as<uint16_t>();
}

void Car::fuelEfficiencyCalc(void) {
    return;
}

void Car::saveToFile(void) {
    return;
}

void Car::loadFromFile(void) {
    return;
}
