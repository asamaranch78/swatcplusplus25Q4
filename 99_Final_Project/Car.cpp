#include <iostream>
#include <iomanip>

#include "Car.h"

using std::cout;
using std::endl;

std::string get_car_type_string(const CarType &cType)
{
    switch (cType)
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
    std::cout << std::setw(20) << std::left << "Trunk capacity (l):" << std::setw(8) << this->trunkCapacity << std::endl;
    std::cout << std::setw(20) << std::left << "Car type:" << std::setw(8) << get_car_type_string(this->cType) << std::endl;
    std::cout << std::setw(20) << std::left << "Doors:" << std::setw(8) << this->numDoors << std::endl;
    std::cout << "=====================================" << std::endl;
}

double Car::fuelEfficiency()
{
    cout << "car fuel efficiency" << endl;
    return 0.0;
}