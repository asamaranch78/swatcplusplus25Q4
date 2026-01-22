// Motorcycle.cpp
#include "Motorcycle.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>

// ---------------------
// Constructor
// ---------------------
Motorcycle::Motorcycle(int id,
                       const std::string& brand,
                       const std::string& model,
                       int year,
                       FuelType fuelType,
                       double weightKg,
                       int engineDisplacementCc,
                       bool hasSidecar)
    : Vehicle(id, brand, model, year, fuelType, weightKg),
      m_engineDisplacementCc(engineDisplacementCc),
      m_hasSidecar(hasSidecar)
{
    validateMotorcycleData(engineDisplacementCc, hasSidecar);
}

// ---------------------
// Validation
// ---------------------
void Motorcycle::validateMotorcycleData(int engineDisplacementCc, bool hasSidecar)
{
    if (engineDisplacementCc <= 0) {
        throw std::invalid_argument("Motorcycle engineDisplacementCc must be > 0");
    }
    if (engineDisplacementCc > 3000) {
        throw std::invalid_argument("Motorcycle engineDisplacementCc is unrealistically high");
    }

    // Sidecar implica más estabilidad pero penaliza eficiencia
    // (no invalidamos nada aquí, solo lógica de dominio)
    (void)hasSidecar;
}

// ---------------------
// Polymorphic overrides
// ---------------------
std::string Motorcycle::typeName() const
{
    return "Motorcycle";
}

double Motorcycle::fuelEfficiency() const
{
    // Score comparable (mayor = más eficiente)
    // Base depende del combustible y la cilindrada
    double base = 0.0;

    switch (getFuelType()) {
        case FuelType::Petrol:   base = 20.0; break;
        case FuelType::Diesel:   base = 18.0; break;
        case FuelType::Electric: base = 28.0; break;
        default:                 base = 16.0; break;
    }

    // Penalización por cilindrada
    const double displacementPenalty = m_engineDisplacementCc / 250.0;

    // Penalización por peso (motos pesan menos que coches)
    const double weightPenalty = getWeightKg() / 80.0;

    // Penalización por sidecar
    const double sidecarPenalty = m_hasSidecar ? 3.0 : 0.0;

    double eff = base - displacementPenalty - weightPenalty - sidecarPenalty;
    if (eff < 0.1) eff = 0.1;

    return eff;
}

std::string Motorcycle::info() const
{
    std::ostringstream oss;
    oss << "ID=" << getId()
        << " | Type=" << typeName()
        << " | " << getBrand() << " " << getModel()
        << " | Year=" << getYear()
        << " | Fuel=" << fuelTypeToString(getFuelType())
        << " | WeightKg=" << std::fixed << std::setprecision(1) << getWeightKg()
        << " | EngineCC=" << m_engineDisplacementCc
        << " | Sidecar=" << (m_hasSidecar ? "Yes" : "No")
        << " | Efficiency=" << std::fixed << std::setprecision(2) << fuelEfficiency();
    return oss.str();
}

std::string Motorcycle::toCsvRow() const
{
    // Formato:
    // id,type,brand,model,year,fuelType,weightKg,engineDisplacementCc,hasSidecar
    std::ostringstream oss;
    oss << getId() << ","
        << typeName() << ","
        << getBrand() << ","
        << getModel() << ","
        << getYear() << ","
        << fuelTypeToString(getFuelType()) << ","
        << std::fixed << std::setprecision(1) << getWeightKg() << ","
        << m_engineDisplacementCc << ","
        << (m_hasSidecar ? "1" : "0");
    return oss.str();
}

// ---------------------
// Getters
// ---------------------
int Motorcycle::getEngineDisplacementCc() const noexcept
{
    return m_engineDisplacementCc;
}

bool Motorcycle::getHasSidecar() const noexcept
{
    return m_hasSidecar;
}
