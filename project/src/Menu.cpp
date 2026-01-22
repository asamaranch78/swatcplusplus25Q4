#include "Menu.h"

#include "VehicleManager.h"
#include "CsvRepository.h"
#include "Car.h"
#include "Truck.h"
#include "Bike.h"
#include "Motorcycle.h"
#include "Vehicle.h" // FuelType

#include <iostream>
#include <limits>
#include <memory>
#include <vector>

// ---------------------
// Ctor
// ---------------------
Menu::Menu(VehicleManager& manager)
    : m_manager(manager)
{}

// ---------------------
// Public API
// ---------------------
void Menu::run()
{
    while (true) {
        try {
            std::cout << "\n=============================\n";
            std::cout << "   VEHICLE MANAGEMENT MENU\n";
            std::cout << "=============================\n";
            std::cout << "1) Add vehicle\n";
            std::cout << "2) List vehicles\n";
            std::cout << "3) Sort vehicles\n";
            std::cout << "4) Filter vehicles\n";
            std::cout << "5) Find by ID\n";
            std::cout << "6) Save to CSV\n";
            std::cout << "7) Load from CSV\n";
            std::cout << "0) Exit\n";

            const int opt = readMenuOption();

            switch (opt) {
                case 1: actionAddVehicle(); break;
                case 2: actionListVehicles(); break;
                case 3: actionSortVehicles(); break;
                case 4: actionFilterVehicles(); break;
                case 5: actionFindById(); break;
                case 6: actionSave(); break;
                case 7: actionLoad(); break;
                case 0:
                    std::cout << "Bye!\n";
                    return;
                default:
                    std::cout << "Invalid option.\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}

// ---------------------
// Actions
// ---------------------
void Menu::actionAddVehicle()
{
    std::cout << "\n=== ADD VEHICLE ===\n";

    const int type = readVehicleType();

    // Common fields
    const int id = readInt("ID (int > 0): ");
    const std::string brand = readLine("Brand: ");
    const std::string model = readLine("Model: ");
    const int year = readInt("Year: ");
    const FuelType fuel = readFuelType();
    const double weight = readDouble("Weight (kg): ");

    std::unique_ptr<Vehicle> v;

    if (type == 1) {
        const int doors = readInt("Number of doors (2-6): ");
        const double trunk = readDouble("Trunk capacity (liters): ");
        v = std::make_unique<Car>(id, brand, model, year, fuel, weight, doors, trunk);
    }
    else if (type == 2) {
        const double payload = readDouble("Payload capacity (kg): ");
        const int axles = readInt("Number of axles (2-10): ");
        v = std::make_unique<Truck>(id, brand, model, year, fuel, weight, payload, axles);
    }
    else if (type == 3) {
        const std::string bikeType = readLine("Bike type (road/mountain/hybrid/bmx/city): ");
        const bool carrier = readBool01("Has carrier");
        v = std::make_unique<Bike>(id, brand, model, year, fuel, weight, bikeType, carrier);
    }
    else if (type == 4) {
        const int cc = readInt("Engine displacement (cc): ");
        const bool sidecar = readBool01("Has sidecar");
        v = std::make_unique<Motorcycle>(id, brand, model, year, fuel, weight, cc, sidecar);
    }
    else {
        std::cout << " Invalid type.\n";
        return;
    }

    m_manager.addVehicle(std::move(v));
    const Vehicle* added = m_manager.findById(id);
    std::cout << " Vehicle added. (Efficiency computed: "
              << (added ? added->fuelEfficiency() : 0.0) << ")\n";
}

void Menu::actionListVehicles() const
{
    std::cout << "\n=== LIST VEHICLES ===\n";
    const auto list = m_manager.listVehicleInfo();
    if (list.empty()) {
        std::cout << "(No vehicles)\n";
        return;
    }
    for (const auto& s : list) std::cout << s << "\n";
}

void Menu::actionSortVehicles()
{
    std::cout << "\n=== SORT VEHICLES ===\n";
    const int opt = readSortOption();

    switch (opt) {
        case 1: m_manager.sortByYear(true); break;
        case 2: m_manager.sortByYear(false); break;
        case 3: m_manager.sortByFuelEfficiency(false); break;
        case 4: m_manager.sortByFuelEfficiency(true); break;
        case 5: m_manager.sortByBrand(true); break;
        case 6: m_manager.sortByBrand(false); break;
        default:
            std::cout << " Invalid option.\n";
            return;
    }
    std::cout << " Sorted.\n";
}

void Menu::actionFilterVehicles() const
{
    std::cout << "\n=== FILTER VEHICLES ===\n";
    const int opt = readFilterOption();

    std::vector<const Vehicle*> result;

    if (opt == 1) {
        const std::string b = readLine("Brand: ");
        result = m_manager.filterByBrand(b);
    } else if (opt == 2) {
        const FuelType f = readFuelType();
        result = m_manager.filterByFuelType(f);
    } else if (opt == 3) {
        const int y1 = readInt("Year min: ");
        const int y2 = readInt("Year max: ");
        result = m_manager.filterByYearRange(y1, y2);
    } else {
        std::cout << " Invalid option.\n";
        return;
    }

    if (result.empty()) {
        std::cout << "(No matches)\n";
        return;
    }

    for (const auto* v : result) std::cout << v->info() << "\n";
}

void Menu::actionFindById() const
{
    std::cout << "\n=== FIND BY ID ===\n";
    const int id = readInt("ID: ");
    const Vehicle* v = m_manager.findById(id);
    if (!v) {
        std::cout << "Not found.\n";
        return;
    }
    std::cout << v->info() << "\n";
}

void Menu::actionSave() const
{
    std::cout << "\n=== SAVE CSV ===\n";
    const std::string file = readLine("Filename (e.g., vehicles.csv): ");
    CsvRepository::save(m_manager, file);
    std::cout << " Saved to " << file << "\n";
}

void Menu::actionLoad()
{
    std::cout << "\n=== LOAD CSV ===\n";
    const std::string file = readLine("Filename (e.g., vehicles.csv): ");
    CsvRepository::load(m_manager, file);
    std::cout << " Loaded from " << file << "\n";
}

// ---------------------
// Input helpers
// ---------------------
void Menu::clearCin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Menu::readInt(const std::string& prompt)
{
    while (true) {
        std::cout << prompt;
        int v;
        if (std::cin >> v) {
            clearCin();
            return v;
        }
        std::cout << " Invalid integer. Try again.\n";
        clearCin();
    }
}

double Menu::readDouble(const std::string& prompt)
{
    while (true) {
        std::cout << prompt;
        double v;
        if (std::cin >> v) {
            clearCin();
            return v;
        }
        std::cout << " Invalid number. Try again.\n";
        clearCin();
    }
}

bool Menu::readBool01(const std::string& prompt)
{
    while (true) {
        const int v = readInt(prompt + " (0=No, 1=Yes): ");
        if (v == 0) return false;
        if (v == 1) return true;
        std::cout << " Please enter 0 or 1.\n";
    }
}

std::string Menu::readLine(const std::string& prompt)
{
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s);
    return s;
}

// ---------------------
// Menu option helpers
// ---------------------
int Menu::readVehicleType()
{
    std::cout << "Type: 1=Car, 2=Truck, 3=Bike, 4=Motorcycle\n";
    return readInt("Choose type: ");
}

int Menu::readSortOption()
{
    std::cout << "1=Year (asc)\n2=Year (desc)\n3=Efficiency (desc)\n4=Efficiency (asc)\n5=Brand (asc)\n6=Brand (desc)\n";
    return readInt("Choose option: ");
}

int Menu::readFilterOption()
{
    std::cout << "1=By brand\n2=By fuel type\n3=By year range\n";
    return readInt("Choose option: ");
}

int Menu::readFuelTypeOption()
{
    std::cout << "FuelType: 1=Petrol, 2=Diesel, 3=Electric\n";
    return readInt("Choose fuel type: ");
}

int Menu::readMenuOption()
{
    return readInt("Choose option: ");
}

FuelType Menu::readFuelType()
{
    while (true) {
        const int choice = readFuelTypeOption();
        switch (choice) {
            case 1: return FuelType::Petrol;
            case 2: return FuelType::Diesel;
            case 3: return FuelType::Electric;
            default:
                std::cout << " Invalid fuel type.\n";
                break;
        }
    }
}
