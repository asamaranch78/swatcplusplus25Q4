#pragma once

#include "Vehicle.h"

class Motorbike : public Vehicle
{
    private:
        MotorbikeType bType;

    public:
        Motorbike(std::string brand, std::string model, int year, double weight, double tankCapacity, FuelType f_type, double b_consumption, MotorbikeType b_type) 
            : Vehicle{VehicleType::Motorbike, brand, model, year, weight, tankCapacity, f_type, b_consumption}, bType{b_type}
            {
            }
        ~Motorbike() = default;

        // Getters for this derived class.
        inline MotorbikeType get_motorbike_type() const { return this->bType; };

        // Helper for motorbike type enum.
        std::string get_bike_type_string() const;

        // Vehicle super class overrides.
        void get_info(std::ostream &os) const override;
        std::string save_object() const override;

        // Fuel efficiency overrides (Vehicle super class pure virtual methods).
        double get_fuel_factor() const override;
        double fuel_efficiency() const override;
};