#include <iostream>
#include <iomanip>

#include "Car.h"

std::string Car::get_car_type_string() const
{
    switch (this->cType)
    {
        case CarType::Sedan: return "Sedan"; break;
        case CarType::Station_wagon: return "Station Wagon"; break;
        case CarType::Van: return "Van"; break;
        case CarType::Sports_car: return "Sports Car"; break;
        case CarType::SUV: return "SUV"; break;
        case CarType::MPV: return "MPV (Multi-purpose Vehicle)"; break;
        case CarType::Off_road: return "Off-road"; break;
        default: return "Unknown"; break;
    }
}

void Car::get_info(std::ostream &os) const
{
    Vehicle::get_info(os);
    std::cout << std::setw(25) << std::left << "Trunk capacity (l):" << std::setw(8) << this->trunkCapacity << std::endl;
    std::cout << std::setw(25) << std::left << "Car type:" << std::setw(8) << get_car_type_string() << std::endl;
    std::cout << std::setw(25) << std::left << "Doors:" << std::setw(8) << std::to_string(this->numDoors) << std::endl;
    std::cout << std::setw(25) << std::left << "Fuel efficiency:" << std::setw(8) << fuel_efficiency() << std::endl;
    std::cout << "=====================================" << std::endl;
}

std::string Car::save_object() const
{
    std::string vStr{Vehicle::save_object()};
    std::ostringstream oss;

    oss << vStr;
    oss << std::fixed << std::setprecision(4);
    oss << this->trunkCapacity << ",";
    oss << get_car_type_string() << ",";
    oss << this->numDoors << ",";

    return oss.str();
}

// Hard-coded values for efficiency calculations.
double Car::get_fuel_factor() const
{
    switch (this->fType)
    {
        case (FuelType::Gas): return 1.0f; break;
        case (FuelType::Diesel): return .9f; break;
        case (FuelType::Hybrid): return .75f; break;
        case (FuelType::Electric): return .5f; break;
        default: return 0.0; break;
    }
}

// Larger values -> better efficiency.
double Car::fuel_efficiency() const
{
    return (this->tankCapacity * get_fuel_factor() * 1000) / (this->weight * this->baseConsumption);
}