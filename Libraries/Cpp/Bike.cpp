#include <iostream>
#include <iomanip>
#include "Bike.h"

// Constructor
Bike::Bike(std::string brand, std::string model, int year, FuelType fuelType, int weight, BikeType bikeType, YesNo hasCarrier, std::string efficiency)
    : Vehicle(Bikes, brand, model, year, fuelType, weight, efficiency), bikeType{bikeType}, hasCarrier{hasCarrier}{
        checkIntInRange(weight, get_min_weight(), max_weight);
    }
// Copy Constructor
Bike::Bike(const Bike &source)
    : Vehicle(source), bikeType{source.bikeType}, hasCarrier{source.hasCarrier} {}
// Methods
void Bike::info(std::ostream &os) const{
    os << std::setw(vehicle_parameter_width) << std::left << VehicleType_to_string(type)
       << std::setw(vehicle_parameter_width) << std::left << id
       << std::setw(vehicle_parameter_width) << std::left << brand
       << std::setw(vehicle_parameter_width) << std::left << model
       << std::setw(vehicle_parameter_width) << std::left << year
       << std::setw(vehicle_parameter_width) << std::left << FuelType_to_string(fuelType)
       << std::setw(vehicle_parameter_width) << std::left << weight
       << std::setw(vehicle_parameter_width) << std::left << efficiencyClass
       << std::setw(vehicle_parameter_width) << std::left << BikeType_to_string(bikeType)
       << std::setw(vehicle_parameter_width/2) << std::right << YesNo_to_string(hasCarrier);
}
bool Bike::compute_efficiency(){
    double typeFactor {};
    if(bikeType == Road)
        typeFactor = 10.0;
    else if(bikeType == Standard)
        typeFactor = 4.0;
    else if(bikeType == Mountain)
        typeFactor = 6.0;
    else
        typeFactor = 2.0;
    efficiencyValue = typeFactor*(11000 - weight);
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