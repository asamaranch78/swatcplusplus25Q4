#include <iostream>
#include <iomanip>
#include "Car.h"

// Constructor
Car::Car(std::string brand, std::string model, int year, FuelType fuelType, int weight, int trunkCapacity, int numDoors, std::string efficiency)
    : Vehicle(Cars, brand, model, year, fuelType, weight, efficiency), trunkCapacity{trunkCapacity}, numDoors{numDoors}{
        checkIntInRange(weight, get_min_weight(), max_weight);
        checkIntInRange(trunkCapacity, min_trunk_capacity, max_trunk_capacity);
        checkIntInRange(numDoors, min_num_doors, max_num_doors);
    }
// Copy Constructor
Car::Car(const Car &source)
    : Vehicle(source), trunkCapacity{source.trunkCapacity}, numDoors{source.numDoors} {}
// Methods
void Car::info(std::ostream &os) const{
    os << std::setw(vehicle_parameter_width) << std::left << VehicleType_to_string(type)
       << std::setw(vehicle_parameter_width) << std::left << id
       << std::setw(vehicle_parameter_width) << std::left << brand
       << std::setw(vehicle_parameter_width) << std::left << model
       << std::setw(vehicle_parameter_width) << std::left << year
       << std::setw(vehicle_parameter_width) << std::left << FuelType_to_string(fuelType)
       << std::setw(vehicle_parameter_width) << std::left << weight
       << std::setw(vehicle_parameter_width) << std::left << efficiencyClass
       << std::setw(vehicle_parameter_width) << std::left << trunkCapacity
       << std::setw(vehicle_parameter_width/2) << std::right << numDoors;
}
bool Car::compute_efficiency(){
    double fuelFactor {};
    if(fuelType == Electric)
        fuelFactor = 10.0;
    else if(fuelType == Diesel)
        fuelFactor = 3.0;
    else if(fuelType == Hybrid)
        fuelFactor = 6.0;
    else
        fuelFactor = 1.0;
    efficiencyValue = fuelFactor*(15000 - weight*numDoors - trunkCapacity);
    efficiencyValue = (efficiencyValue > 0) ? efficiencyValue : 0;
    if(efficiencyValue > 100000)
        efficiencyClass = "A";
    else if(efficiencyValue > 60000)
        efficiencyClass = "B";
    else if(efficiencyValue > 20000)
        efficiencyClass = "C";
    else if(efficiencyValue > 1000)
        efficiencyClass = "D";
    else
        efficiencyClass = "F";
    return true;
}