// Car.cpp
#include "Car.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>

// ---------------------
// Constructor
// ---------------------
Car::Car(int id,
         const std::string& brand,
         const std::string& model,
         int year,
         FuelType fuelType,
         double weightKg,
         int numDoors,
         double trunkCapacityLiters)
    : Vehicle(id, brand, model, year, fuelType, weightKg),
      m_numDoors(numDoors),
      m_trunkCapacityLiters(trunkCapacityLiters)
{
    validateCarData(numDoors, trunkCapacityLiters);
}

// ---------------------
// Validation
// ---------------------
void Car::validateCarData(int numDoors, double trunkCapacityLiters)
{
    if (numDoors < 2 || numDoors > 6) {
        throw std::invalid_argument("Car numDoors must be between 2 and 6");
    }
    if (trunkCapacityLiters < 0.0) {
        throw std::invalid_argument("Car trunkCapacityLiters must be >= 0");
    }
    // Un rango razonable (no obligatorio), pero ayuda a detectar errores de input
    if (trunkCapacityLiters > 2000.0) {
        throw std::invalid_argument("Car trunkCapacityLiters is unrealistically high");
    }
}

// ---------------------
// Polymorphic overrides
// ---------------------
std::string Car::typeName() const
{
    return "Car";
}

double Car::fuelEfficiency() const
{
    // Fórmula simple y consistente para el proyecto:
    // - Base según tipo de combustible (valor arbitrario comparable)
    // - Penalización por peso
    // - Leve penalización por maletero muy grande (más volumen/carga típica)
    //
    // Resultado: "score" donde mayor = más eficiente

    double base = 0.0;
    switch (getFuelType()) {
        case FuelType::Petrol:   base = 14.0; break;
        case FuelType::Diesel:   base = 16.0; break;
        case FuelType::Electric: base = 22.0; break;
        default:                 base = 12.0; break;
    }

    const double weightPenalty = getWeightKg() / 250.0;          // ~5-7 para coches normales
    const double trunkPenalty  = m_trunkCapacityLiters / 800.0;  // 0.5 aprox para 400L

    double eff = base - weightPenalty - trunkPenalty;

    // Evitar negativos para que ordenar tenga sentido
    if (eff < 0.1) eff = 0.1;
    return eff;
}

std::string Car::info() const
{
    std::ostringstream oss;
    oss << "ID=" << getId()
        << " | Type=" << typeName()
        << " | " << getBrand() << " " << getModel()
        << " | Year=" << getYear()
        << " | Fuel=" << fuelTypeToString(getFuelType())
        << " | WeightKg=" << std::fixed << std::setprecision(1) << getWeightKg()
        << " | Doors=" << m_numDoors
        << " | Trunk(L)=" << std::fixed << std::setprecision(1) << m_trunkCapacityLiters
        << " | Efficiency=" << std::fixed << std::setprecision(2) << fuelEfficiency();
    return oss.str();
}

std::string Car::toCsvRow() const
{
    // Formato propuesto:
    // id,type,brand,model,year,fuelType,weightKg,numDoors,trunkCapacityLiters
    std::ostringstream oss;
    oss << getId() << ","
        << typeName() << ","
        << getBrand() << ","
        << getModel() << ","
        << getYear() << ","
        << fuelTypeToString(getFuelType()) << ","
        << std::fixed << std::setprecision(1) << getWeightKg() << ","
        << m_numDoors << ","
        << std::fixed << std::setprecision(1) << m_trunkCapacityLiters;
    return oss.str();
}

// ---------------------
// Getters
// ---------------------
int Car::getNumDoors() const noexcept
{
    return m_numDoors;
}

double Car::getTrunkCapacityLiters() const noexcept
{
    return m_trunkCapacityLiters;
}
