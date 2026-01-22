#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

// =====================
// Fuel type enum
// =====================
enum class FuelType {
    Petrol,
    Diesel,
    Electric
};

// Helpers (implementados en Vehicle.cpp)
std::string fuelTypeToString(FuelType type);
FuelType fuelTypeFromString(const std::string& value);

// =====================
// Base class: Vehicle
// =====================
class Vehicle {
public:
    virtual ~Vehicle() = default;

    // --- Polymorphic interface ---
    virtual std::string typeName() const = 0;
    virtual std::string info() const = 0;
    virtual double fuelEfficiency() const = 0;

    // CSV support (base fields)
    virtual std::string toCsvRow() const = 0;

    // --- Getters ---
    int getId() const noexcept;
    const std::string& getBrand() const noexcept;
    const std::string& getModel() const noexcept;
    int getYear() const noexcept;
    FuelType getFuelType() const noexcept;
    double getWeightKg() const noexcept;

protected:
    // Constructor for derived classes
    Vehicle(int id,
            const std::string& brand,
            const std::string& model,
            int year,
            FuelType fuelType,
            double weightKg);

    // Validation shared by all vehicles
    static void validateBaseData(int id,
                                 const std::string& brand,
                                 const std::string& model,
                                 int year,
                                 double weightKg);

private:
    int m_id;
    std::string m_brand;
    std::string m_model;
    int m_year;
    FuelType m_fuelType;
    double m_weightKg;
};

#endif // VEHICLE_H
