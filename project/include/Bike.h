#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"
#include <string>

// =====================
// Class: Bike
// =====================
class Bike : public Vehicle {
public:
    Bike(int id,
         const std::string& brand,
         const std::string& model,
         int year,
         FuelType fuelType,
         double weightKg,
         const std::string& bikeType,  // "mountain", "road", "hybrid", etc.
         bool hasCarrier);

    // Polymorphic overrides
    std::string typeName() const override;
    std::string info() const override;
    double fuelEfficiency() const override;
    std::string toCsvRow() const override;

    // Getters
    const std::string& getBikeType() const noexcept;
    bool getHasCarrier() const noexcept;

private:
    // Validation helpers
    static void validateBikeData(const std::string& bikeType);

    std::string m_bikeType;
    bool m_hasCarrier;
};

#endif // BIKE_H
