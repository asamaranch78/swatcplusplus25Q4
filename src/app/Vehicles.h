#ifndef _VEHICLES_H_
#define _VEHICLES_H_

#include <vector>
#include <string>
#include <memory>
#include "Vehicle.h"

class Vehicles
{
private:
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    std::vector<std::unique_ptr<Vehicle>> backup;
public:
// Constructor
    Vehicles() = default;
// Copy Constructor
    Vehicles(const Vehicles &source) = default;
// Destructor
    ~Vehicles() = default;
// Methods
    void display() const;
    bool add_vehicle(std::unique_ptr<Vehicle> vehicle);
    bool calc_efficiency(std::unique_ptr<Vehicle> vehicle = nullptr);
    bool save_data(std::unique_ptr<Vehicle> vehicle = nullptr);
    void sort(const Attribute &sel);
    void filter(MyFilter &mf);
    void unfilter(MyFilter &mf);
};

#endif // _VEHICLEs_H_