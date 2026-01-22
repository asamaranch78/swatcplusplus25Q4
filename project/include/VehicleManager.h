#ifndef VEHICLE_MANAGER_H
#define VEHICLE_MANAGER_H

#include <memory>
#include <string>
#include <vector>

#include "Vehicle.h"

// =====================
// Class: VehicleManager
// =====================
// Responsabilidad:
// - Mantener una colección de Vehicle (polimórfica)
// - Añadir, listar, ordenar y filtrar
//
// Nota: No hace UI (no pide input), no guarda/carga CSV.
class VehicleManager {
public:
    VehicleManager() = default;

    // --- Add ---
    // Añade un vehículo ya construido (ownership por unique_ptr).
    // Lanza std::invalid_argument si el puntero es null o el ID ya existe.
    void addVehicle(std::unique_ptr<Vehicle> v);

    // --- List ---
    // Devuelve un vector de strings con la info() de cada vehículo.
    std::vector<std::string> listVehicleInfo() const;

    // Devuelve número de vehículos
    std::size_t size() const noexcept;

    // --- Sort (in-place) ---
    // ascending=true orden ascendente, false descendente
    void sortByYear(bool ascending = true);
    void sortByFuelEfficiency(bool ascending = false); // por defecto: más eficiente primero
    void sortByBrand(bool ascending = true);

    // --- Filter (no modifica la colección) ---
    // Devuelve punteros const a los vehículos que cumplen el filtro.
    std::vector<const Vehicle*> filterByBrand(const std::string& brand) const;
    std::vector<const Vehicle*> filterByFuelType(FuelType fuelType) const;
    std::vector<const Vehicle*> filterByYearRange(int yearMin, int yearMax) const;

    // --- Search (rápido, opcional pero útil) ---
    // Devuelve nullptr si no existe.
    const Vehicle* findById(int id) const;

    std::vector<const Vehicle*> getAll() const;


private:
    bool idExists(int id) const;

    std::vector<std::unique_ptr<Vehicle>> m_vehicles;
};

#endif // VEHICLE_MANAGER_H
