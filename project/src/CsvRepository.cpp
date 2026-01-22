#include "CsvRepository.h"

#include "VehicleManager.h"
#include "Car.h"
#include "Truck.h"
#include "Bike.h"
#include "Motorcycle.h"
#include "Vehicle.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

namespace {

// Trim
std::string trimCopy(std::string s) {
    auto notSpace = [](unsigned char ch) { return !std::isspace(ch); };
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), notSpace));
    s.erase(std::find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
    return s;
}

// CSV simple: split por coma (sin soporte de comillas escapadas).
std::vector<std::string> splitCsvSimple(const std::string& line) {
    std::vector<std::string> parts;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, ',')) {
        parts.push_back(trimCopy(item));
    }
    return parts;
}

int toIntStrict(const std::string& s, const std::string& field, int lineNo) {
    try {
        size_t idx = 0;
        int v = std::stoi(s, &idx);
        if (idx != s.size()) throw std::invalid_argument("trailing chars");
        return v;
    } catch (...) {
        throw std::invalid_argument(
            "CSV load error (line " + std::to_string(lineNo) +
            "): invalid int for '" + field + "': '" + s + "'"
        );
    }
}

double toDoubleStrict(const std::string& s, const std::string& field, int lineNo) {
    try {
        size_t idx = 0;
        double v = std::stod(s, &idx);
        if (idx != s.size()) throw std::invalid_argument("trailing chars");
        return v;
    } catch (...) {
        throw std::invalid_argument(
            "CSV load error (line " + std::to_string(lineNo) +
            "): invalid double for '" + field + "': '" + s + "'"
        );
    }
}

bool toBool01(const std::string& s, const std::string& field, int lineNo) {
    const std::string v = s;
    if (v == "1" || v == "true" || v == "TRUE" || v == "True") return true;
    if (v == "0" || v == "false" || v == "FALSE" || v == "False") return false;

    throw std::invalid_argument(
        "CSV load error (line " + std::to_string(lineNo) +
        "): invalid bool for '" + field + "': '" + s + "' (use 0/1)"
    );
}

} // namespace

// ---------------------
// SAVE
// ---------------------
void CsvRepository::save(const VehicleManager& manager, const std::string& filename)
{
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw std::runtime_error("CsvRepository::save: cannot open file: " + filename);
    }

    // Header humano (opcional)
    out << "id,type,brand,model,year,fuelType,weightKg,spec1,spec2\n";

    for (const Vehicle* v : manager.getAll()) {
        out << v->toCsvRow() << "\n";
    }
}

// ---------------------
// LOAD (COMPLETO)
// ---------------------
void CsvRepository::load(VehicleManager& manager, const std::string& filename)
{
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw std::runtime_error("CsvRepository::load: cannot open file: " + filename);
    }

    std::string line;
    int lineNo = 0;
    bool headerSkipped = false;

    while (std::getline(in, line)) {
        ++lineNo;

        line = trimCopy(line);
        if (line.empty()) continue;

        // Saltar header si existe
        if (!headerSkipped) {
            headerSkipped = true;
            if (line.rfind("id,type", 0) == 0) {
                continue;
            }
        }

        const auto cols = splitCsvSimple(line);

        // Mínimo: id,type,brand,model,year,fuelType,weightKg
        if (cols.size() < 7) {
            throw std::invalid_argument(
                "CSV load error (line " + std::to_string(lineNo) +
                "): not enough columns (need >=7): " + line
            );
        }

        const int id = toIntStrict(cols[0], "id", lineNo);
        const std::string type = cols[1];
        const std::string brand = cols[2];
        const std::string model = cols[3];
        const int year = toIntStrict(cols[4], "year", lineNo);
        const FuelType fuel = fuelTypeFromString(cols[5]); // ya lanza invalid_argument si es inválido
        const double weightKg = toDoubleStrict(cols[6], "weightKg", lineNo);

        // Cada tipo requiere 2 campos extra => total 9 columnas
        if (cols.size() < 9) {
            throw std::invalid_argument(
                "CSV load error (line " + std::to_string(lineNo) +
                "): type '" + type + "' needs 9 columns: " + line
            );
        }

        if (type == "Car") {
            const int numDoors = toIntStrict(cols[7], "numDoors", lineNo);
            const double trunk = toDoubleStrict(cols[8], "trunkCapacityLiters", lineNo);

            manager.addVehicle(std::make_unique<Car>(
                id, brand, model, year, fuel, weightKg, numDoors, trunk
            ));
        }
        else if (type == "Truck") {
            const double payload = toDoubleStrict(cols[7], "payloadCapacityKg", lineNo);
            const int axles = toIntStrict(cols[8], "numAxles", lineNo);

            manager.addVehicle(std::make_unique<Truck>(
                id, brand, model, year, fuel, weightKg, payload, axles
            ));
        }
        else if (type == "Bike") {
            const std::string bikeType = cols[7];
            const bool hasCarrier = toBool01(cols[8], "hasCarrier", lineNo);

            manager.addVehicle(std::make_unique<Bike>(
                id, brand, model, year, fuel, weightKg, bikeType, hasCarrier
            ));
        }
        else if (type == "Motorcycle") {
            const int cc = toIntStrict(cols[7], "engineDisplacementCc", lineNo);
            const bool sidecar = toBool01(cols[8], "hasSidecar", lineNo);

            manager.addVehicle(std::make_unique<Motorcycle>(
                id, brand, model, year, fuel, weightKg, cc, sidecar
            ));
        }
        else {
            throw std::invalid_argument(
                "CSV load error (line " + std::to_string(lineNo) +
                "): unknown type '" + type + "'"
            );
        }
    }
}
