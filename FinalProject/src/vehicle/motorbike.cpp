#include "motorbike.h"

void Motorbike::fuelEfficiencyCalc() {
    return;
}

std::string Motorbike::getSpecial(void) {
    return "Seats: " + std::to_string(seats);
}

YAML::Node Motorbike::getYaml() {
    YAML::Node node = Vehicle::getYaml();

    node["Seats"] = seats;

    return node;
}

void Motorbike::loadYaml(YAML::Node node) {
    type = Types::MOTORBIKE;
    Vehicle::loadYaml(node);

    seats = node["Seats"].as<uint16_t>();
}
