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

#endif