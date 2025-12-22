#ifndef __CAR_H__
#define __CAR_H__
#include "Vehicle.h"

class Car : public Vehicle {
public:
    int numDoors;
    double trunkCapacity;

    

    Car(string b, string m, int y, Vehicle::fuelType f, double w, int doors, double trunkCap)
        : Vehicle{b, m, y, f, w}, numDoors{doors},trunkCapacity{trunkCap} {}

    std::string info() override;

    double fuelEfficiency()override;

    ~Car() = default;
};

std::string Car::info(){
    return "Car: " + brand + " " + model + ", Year: " + to_string(year) +
           ", Fuel: " + (fuel == Petrol ? "Petrol" : fuel == Diesel ? "Diesel" : "Electric") +
           ", Weight: " + to_string(weigth) + "kg, Doors: " + to_string(numDoors) +
           ", Trunk Capacity: " + to_string(trunkCapacity) + "L";
}

double Car::fuelEfficiency(){
    return 15.0 - (weigth / 1000.0) - (numDoors * 0.5);
}
#endif