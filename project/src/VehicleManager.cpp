// src/VehicleManager.cpp
#include "VehicleManager.h"

#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace {
static std::string toLowerCopy(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}
} // namespace

bool VehicleManager::idExists(int id) const
{
    return std::any_of(m_vehicles.begin(), m_vehicles.end(),
                       [id](const std::unique_ptr<Vehicle>& v) {
                           return v && v->getId() == id;
                       });
}

void VehicleManager::addVehicle(std::unique_ptr<Vehicle> v)
{
    if (!v) {
        throw std::invalid_argument("VehicleManager::addVehicle: null vehicle pointer");
    }
    if (idExists(v->getId())) {
        throw std::invalid_argument("VehicleManager::addVehicle: duplicate id=" + std::to_string(v->getId()));
    }
    m_vehicles.push_back(std::move(v));
}

std::vector<std::string> VehicleManager::listVehicleInfo() const
{
    std::vector<std::string> out;
    out.reserve(m_vehicles.size());

    for (const auto& v : m_vehicles) {
        if (v) out.push_back(v->info());
    }
    return out;
}

std::size_t VehicleManager::size() const noexcept
{
    return m_vehicles.size();
}

void VehicleManager::sortByYear(bool ascending)
{
    std::sort(m_vehicles.begin(), m_vehicles.end(),
              [ascending](const std::unique_ptr<Vehicle>& a,
                          const std::unique_ptr<Vehicle>& b) {
                  if (!a) return false;
                  if (!b) return true;
                  return ascending ? (a->getYear() < b->getYear())
                                   : (a->getYear() > b->getYear());
              });
}

void VehicleManager::sortByFuelEfficiency(bool ascending)
{
    std::sort(m_vehicles.begin(), m_vehicles.end(),
              [ascending](const std::unique_ptr<Vehicle>& a,
                          const std::unique_ptr<Vehicle>& b) {
                  if (!a) return false;
                  if (!b) return true;
                  const double ea = a->fuelEfficiency();
                  const double eb = b->fuelEfficiency();
                  return ascending ? (ea < eb) : (ea > eb);
              });
}

void VehicleManager::sortByBrand(bool ascending)
{
    std::sort(m_vehicles.begin(), m_vehicles.end(),
              [ascending](const std::unique_ptr<Vehicle>& a,
                          const std::unique_ptr<Vehicle>& b) {
                  if (!a) return false;
                  if (!b) return true;
                  const std::string ba = toLowerCopy(a->getBrand());
                  const std::string bb = toLowerCopy(b->getBrand());
                  return ascending ? (ba < bb) : (ba > bb);
              });
}

std::vector<const Vehicle*> VehicleManager::filterByBrand(const std::string& brand) const
{
    const std::string needle = toLowerCopy(brand);
    std::vector<const Vehicle*> out;

    for (const auto& v : m_vehicles) {
        if (!v) continue;
        if (toLowerCopy(v->getBrand()) == needle) {
            out.push_back(v.get());
        }
    }
    return out;
}

std::vector<const Vehicle*> VehicleManager::filterByFuelType(FuelType fuelType) const
{
    std::vector<const Vehicle*> out;

    for (const auto& v : m_vehicles) {
        if (!v) continue;
        if (v->getFuelType() == fuelType) {
            out.push_back(v.get());
        }
    }
    return out;
}

std::vector<const Vehicle*> VehicleManager::filterByYearRange(int yearMin, int yearMax) const
{
    if (yearMin > yearMax) {
        throw std::invalid_argument("VehicleManager::filterByYearRange: yearMin > yearMax");
    }

    std::vector<const Vehicle*> out;

    for (const auto& v : m_vehicles) {
        if (!v) continue;
        const int y = v->getYear();
        if (y >= yearMin && y <= yearMax) {
            out.push_back(v.get());
        }
    }
    return out;
}

const Vehicle* VehicleManager::findById(int id) const
{
    auto it = std::find_if(m_vehicles.begin(), m_vehicles.end(),
                           [id](const std::unique_ptr<Vehicle>& v) {
                               return v && v->getId() == id;
                           });

    return (it != m_vehicles.end()) ? it->get() : nullptr;
}
std::vector<const Vehicle*> VehicleManager::getAll() const
{
    std::vector<const Vehicle*> out;
    out.reserve(m_vehicles.size());
    for (const auto& v : m_vehicles) {
        if (v) out.push_back(v.get());
    }
    return out;
}
