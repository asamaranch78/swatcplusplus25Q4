#pragma once

#include "Vehicle.h"

class Truck : public Vehicle
{
    private:
        TruckType tType;

    public:
        Truck(std::string brand, std::string model, int year, double weight, double tankCapacity, TruckType t_tType = TruckType::Two_axle, FuelType f_fType = FuelType::Diesel)
            : Vehicle{VehicleType::Truck, brand, model, year, weight, tankCapacity, f_fType}, tType{t_tType}
            {
            }
        ~Truck() = default;
               
        virtual void get_info(std::ostream &os) const override;
        virtual double fuelEfficiency() override;
};