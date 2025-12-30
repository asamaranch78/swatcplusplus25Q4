#pragma once

#include "Vehicle.h"

class Motorbike : public Vehicle
{
    private:
        MotorbikeType bType;

    public:
        Motorbike(std::string brand, std::string model, int year, double weight, double tankCapacity, MotorbikeType b_type = MotorbikeType::Naked, FuelType f_type = FuelType::Gas) 
            : Vehicle{VehicleType::Motorbike, brand, model, year, weight, tankCapacity, f_type}, bType{b_type}
            {
            }
        ~Motorbike() = default;

        virtual void get_info(std::ostream &os) const override;
        virtual double fuelEfficiency() override;
};