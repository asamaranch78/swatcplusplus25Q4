#ifndef CSV_REPOSITORY_H
#define CSV_REPOSITORY_H

#include <string>

class VehicleManager;

class CsvRepository {
public:
    // Guarda todos los vehículos del manager en un CSV.
    static void save(const VehicleManager& manager, const std::string& filename);

    // Carga vehículos desde CSV y los añade al manager (no borra lo existente).
    static void load(VehicleManager& manager, const std::string& filename);
};

#endif // CSV_REPOSITORY_H
