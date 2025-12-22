#ifndef __BIKE_H__
#define __BIKE_H__
#include "Vehicle.h"

class Bike : public Vehicle {
    public:
        bool hasCarrier;
        enum bikeType { Mountain, Road, Hybrid };
        bikeType type;

        Bike(string b, string m, int y, Vehicle::fuelType f, double w, bool carrier, bikeType t)
            : Vehicle{b, m, y, f, w}, hasCarrier{carrier}, type {t} {}

        std::string info() override;

        double fuelEfficiency() override;

        ~Bike() = default;
}; 

std::string Bike::info(){
    return "Bike: " + brand + " " + model + ", Year: " + to_string(year) +
           ", Fuel: " + (fuel == Petrol ? "Petrol" : fuel == Diesel ? "Diesel" : "Electric") +
           ", Weight: " + to_string(weigth) + "kg, Carrier: " + (hasCarrier ? "Yes" : "No") + (type == Mountain ? ", Type: Mountain" : type == Road ? ", Type: Road" : ", Type: Hybrid");
}

double Bike::fuelEfficiency(){
    return 50.0 - (weigth / 100.0) + (hasCarrier ? -2.0 : 0.0);
}

#endif