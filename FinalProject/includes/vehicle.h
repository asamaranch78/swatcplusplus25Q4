#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include <string>
#include <cstdint>
#include <yaml-cpp/yaml.h>

#include "enums.h"


class Vehicle {
public:
    std::string manufacturer;
    std::string model;
    uint16_t year;
    uint16_t weight;
    double fuelEfficiency;
    FuelTypes fuelType;
    Types type;

    std::string getFuelType(void);
    std::string getType(void);
    virtual void fuelEfficiencyCalc() = 0;
    virtual std::string getSpecial(void) = 0;
    virtual YAML::Node getYaml();
    virtual void loadYaml(YAML::Node node);
};

#endif
