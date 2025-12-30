#include <iomanip>

#include "Vehicle.h"

std::string Vehicle::get_fuel_string() const
{
    switch (fType)
    {
        case (FuelType::Diesel): return "Diesel"; break;
        case (FuelType::Gas): return "Gas"; break;
        case (FuelType::Electric): return "Electric"; break;
        case (FuelType::Hybrid): return "Hybrid"; break;
        case (FuelType::None): return "-"; break;
        default: return "Unknown"; break;
    }
}

std::string Vehicle::get_vehicle_string() const
{
    switch (this->vType)
    {
        case (VehicleType::Car): return "CAR"; break;
        case (VehicleType::Truck): return "TRUCK"; break;
        case (VehicleType::Motorbike): return "MOTORBIKE"; break;
        default: return "UNKNOWN"; break;
    }
}

void Vehicle::get_info(std::ostream &os) const
{
    std::cout << "=====================================" << std::endl;
    std::cout << "··  ···  ···  ···  ···  ···  ···  ···" << std::endl;
    std::cout << get_vehicle_string() << std::endl;
    std::cout << "···  ···  ···  ···  ···  ···  ···  ··" << std::endl;
    std::cout << std::setw(20) << std::left << "Brand:" << std::setw(8) << this->brand << std::endl;
    std::cout << std::setw(20) << std::left << "Model:" << std::setw(8) << this->model << std::endl;
    std::cout << std::setw(20) << std::left << "Year:" << std::setw(8) << this->year << std::endl;
    std::cout << std::setw(20) << std::left << "Weight (kg):" << std::setw(8) << this->weight << std::endl;
    std::cout << std::setw(20) << std::left << "Fuel type:" << std::setw(8) << get_fuel_string() << std::endl;
    std::cout << std::setw(20) << std::left << "Tank capacity (l):" << std::setw(8) << this->get_tank_capacity() << std::endl;
}

bool Vehicle::operator==(const Vehicle &rhs) const
{
    return (this->brand == rhs.brand && this->model == rhs.model && this->year == rhs.year);
}