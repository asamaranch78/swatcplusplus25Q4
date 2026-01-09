#ifndef __TRUCK_H__
#define __TRUCK_H__

#include <cstdint>

#include "vehicle.h"
#include "messages.h"

class Truck: public Vehicle {
public:
    uint16_t axles;
    uint16_t payloadCapacity;

    Truck() = default;
    ~Truck() = default;
    virtual void info() override;
    virtual void fuelEfficiencyCalc() override;
    virtual void saveToFile() override;
    virtual void askUserData(Msg *msg) override;
    virtual void loadFromFile() override;
};

#endif
