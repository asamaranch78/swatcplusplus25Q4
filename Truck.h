#ifndef __TRUCK_H__
#define __TRUCK_H__
#include "Vehicle.h"

class Truck : public Vehicle {
public:
    double maxLoad;
    int numAxles;
    Truck(string b, string m, int y, Vehicle::fuelType f, double w, double load, int axles)
        : Vehicle{b, m, y, f, w}, maxLoad{load}, numAxles{axles} {}
    std::string info() override;
    double fuelEfficiency() override;
    ~Truck() = default;
};

std::string Truck::info(){
    return "Truck: " + brand + " " + model + ", Year: " + to_string(year) +
           ", Fuel: " + (fuel == Petrol ? "Petrol" : fuel == Diesel ? "Diesel" : "Electric") +
           ", Weight: " + to_string(weigth) + "kg, Max Load: " + to_string(maxLoad) +
           "kg, Axles: " + to_string(numAxles);
}

double Truck::fuelEfficiency(){
    return 8.0 - (weigth / 2000.0) - (maxLoad / 1000.0);
}


#endif