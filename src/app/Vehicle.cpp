#include <iostream>
#include <iomanip>
#include <cctype>
#include "Vehicle.h"
#include "common/Exceptions.h"

// Constructor
Vehicle::Vehicle(VehicleType type, std::string brand, std::string model, int year, FuelType fuelType, int weight, std::string efficiency)
    : type{type}, brand{brand}, model{model}, year{year}, fuelType{fuelType}, weight{weight}, efficiencyClass{efficiency}{
        checkStringValidity(brand);
        checkStringValidity(model);
        checkStringValidity(efficiency);
        checkIntInRange(year, min_year, max_year);
        checkIntInRange(weight, min_weight, max_weight);
        std::stringstream make_id {};
        make_id << static_cast<char>(std::toupper(brand.front())) << static_cast<char>(std::toupper(model.front())) << fuelType << year + weight;
        id = make_id.str();
        //std::cout << type << std::endl;
    }
// Copy Constructor
Vehicle::Vehicle(const Vehicle &source)
    : Vehicle{source.type, source.brand, source.model, source.year, source.fuelType, source.weight} {}
// Methods
void Vehicle::info(std::ostream &os) const{
    os << std::setw(vehicle_parameter_width) << std::left << VehicleType_to_string(type)
       << std::setw(vehicle_parameter_width) << std::left << id
       << std::setw(vehicle_parameter_width) << std::left << brand
       << std::setw(vehicle_parameter_width) << std::left << model
       << std::setw(vehicle_parameter_width) << std::left << year
       << std::setw(vehicle_parameter_width) << std::left << FuelType_to_string(fuelType)
       << std::setw(vehicle_parameter_width) << std::left << weight
       << std::setw(vehicle_parameter_width) << std::left << efficiencyClass;
}