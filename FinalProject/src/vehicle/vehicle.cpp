#include <cstdint>
#include <iostream>
#include <iomanip>

#include "vehicle.h"
#include "constants.h"
#include "enums.h"

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
            return dieselString;
        case FuelTypes::ELECTRIC:
            return electricString;
        case FuelTypes::GASOLINE:
            return gasolineString;
    }
    return "Unknown";
}

std::string Vehicle::getType(void) {
    switch (type) {
        case Types::CAR:
            return carString;
        case Types::ELECTRIC_CAR:
            return elecCarString;
        case Types::MOTORBIKE:
            return motorString;
        case Types::TRUCK:
            return truckString;
    }
    return "Unknown";
}

FuelTypes Vehicle::decodeFuelType(std::string type) {
    if (dieselString == type) { return FuelTypes::DIESEL;}
    if (gasolineString == type) { return FuelTypes::GASOLINE;}
    if (electricString == type) { return FuelTypes::ELECTRIC;}
    throw;
}

Types Vehicle::decodeType(std::string type) {
    if (carString == type) { return Types::CAR;}
    if (elecCarString == type) { return Types::ELECTRIC_CAR;}
    if (motorString == type) { return Types::MOTORBIKE;}
    if (truckString == type) { return Types::TRUCK; }
    throw;
}

YAML::Node Vehicle::getYaml() {
    YAML::Node node;

    node["Manufacturer"] = manufacturer;
    node["Model"] = model;
    node["Year"] = year;
    node["Weight"] = weight;
    node["FuelEfficiency"] = fuelEfficiency;
    node["FuelType"] = getFuelType();
    node["Type"] = getType(); 

    return node;
}

void Vehicle::loadYaml(YAML::Node node) {
    manufacturer = node["Manufacturer"].as<std::string>();
    model = node["Model"].as<std::string>();
    year = node["Year"].as<uint16_t>();
    weight = node["Weight"].as<uint16_t>();
    fuelEfficiency = node["FuelEfficiency"].as<double>();
    fuelType = decodeFuelType(node["FuelType"].as<std::string>());
}
