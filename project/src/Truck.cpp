// Truck.cpp
#include "Truck.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>

// ---------------------
// Constructor
// ---------------------
Truck::Truck(int id,
             const std::string& brand,
             const std::string& model,
             int year,
             FuelType fuelType,
             double weightKg,
             double payloadCapacityKg,
             int numAxles)
    : Vehicle(id, brand, model, year, fuelType, weightKg),
      m_payloadCapacityKg(payloadCapacityKg),
      m_numAxles(numAxles)
{
    validateTruckData(payloadCapacityKg, numAxles);
}

// ---------------------
// Validation
// ---------------------
void Truck::validateTruckData(double payloadCapacityKg, int numAxles)
{
    if (payloadCapacityKg <= 0.0) {
        throw std::invalid_argument("Truck payloadCapacityKg must be > 0");
    }
    // Rangos razonables para camiones
    if (payloadCapacityKg > 100000.0) {
        throw std::invalid_argument("Truck payloadCapacityKg is unrealistically high");
    }
    if (numAxles < 2 || numAxles > 10) {
        throw std::invalid_argument("Truck numAxles must be between 2 and 10");
    }
}

// ---------------------
// Polymorphic overrides
// ---------------------
std::string Truck::typeName() const
{
    return "Truck";
}

double Truck::fuelEfficiency() const
{
    // "Score" comparable (mayor = más eficiente)
    // Base por combustible + penalizaciones fuertes por peso, carga y ejes
    double base = 0.0;
    switch (getFuelType()) {
        case FuelType::Diesel:   base = 10.0; break;
        case FuelType::Petrol:   base = 8.0;  break;
        case FuelType::Electric: base = 14.0; break;
        default:                 base = 7.0;  break;
    }

    const double weightPenalty  = getWeightKg() / 1500.0;        // camiones pesan mucho
    const double payloadPenalty = m_payloadCapacityKg / 2000.0; // carga impacta fuerte
    const double axlePenalty    = static_cast<double>(m_numAxles) * 0.8;

    double eff = base - weightPenalty - payloadPenalty - axlePenalty;
    if (eff < 0.1) eff = 0.1; // evitar negativos

    return eff;
}

std::string Truck::info() const
{
    std::ostringstream oss;
    oss << "ID=" << getId()
        << " | Type=" << typeName()
        << " | " << getBrand() << " " << getModel()
        << " | Year=" << getYear()
        << " | Fuel=" << fuelTypeToString(getFuelType())
        << " | WeightKg=" << std::fixed << std::setprecision(1) << getWeightKg()
        << " | PayloadKg=" << std::fixed << std::setprecision(1) << m_payloadCapacityKg
        << " | Axles=" << m_numAxles
        << " | Efficiency=" << std::fixed << std::setprecision(2) << fuelEfficiency();
    return oss.str();
}

std::string Truck::toCsvRow() const
{
    // Formato:
    // id,type,brand,model,year,fuelType,weightKg,payloadCapacityKg,numAxles
    std::ostringstream oss;
    oss << getId() << ","
        << typeName() << ","
        << getBrand() << ","
        << getModel() << ","
        << getYear() << ","
        << fuelTypeToString(getFuelType()) << ","
        << std::fixed << std::setprecision(1) << getWeightKg() << ","
        << std::fixed << std::setprecision(1) << m_payloadCapacityKg << ","
        << m_numAxles;
    return oss.str();
}

// ---------------------
// Getters
// ---------------------
double Truck::getPayloadCapacityKg() const noexcept
{
    return m_payloadCapacityKg;
}

int Truck::getNumAxles() const noexcept
{
    return m_numAxles;
}
