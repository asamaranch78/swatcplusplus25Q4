#include <iostream>
#include <iomanip>

#include "Motorbike.h"

std::string get_bike_type_string(const MotorbikeType &bType)
{
    switch (bType)
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
    std::cout << std::setw(20) << std::left << "Type:" << std::setw(8) << get_bike_type_string(this->bType) << std::endl;
    std::cout << "=====================================" << std::endl;
}

double Motorbike::fuelEfficiency()
{
    std::cout << "bike fuel efficiency" << std::endl;
    return 0.0;
}