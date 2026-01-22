#include "enums.h"
#include "fuelActions.h"
#include "fuelWindow.h"
#include "elecFuelWindow.h"
#include "showError.h"
#include <cstdint>

void fuelEffiCalc(std::shared_ptr<Vehicle> vehicle, std::shared_ptr<MainWindow> mainWin) {
    if (vehicle->fuelType != FuelTypes::ELECTRIC) {
        normalFuelEffiCalc(vehicle, mainWin); 
    }
    else {
        electricFuelEffiCalc(vehicle, mainWin);
    }
}

void normalFuelEffiCalc(std::shared_ptr<Vehicle> vehicle, std::shared_ptr<MainWindow> mainWin) {
    FuelWindow popUp(mainWin);
    uint16_t kilometers;
    double liters;

    if (popUp.askForData()) {
        try {
            kilometers = popUp.getKilometers();
            liters = popUp.getLiters();
            vehicle->fuelEfficiencyCalc(kilometers, liters);
        }
        catch (const std::exception& e) {
            std::vector<std::string> message {};
            message.push_back("Data wrongly formatted or incomplete");
            message.push_back("");
            message.push_back("Triggered exception:");
            message.push_back(e.what());
            showError(message, mainWin);
        }
    }
}

void electricFuelEffiCalc(std::shared_ptr<Vehicle> vehicle, std::shared_ptr<MainWindow> mainWin) {
    ElecFuelWindow popUp(mainWin);
    uint16_t kilometers;
    double hours;

    if (popUp.askForData()) {
        try {
            kilometers = popUp.getKilometers();
            hours = popUp.getHours();
            vehicle->fuelEfficiencyCalc(kilometers, hours);
        }
        catch (const std::exception& e) {
            std::vector<std::string> message {};
            message.push_back("Data wrongly formatted or incomplete");
            message.push_back("");
            message.push_back("Triggered exception:");
            message.push_back(e.what());
            showError(message, mainWin);
        }
    }
}
