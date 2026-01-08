#include <iostream>
#include <iomanip>

#include "Truck.h"

std::string Truck::get_truck_type_string() const
{
    switch (this->tType)
    {
        case TruckType::Two_axle: return "Two axle"; break;
        case TruckType::Three_axle: return "Three axle"; break;
        case TruckType::Four_axle: return "Four axle"; break;
        case TruckType::Five_axle: return "Five axle"; break;
        default: return "Unknown"; break;
    }
}

void Truck::get_info(std::ostream &os) const
{
    Vehicle::get_info(os);
    std::cout << std::setw(25) << std::left << "Type:" << std::setw(8) << get_truck_type_string() << std::endl;
    std::cout << std::setw(25) << std::left << "Fuel efficiency:" << std::setw(8) << fuel_efficiency() << std::endl;
    std::cout << "=============================================" << std::endl;
}

std::string Truck::save_object() const
{
    std::string vStr{Vehicle::save_object()};
    std::ostringstream oss;

    oss << vStr;
    oss << std::fixed << std::setprecision(4);
    oss << get_truck_type_string() << ",";

    return oss.str();
}

double Truck::get_fuel_factor() const
{
    switch (this->fType)
    {
        case (FuelType::Gas): return 0.2f; break;
        case (FuelType::Diesel): return .7f; break;
        case (FuelType::Hybrid): return .15f; break;
        case (FuelType::Electric): return .04f; break;
        default: return 0.0; break;
    }
}

double Truck::fuel_efficiency() const
{
    return (this->tankCapacity * get_fuel_factor() * 1000) / (this->weight * this->baseConsumption);
}