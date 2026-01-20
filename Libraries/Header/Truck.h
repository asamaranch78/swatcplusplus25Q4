#ifndef _TRUCK_H_
#define _TRUCK_H_

#include <string>
#include "Vehicle.h"
#include "Utils.h"

class Truck: public Vehicle
{
private:
    VehicleType type = Trucks;
    const int min_weight {2000};
    const int min_num_axles {2};
    const int max_num_axles {10};
    const int min_payload_capacity {100};
    const int max_payload_capacity {50000};
protected:
    int payloadCapacity;
    int numAxles; 
public:
// Constructor
    Truck(std::string brand, std::string model, int year, FuelType fuelType, int weight, int payloadCapacity, int numAxles, std::string efficiency = "NC");
// Copy Constructor
    Truck(const Truck &source);
// Move Constructor
    Truck(Truck &&source) = default;
// Destructor
    virtual ~Truck() = default;
// Getters
    VehicleType get_type() const {return type;}
    int get_payload_capacity() const {return payloadCapacity;}
    int get_num_axest() const {return numAxles;}
// Methods
    virtual void info(std::ostream &os) const override;
    virtual bool compute_efficiency() override;
// Overload
    bool operator<(const Truck &rhs) const {
        //return (this->numAxles*this->payloadCapacity < rhs.numAxles*rhs.payloadCapacity);
        return this->efficiencyValue < rhs.efficiencyValue;
    }
    bool operator==(const Truck &rhs) const {
        return (this->payloadCapacity == rhs.payloadCapacity && this->numAxles == rhs.numAxles);
    }
};

#endif // _TRUCK_H_