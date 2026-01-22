#ifndef __MOTORBIKE_H__
#define __MOTORBIKE_H__

#include "vehicle.h"

class Motorbike: public Vehicle {
public:
    uint16_t seats;

    Motorbike() = default;
    ~Motorbike() = default;
    virtual std::string getSpecial(void) override;
    virtual YAML::Node getYaml() override;
    virtual void loadYaml(YAML::Node node) override;
};

#endif
