#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"
#include <string>

// =====================
// Class: Motorcycle
// =====================
class Motorcycle : public Vehicle {
public:
    Motorcycle(int id,
               const std::string& brand,
               const std::string& model,
               int year,
               FuelType fuelType,
               double weightKg,
               int engineDisplacementCc,
               bool hasSidecar);

    // Polymorphic overrides
    std::string typeName() const override;
    std::string info() const override;
    double fuelEfficiency() const override;
    std::string toCsvRow() const override;

    // Getters
    int getEngineDisplacementCc() const noexcept;
    bool getHasSidecar() const noexcept;

private:
    // Validation helpers
    static void validateMotorcycleData(int engineDisplacementCc, bool hasSidecar);

    int m_engineDisplacementCc; // cilindrada (cc)
    bool m_hasSidecar;
};

#endif // MOTORCYCLE_H
