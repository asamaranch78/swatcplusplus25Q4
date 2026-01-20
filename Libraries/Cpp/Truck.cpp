#include <iostream>
#include <iomanip>
#include "Truck.h"

// Constructor
Truck::Truck(std::string brand, std::string model, int year, FuelType fuelType, int weight, int payloadCapacity, int numAxles, std::string efficiency)
    : Vehicle(Trucks, brand, model, year, fuelType, weight, efficiency), payloadCapacity{payloadCapacity}, numAxles{numAxles}{
        checkIntInRange(weight, min_weight, get_max_weight());
        checkIntInRange(payloadCapacity, min_payload_capacity, max_payload_capacity);
        checkIntInRange(numAxles, min_num_axles, max_num_axles);
    }
// Copy Constructor
Truck::Truck(const Truck &source)
    : Vehicle(source), payloadCapacity{source.payloadCapacity}, numAxles{source.numAxles} {}
// Methods
void Truck::info(std::ostream &os) const{
    Vehicle::info(os);
    os << std::setw(vehicle_parameter_width) << std::left << payloadCapacity
       << std::setw(vehicle_parameter_width/2) << std::right << numAxles;
}
bool Truck::compute_efficiency(){
    double fuelFactor {};
    if(fuelType == Electric)
        fuelFactor = 10.0;
    else if(fuelType == Diesel)
        fuelFactor = 3.0;
    else if(fuelType == Hybrid)
        fuelFactor = 6.0;
    else
        fuelFactor = 1.0;
    efficiencyValue = fuelFactor*(15000 - weight*numAxles - payloadCapacity);
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