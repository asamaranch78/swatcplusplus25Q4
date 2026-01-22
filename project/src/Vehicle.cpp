// Vehicle.cpp
#include "Vehicle.h"

#include <algorithm>
#include <cctype>
#include <chrono>
#include <ctime>
#include <stdexcept>
#include <string>

namespace {

// Trim helpers
inline void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        [](unsigned char ch) { return !std::isspace(ch); }));
}

inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
        [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
}

inline std::string trimCopy(std::string s) {
    ltrim(s);
    rtrim(s);
    return s;
}

inline std::string toLowerCopy(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}

inline int currentYear() {
    using namespace std::chrono;
    const auto now = system_clock::now();
    const std::time_t t = system_clock::to_time_t(now);

    std::tm tmLocal{};
#if defined(_WIN32)
    localtime_s(&tmLocal, &t);
#else
    tmLocal = *std::localtime(&t);
#endif
    return tmLocal.tm_year + 1900;
}

} // namespace

// =====================
// FuelType helpers
// =====================
std::string fuelTypeToString(FuelType type)
{
    switch (type) {
        case FuelType::Petrol:   return "Petrol";
        case FuelType::Diesel:   return "Diesel";
        case FuelType::Electric: return "Electric";
        default:                 return "Unknown";
    }
}

FuelType fuelTypeFromString(const std::string& value)
{
    const std::string v = toLowerCopy(trimCopy(value));

    // Aceptamos variantes comunes para robustez
    if (v == "petrol" || v == "gasoline" || v == "gas" || v == "benzine") {
        return FuelType::Petrol;
    }
    if (v == "diesel") {
        return FuelType::Diesel;
    }
    if (v == "electric" || v == "ev" || v == "battery") {
        return FuelType::Electric;
    }

    throw std::invalid_argument("Invalid FuelType string: '" + value + "'");
}

// =====================
// Vehicle implementation
// =====================
Vehicle::Vehicle(int id,
                 const std::string& brand,
                 const std::string& model,
                 int year,
                 FuelType fuelType,
                 double weightKg)
    : m_id(id),
      m_brand(brand),
      m_model(model),
      m_year(year),
      m_fuelType(fuelType),
      m_weightKg(weightKg)
{
    validateBaseData(id, brand, model, year, weightKg);
}

void Vehicle::validateBaseData(int id,
                               const std::string& brand,
                               const std::string& model,
                               int year,
                               double weightKg)
{
    if (id <= 0) {
        throw std::invalid_argument("Vehicle id must be > 0");
    }

    const std::string b = trimCopy(brand);
    const std::string m = trimCopy(model);

    if (b.empty()) {
        throw std::invalid_argument("Vehicle brand must not be empty");
    }
    if (m.empty()) {
        throw std::invalid_argument("Vehicle model must not be empty");
    }

    // Año del primer coche (Benz Patent-Motorwagen): 1886
    const int minYear = 1886;
    const int maxYear = currentYear() + 1; // permitimos año próximo (model year)

    if (year < minYear || year > maxYear) {
        throw std::invalid_argument(
            "Vehicle year out of range. Allowed: [" +
            std::to_string(minYear) + ", " + std::to_string(maxYear) + "]"
        );
    }

    if (weightKg <= 0.0) {
        throw std::invalid_argument("Vehicle weightKg must be > 0");
    }
}

// =====================
// Getters (declared in .h)
// =====================
int Vehicle::getId() const noexcept { return m_id; }

const std::string& Vehicle::getBrand() const noexcept { return m_brand; }

const std::string& Vehicle::getModel() const noexcept { return m_model; }

int Vehicle::getYear() const noexcept { return m_year; }

FuelType Vehicle::getFuelType() const noexcept { return m_fuelType; }

double Vehicle::getWeightKg() const noexcept { return m_weightKg; }
