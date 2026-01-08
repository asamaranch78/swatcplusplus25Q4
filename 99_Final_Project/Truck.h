#pragma once

#include "Vehicle.h"

class Truck : public Vehicle
{
    private:
        TruckType tType;

    public:
        Truck(std::string brand, std::string model, int year, double weight, double tankCapacity, FuelType f_fType, double b_consumption, TruckType t_tType)
            : Vehicle{VehicleType::Truck, brand, model, year, weight, tankCapacity, f_fType, b_consumption}, tType{t_tType}
            {
            }
        ~Truck() = default;
               
        // Getters for this class.
        inline TruckType get_truck_type() const { return this->tType; };

        // Helper for truck type enum.
        std::string get_truck_type_string() const;

        // Vehicle super class overrides.
        void get_info(std::ostream &os) const override;
        std::string save_object() const override;

        // Fuel efficiency overrides (Vehicle super class pure virtual methods).
        double get_fuel_factor() const override;
        double fuel_efficiency() const override;
};