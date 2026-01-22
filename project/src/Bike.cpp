// Bike.cpp
#include "Bike.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <stdexcept>

// Helpers locales (solo para este .cpp)
namespace {
    std::string toLowerCopy(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        return s;
    }

    std::string trimCopy(std::string s) {
        auto notSpace = [](unsigned char ch) { return !std::isspace(ch); };
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), notSpace));
        s.erase(std::find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
        return s;
    }
}

// ---------------------
// Constructor
// ---------------------
Bike::Bike(int id,
           const std::string& brand,
           const std::string& model,
           int year,
           FuelType fuelType,
           double weightKg,
           const std::string& bikeType,
           bool hasCarrier)
    : Vehicle(id, brand, model, year, fuelType, weightKg),
      m_bikeType(trimCopy(bikeType)),
      m_hasCarrier(hasCarrier)
{
    validateBikeData(m_bikeType);
}

// ---------------------
// Validation
// ---------------------
void Bike::validateBikeData(const std::string& bikeType)
{
    if (bikeType.empty()) {
        throw std::invalid_argument("Bike bikeType must not be empty");
    }

    // Opcional: limitar a tipos conocidos (robusto para CSV/input)
    const std::string t = toLowerCopy(bikeType);
    const bool ok = (t == "road" || t == "mountain" || t == "hybrid" || t == "bmx" || t == "city");
    if (!ok) {
        throw std::invalid_argument(
            "Bike bikeType must be one of: road, mountain, hybrid, bmx, city"
        );
    }
}

// ---------------------
// Polymorphic overrides
// ---------------------
std::string Bike::typeName() const
{
    return "Bike";
}

double Bike::fuelEfficiency() const
{
    // Score comparable (mayor = más eficiente)
    // Bicis: altísima eficiencia. Penaliza peso + carrier.
    // Si es Electric: subimos base (como “mejor rendimiento/energía por km” en este scoring).
    double base = 30.0;

    if (getFuelType() == FuelType::Electric) {
        base = 35.0;
    } else if (getFuelType() == FuelType::Diesel || getFuelType() == FuelType::Petrol) {
        // Para mantener coherencia del dominio: una bici real no sería gasolina,
        // pero lo soportamos por robustez del sistema.
        base = 25.0;
    }

    const std::string t = toLowerCopy(m_bikeType);
    double typeAdjust = 0.0;
    if (t == "road")      typeAdjust = +2.0;
    else if (t == "city") typeAdjust = +1.0;
    else if (t == "hybrid") typeAdjust = +0.5;
    else if (t == "mountain") typeAdjust = -1.0;
    else if (t == "bmx")  typeAdjust = -0.5;

    const double weightPenalty  = getWeightKg() / 10.0;   // bicis pesan poco
    const double carrierPenalty = m_hasCarrier ? 0.8 : 0.0;

    double eff = base + typeAdjust - weightPenalty - carrierPenalty;
    if (eff < 0.1) eff = 0.1;
    return eff;
}

std::string Bike::info() const
{
    std::ostringstream oss;
    oss << "ID=" << getId()
        << " | Type=" << typeName()
        << " | " << getBrand() << " " << getModel()
        << " | Year=" << getYear()
        << " | Fuel=" << fuelTypeToString(getFuelType())
        << " | WeightKg=" << std::fixed << std::setprecision(1) << getWeightKg()
        << " | BikeType=" << m_bikeType
        << " | Carrier=" << (m_hasCarrier ? "Yes" : "No")
        << " | Efficiency=" << std::fixed << std::setprecision(2) << fuelEfficiency();
    return oss.str();
}

std::string Bike::toCsvRow() const
{
    // Formato:
    // id,type,brand,model,year,fuelType,weightKg,bikeType,hasCarrier
    std::ostringstream oss;
    oss << getId() << ","
        << typeName() << ","
        << getBrand() << ","
        << getModel() << ","
        << getYear() << ","
        << fuelTypeToString(getFuelType()) << ","
        << std::fixed << std::setprecision(1) << getWeightKg() << ","
        << m_bikeType << ","
        << (m_hasCarrier ? "1" : "0");
    return oss.str();
}

// ---------------------
// Getters
// ---------------------
const std::string& Bike::getBikeType() const noexcept
{
    return m_bikeType;
}

bool Bike::getHasCarrier() const noexcept
{
    return m_hasCarrier;
}
