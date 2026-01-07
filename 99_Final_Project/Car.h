#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
    static constexpr inline double weight_factor = 1500;

    private:
        double trunkCapacity;
        int numDoors;
        CarType cType;

    public:
        Car(std::string brand, std::string model, int year, double weight, double tankCapacity, FuelType f_type, double b_consumption, double trkCapacity, int doors = 5, CarType c_type = CarType::Station_wagon) 
            : Vehicle{VehicleType::Car, brand, model, year, weight, tankCapacity, f_type, b_consumption}, trunkCapacity{trkCapacity}, numDoors{doors}, cType{c_type}
            {
            }
        ~Car() = default;

        // Getters for this class.
        inline double get_trunk_capacity() const { return this->trunkCapacity; };
        inline int get_num_doors() const { return this->numDoors; };

        // Helper for car type.
        std::string get_car_type_string() const;

        // Vehicle super class overrides.
        void get_info(std::ostream &os) const override;
        std::string save_object() const override;

        // Fuel efficiency overrides (Vehicle super class pure virtual methods).
        double get_fuel_factor() const override;
        double fuel_efficiency() const override;
};