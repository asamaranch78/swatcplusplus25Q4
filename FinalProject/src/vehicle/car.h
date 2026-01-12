#ifndef __CAR_H__
#define __CAR_H__

#include <cstdint>

#include "vehicle.h"
#include "messages.h"

class Car: public Vehicle {
public:
    uint16_t doors;
    uint16_t trunkCapacity;

    Car() = default;
    ~Car() = default;
    virtual void info() override;
    virtual void fuelEfficiencyCalc() override;
    virtual void saveToFile() override;
    virtual void askUserData(Msg *msg) override;
    virtual void loadFromFile() override;
    virtual std::string getSpecial(void) override;
};

#endif
