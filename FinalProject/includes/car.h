#ifndef __CAR_H__
#define __CAR_H__

#include <cstdint>

#include "vehicle.h"

class Car: public Vehicle {
public:
    uint16_t doors;
    uint16_t trunkCapacity;

    Car() = default;
    ~Car() = default;
    virtual void fuelEfficiencyCalc() override;
    virtual std::string getSpecial(void) override;
    virtual YAML::Node getYaml() override;
    virtual void loadYaml(YAML::Node node) override;
};

#endif
