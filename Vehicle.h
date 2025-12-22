#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include <string>

using namespace std;

class Vehicle{

    public:
        string brand;
        string model;
        int year;
        enum fuelType { Petrol, Diesel, Electric };
        Vehicle::fuelType fuel;
        double weigth;

        virtual string info()=0;

        virtual double fuelEfficiency()=0;

        Vehicle(string b, string m, int y, Vehicle::fuelType f, double w)
            : brand{b}, model{m}, year{y}, fuel{f}, weigth{w} {}

        ~Vehicle() = default;
};
/*
string Vehicle::info(){
    return "Vehicle: " + brand + " " + model + ", Year: " + to_string(year) +
           ", Fuel: " + (fuel == Petrol ? "Petrol" : fuel == Diesel ? "Diesel" : "Electric") +
           ", Weight: " + to_string(weigth) + "kg";
}
double Vehicle::fuelEfficiency(){
    return 20.0 - (weigth / 1000.0);
}*/
#endif