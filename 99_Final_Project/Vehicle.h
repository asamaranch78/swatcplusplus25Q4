#pragma once

#include <cstdint>

#include "I_Printable.h"
#include "ProjectEnums.h"

class Vehicle : public I_Printable
{
    private:
        // Auto-generated id_ attribute
        const std::uint64_t id_;
        static std::uint64_t GenerateId();

    protected:
        VehicleType vType;
        std::string brand;
        std::string model;
        int year;
        double weight;
        double tankCapacity;
        FuelType fType;
        double baseConsumption;

        // Protected constructor for vehicle class.
        Vehicle(VehicleType v_type, std::string b_name = "", std::string m_model = "-", int y_year = 0, double w_weight = 0, double t_tankCapacity = 0, FuelType f_type = FuelType::Unknown, double b_consumption = 0.0)
            : id_{GenerateId()}, vType{v_type}, brand{b_name}, model{m_model}, year{y_year}, weight{w_weight}, tankCapacity{t_tankCapacity}, fType{f_type}, baseConsumption{b_consumption}
            {
            }

    public:
        virtual ~Vehicle() = default;
    
        // Getters
        inline std::uint64_t getId() const noexcept { return id_; };
        inline std::string get_brand() const { return brand; };
        inline std::string get_model() const { return model; };
        inline int get_year() const { return year; };
        inline double get_weight() const { return weight; };
        inline double get_tank_capacity() const { return this->tankCapacity; };
        inline VehicleType get_vehicle_type() const { return this->vType; };
        inline FuelType get_fuel_type() const { return this->fType; };
        
        // Helpers for enum types.
        std::string get_vehicle_string() const;
        std::string get_fuel_string() const;
        
        // Virtual methods for printing and saving.
        virtual void get_info(std::ostream &os) const;
        virtual std::string save_object() const;

        // Pure virtual methods for efficiency calculation.
        virtual double get_fuel_factor() const = 0;
        virtual double fuel_efficiency() const = 0;

        // Operator overload for comparison.
        bool operator==(const Vehicle &rhs) const;
};