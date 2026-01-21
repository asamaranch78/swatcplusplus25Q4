#ifndef __ELECTRIC_H__
#define __ELECTRIC_H__

#include "car.h"

class Electric: public Car {
public:
    uint16_t range;

    Electric() = default;
    ~Electric() = default;
    virtual void fuelEfficiencyCalc() override;
    virtual std::string getSpecial(void) override;
    virtual YAML::Node getYaml() override;
    virtual void loadYaml(YAML::Node node) override;
};

#endif
