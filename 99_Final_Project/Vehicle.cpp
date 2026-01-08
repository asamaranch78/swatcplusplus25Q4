#include <iomanip>

#include "Vehicle.h"

std::uint64_t Vehicle::GenerateId()
{
    static std::uint64_t nextId = 1;
    return nextId++;
}

std::string Vehicle::get_fuel_string() const
{
    switch (fType)
    {
        case (FuelType::Diesel): return "DIESEL"; break;
        case (FuelType::Gas): return "GAS"; break;
        case (FuelType::Electric): return "ELECTRIC"; break;
        case (FuelType::Hybrid): return "HYBRID"; break;
        case (FuelType::Unknown): return "-"; break;
        default: return "Unknown"; break;
    }
}

std::string Vehicle::save_object() const
{
    std::ostringstream oss;

    oss << std::fixed << std::setprecision(4);
    oss << get_vehicle_string() << ",";
    oss << this->brand << ",";
    oss << this->model << ",";
    oss << this->year << ",";
    oss << this->weight << ",";
    oss << get_fuel_string() << ",";
    oss << this->tankCapacity << ",";
    oss << this->baseConsumption << ",";

    return oss.str();
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
    std::cout << std::fixed << std::setprecision(2); 
    std::cout << "=============================================" << std::endl;
    std::cout << "··· ···  ···  ···  ···  ···  ···  ··· ··· ···" << std::endl;
    std::cout << get_vehicle_string() << std::endl;
    std::cout << "··· ···  ···  ···  ···  ···  ···  ··· ··· ···" << std::endl;
    std::cout << std::setw(25) << std::left << "ID:" << std::setw(8) << std::to_string(this->getId()) << std::endl;
    std::cout << std::setw(25) << std::left << "Brand:" << std::setw(8) << this->brand << std::endl;
    std::cout << std::setw(25) << std::left << "Model:" << std::setw(8) << this->model << std::endl;
    std::cout << std::setw(25) << std::left << "Year:" << std::setw(8) << std::to_string(this->year) << std::endl;
    std::cout << std::setw(25) << std::left << "Weight (kg):" << std::setw(8) << this->weight << std::endl;
    std::cout << std::setw(25) << std::left << "Fuel type:" << std::setw(8) << get_fuel_string() << std::endl;
    std::cout << std::setw(25) << std::left << "Tank capacity (l):" << std::setw(8) << this->tankCapacity << std::endl;
    std::cout << std::setw(25) << std::left << "Consumption (l/100km):" << std::setw(8) << this->baseConsumption << std::endl;
}

bool Vehicle::operator==(const Vehicle &rhs) const
{
    return (this->brand == rhs.brand && this->model == rhs.model && this->year == rhs.year);
}