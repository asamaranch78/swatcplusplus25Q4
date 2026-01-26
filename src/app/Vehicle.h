#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <string>
#include "common/Print_Info.h"
#include "common/Utils.h"

class Vehicle: public Print_Info
{
private:
    const int min_year {1960};
    const int max_year {2027};
    const int min_weight {1};
    const int max_weight {20000};
protected:
    VehicleType type;
    std::string id {"ABC0001"};
    std::string brand;
    std::string model; 
    int year;
    FuelType fuelType;
    int weight;
    std::string efficiencyClass;
    double efficiencyValue {0.0};
    int position {1};
public:
// Constructor
    Vehicle() = default;
    Vehicle(VehicleType type, std::string brand, std::string model, int year, FuelType fuelType, int weight, std::string efficiencyClass = "NC");
// Copy Constructor
    Vehicle(const Vehicle &source);
// Move Constructor
    Vehicle(Vehicle &&source) = default;
// Destructor
    virtual ~Vehicle() = default;
// Getters
    int get_min_year() const {return min_year;}
    int get_max_year() const {return max_year;}
    int get_min_weight() const {return min_weight;}
    int get_max_weight() const {return max_weight;}
    VehicleType get_type() const {return type;}
    std::string get_id() const {return id;}
    std::string get_brand() const {return brand;}
    std::string get_model() const {return model;}
    int get_year() const {return year;}
    FuelType get_fuelType() const {return fuelType;}
    int get_weight() const {return weight;}
    std::string get_efficiency_class() const {return efficiencyClass;}
    double get_efficiency_value() const {return efficiencyValue;}
    int get_position() const {return position;}
// Methods
    virtual void info(std::ostream &os) const override;
    virtual bool compute_efficiency() = 0;
// Overload
    bool operator<(const Vehicle &rhs) const  {
        if(this->efficiencyClass != rhs.efficiencyClass)
            return this->efficiencyClass < rhs.efficiencyClass;
        else if(this->efficiencyValue != rhs.efficiencyValue)
            return this->efficiencyValue < rhs.efficiencyValue;
        return this->year < rhs.year;
    }
    bool operator==(const Vehicle &rhs) const  {
        return (this->brand == rhs.brand && this->model == rhs.model);
    }
};

#endif // _VEHICLE_H_