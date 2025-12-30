#pragma once

#include <string>
#include <iostream>

#include "I_Printable.h"
#include "ProjectEnums.h"

class Vehicle : public I_Printable
{
    protected:
        VehicleType vType;
        std::string brand;
        std::string model;
        int year;
        double weight;
        double tankCapacity;
        FuelType fType;

    public:
        Vehicle(VehicleType v_type, std::string b_name = "", std::string m_model = "-", int y_year = 0, double w_weight = 0, double t_tankCapacity = 0, FuelType f_type = FuelType::None) 
            : vType{v_type}, brand{b_name}, model{m_model}, year{y_year}, weight{w_weight}, tankCapacity{t_tankCapacity}, fType{f_type} 
            {
            }

        virtual ~Vehicle() = default;

        inline std::string get_brand() const { return brand; };
        inline std::string get_model() const { return model; };
        inline int get_year() const { return year; };
        inline double get_weight() const { return weight; };
        inline double get_tank_capacity() const { return this->tankCapacity; };
        inline VehicleType get_vehicle_type() const { return this->vType; };
        inline FuelType get_fuel_type() const { return this->fType; };
        
        virtual void get_info(std::ostream &os) const;
        std::string get_vehicle_string() const;
        std::string get_fuel_string() const;

        // TODO: Convert to pure virtual.
        virtual double fuelEfficiency() { return 0.0; };

        bool operator==(const Vehicle &rhs) const;
};