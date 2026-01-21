#include "electric.h"


void Electric::fuelEfficiencyCalc() {
    return;
}

std::string Electric::getSpecial(void) {
    std::string special {Car::getSpecial()};
    special += "\t";
    special += "Range: " + std::to_string(range);
    return special;
}

YAML::Node Electric::getYaml(){
    YAML::Node node = Car::getYaml();
    node["Range"] = range;
    return node;
}

void Electric::loadYaml(YAML::Node node) {
    Car::loadYaml(node);
    type = Types::ELECTRIC_CAR;

    range = node["Range"].as<uint16_t>();
}
