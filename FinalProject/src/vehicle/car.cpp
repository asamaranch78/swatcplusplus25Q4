#include <cstdint>
#include <string>

#include "car.h"
#include "vehicle.h"

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
    Vehicle::loadYaml(node);
    type = Types::CAR;

    doors = node["Doors"].as<uint16_t>();
    trunkCapacity = node["TrunkCapacity"].as<uint16_t>();
}

void Car::fuelEfficiencyCalc(void) {
    return;
}

