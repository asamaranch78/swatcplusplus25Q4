#include <iostream>
#include <iomanip>

#include "Motorbike.h"

std::string Motorbike::get_bike_type_string() const
{
    switch (this->bType)
    {
        case MotorbikeType::Sport_bike: return "Sports bike"; break;
        case MotorbikeType::Custom: return "Custom"; break;
        case MotorbikeType::Chopper: return "Chopper"; break;
        case MotorbikeType::Naked: return "Naked"; break;
        case MotorbikeType::Scooter: return "Scooter"; break;
        case MotorbikeType::Touring: return "Touring"; break;
        case MotorbikeType::Motocross: return "Motocross"; break;
        default: return "Unknown"; break;
    }
}

void Motorbike::get_info(std::ostream &os) const
{
    Vehicle::get_info(os);
    std::cout << std::setw(25) << std::left << "Type:" << std::setw(8) << get_bike_type_string() << std::endl;
    std::cout << std::setw(25) << std::left << "Fuel efficiency:" << std::setw(8) << fuel_efficiency() << std::endl;
    std::cout << "=====================================" << std::endl;
}

std::string Motorbike::save_object() const
{
    std::string vStr{Vehicle::save_object()};
    std::ostringstream oss;

    oss << vStr;
    oss << std::fixed << std::setprecision(4);
    oss << get_bike_type_string() << ",";
    
    return oss.str();
}

double Motorbike::get_fuel_factor() const
{
    switch (this->fType)
    {
        case (FuelType::Gas): return 1.2f; break;
        case (FuelType::Diesel): return .2f; break;
        case (FuelType::Hybrid): return .9f; break;
        case (FuelType::Electric): return .65f; break;
        default: return 0.0; break;
    }
}

double Motorbike::fuel_efficiency() const
{
    return (this->tankCapacity * get_fuel_factor() * 1000) / (this->weight * this->baseConsumption);
}
