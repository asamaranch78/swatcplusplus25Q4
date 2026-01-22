#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
#include <string>

// =====================
// Class: Truck
// =====================
class Truck : public Vehicle {
public:
    Truck(int id,
          const std::string& brand,
          const std::string& model,
          int year,
          FuelType fuelType,
          double weightKg,
          double payloadCapacityKg,
          int numAxles);

    // Polymorphic overrides
    std::string typeName() const override;
    std::string info() const override;
    double fuelEfficiency() const override;
    std::string toCsvRow() const override;

    // Getters
    double getPayloadCapacityKg() const noexcept;
    int getNumAxles() const noexcept;

private:
    // Validation helpers
    static void validateTruckData(double payloadCapacityKg, int numAxles);

    double m_payloadCapacityKg;
    int m_numAxles;
};

#endif // TRUCK_H
