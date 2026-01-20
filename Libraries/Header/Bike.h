#ifndef _BIKE_H_
#define _BIKE_H_

#include <string>
#include "Vehicle.h"
#include "Utils.h"

class Bike: public Vehicle
{
private:
    VehicleType type = VehicleType(2);
    const int max_weight {100};
protected:
    BikeType bikeType;
    YesNo hasCarrier; 
public:
// Constructor
    Bike(std::string brand, std::string model, int year, FuelType fuelType, int weight, BikeType bikeType, YesNo hasCarrier, std::string efficiency = "NC");
// Copy Constructor
    Bike(const Bike &source);
// Move Constructor
    Bike(Bike &&source) = default;
// Destructor
    virtual ~Bike() = default;
// Getters
    VehicleType get_type() const {return type;}
    BikeType get_bike_type() const {return bikeType;}
    YesNo get_has_carrier() const {return hasCarrier;}
// Methods
    virtual void info(std::ostream &os) const override;
    virtual bool compute_efficiency() override;
// Overload
    bool operator<(const Bike &rhs) const {
        //return this->weight < rhs.weight;
        return this->efficiencyClass < rhs.efficiencyClass;
    }
    bool operator==(const Bike &rhs) const  {
        return (this->brand == rhs.brand && this->model == rhs.model);
    }
};

#endif // _BIKE_H_