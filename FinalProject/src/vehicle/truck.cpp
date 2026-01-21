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

YAML::Node Truck::getYaml() {
    YAML::Node node = Vehicle::getYaml();

    node["Axles"] = axles;
    node["PayloadCapacity"] = payloadCapacity;

    return node;
}

void Truck::loadYaml(YAML::Node node) {
    type = Types::TRUCK;
    Vehicle::loadYaml(node);

    axles = node["Axles"].as<uint16_t>();
    payloadCapacity = node["PayloadCapacity"].as<uint16_t>();
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
