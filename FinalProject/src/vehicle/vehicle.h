#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include <string>
#include <cstdint>

enum FuelTypes{DIESEL, GASOLINE, ELECTRIC};
enum Types {CAR, TRUCK, ELECTRIC_CAR, MOTORBIKE};

class Vehicle {
public:
    std::string manufacturer;
    std::string model;
    uint16_t year;
    uint16_t weight;
    double fuelEfficiency;
    FuelTypes fuelType;
    Types type;

    virtual void info();
    virtual void fuelEfficiencyCalc() = 0;
    virtual void saveToFile() = 0;
    virtual void loadFromFile() = 0;
    std::string getFuelType(void);
    std::string getType(void);
    virtual std::string getSpecial(void) = 0;
};

#endif
