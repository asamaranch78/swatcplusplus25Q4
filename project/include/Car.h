#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>

// =====================
// Class: Car
// =====================
class Car : public Vehicle {
public:
    Car(int id,
        const std::string& brand,
        const std::string& model,
        int year,
        FuelType fuelType,
        double weightKg,
        int numDoors,
        double trunkCapacityLiters);

    // Polymorphic overrides
    std::string typeName() const override;
    std::string info() const override;
    double fuelEfficiency() const override;
    std::string toCsvRow() const override;

    // Getters
    int getNumDoors() const noexcept;
    double getTrunkCapacityLiters() const noexcept;

private:
    // Validation helpers
    static void validateCarData(int numDoors, double trunkCapacityLiters);

    int m_numDoors;
    double m_trunkCapacityLiters;
};

#endif // CAR_H
