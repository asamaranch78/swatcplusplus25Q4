#ifndef _CAR_H_
#define _CAR_H_

#include <string>
#include "Vehicle.h"
#include "Utils.h"

class Car: public Vehicle
{
private:
    VehicleType type = Cars;
    const int min_weight {500};
    const int max_weight {5000};
    const int min_num_doors {1};
    const int max_num_doors {7};
    const int min_trunk_capacity {0};
    const int max_trunk_capacity {5000};
protected:
    int trunkCapacity;
    int numDoors; 
public:
// Constructor
    Car(std::string brand, std::string model, int year, FuelType fuelType, int weight, int trunkCapacity, int numDoors, std::string efficiency = "NC");
// Copy Constructor
    Car(const Car &source);
// Move Constructor
    Car(Car &&source) = default;
// Destructor
    virtual ~Car() = default;
// Getters
    VehicleType get_type() const {return type;}
    int get_trunk_capacity() const {return trunkCapacity;}
    int get_num_doors() const {return numDoors;}
// Methods
    virtual void info(std::ostream &os) const override;
    virtual bool compute_efficiency() override;
// Overload
    bool operator<(const Car &rhs) const {
        //return this->numDoors < rhs.numDoors;
        return this->efficiencyClass < rhs.efficiencyClass;
    }
    bool operator==(const Car &rhs) const  {
        return (this->trunkCapacity == rhs.trunkCapacity && this->numDoors == rhs.numDoors);
    }
};

#endif // _CAR_H_