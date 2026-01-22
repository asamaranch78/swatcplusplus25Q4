#include <memory>

#include "VehicleManager.h"
#include "Menu.h"

// (Opcional) preload: puedes hacerlo aquí o en Menu::run() si lo prefieres.
#include "Car.h"
#include "Truck.h"
#include "Bike.h"
#include "Motorcycle.h"

int main() {
    VehicleManager manager;

    // Preload opcional
    try {
        manager.addVehicle(std::make_unique<Car>(1, "Toyota", "Corolla", 2020, FuelType::Petrol, 1300.0, 4, 470.0));
        manager.addVehicle(std::make_unique<Truck>(10, "Volvo", "FH16", 2019, FuelType::Diesel, 8000.0, 20000.0, 5));
        manager.addVehicle(std::make_unique<Bike>(20, "Specialized", "Turbo Vado", 2024, FuelType::Electric, 22.5, "city", true));
        manager.addVehicle(std::make_unique<Motorcycle>(30, "Yamaha", "MT-07", 2021, FuelType::Petrol, 184.0, 689, false));
    } catch (...) {}

    Menu menu(manager);
    menu.run();
    return 0;
}
