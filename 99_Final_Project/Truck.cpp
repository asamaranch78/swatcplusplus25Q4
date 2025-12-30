#include <iostream>
#include <iomanip>

#include "Truck.h"

std::string get_truck_type_string(const TruckType &tType)
{
    switch (tType)
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
    std::cout << std::setw(20) << std::left << "Type:" << std::setw(8) << get_truck_type_string(this->tType) << std::endl;
    std::cout << "=====================================" << std::endl;
}

double Truck::fuelEfficiency()
{
    std::cout << "Truck fuel efficiency" << std::endl;
    return 0.0;
}