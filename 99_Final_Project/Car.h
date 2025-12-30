#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
    private:
        double trunkCapacity;
        int numDoors;
        CarType cType;

    public:
        Car(std::string brand, std::string model, int year, double weight, double tankCapacity, FuelType f_type, double trkCapacity, int doors = 5, CarType c_type = CarType::Station_wagon) 
            : Vehicle{VehicleType::Car, brand, model, year, weight, tankCapacity, f_type}, trunkCapacity{trkCapacity}, numDoors{doors}, cType{c_type}
            {
            }
        ~Car() = default;

        virtual void get_info(std::ostream &os) const override;
        virtual double fuelEfficiency() override;

};