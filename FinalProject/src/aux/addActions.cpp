#include "addActions.h"
#include <exception>
#include "car.h"
#include "motorbike.h"
#include "showError.h"
#include "truck.h"
#include "addCarWindow.h"
#include "addTruckWindow.h"
#include "addMotorbikeWindow.h"
#include "addElectricWindow.h"
#include "enums.h"
#include "selectionList.h"
#include "showError.h"

#include <memory>

void addVehicle(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    SelectionList window1(mainWin, TYPES_TEXTS);
    uint8_t type = window1.handleList();
    switch (calculateType(type)) {
        case Types::CAR:
            addCar(data, mainWin);
            break;
        case Types::TRUCK:
            addTruck(data, mainWin);
            break;
        case Types::ELECTRIC_CAR:
            addElectric(data, mainWin);
            break;
        case Types::MOTORBIKE:
            addMotorbike(data, mainWin);
            break;
    }
}

void addCar(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    AddCarWindow popUp(mainWin);
    std::shared_ptr<Car> newCar = std::make_shared<Car>();

    SelectionList window1(mainWin, FUEL_TYPE_TEXTS);
    uint8_t fuel = window1.handleList();
    newCar->fuelType = calculateFuelType(fuel);
    newCar->type = Types::CAR;

    if (popUp.askForData()) {
        try { 
            popUp.saveToObject(newCar);
            data->addVehicle(newCar);
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

void addTruck(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    AddTruckWindow popUp(mainWin);
    std::shared_ptr<Truck> newTruck = std::make_shared<Truck>();

    newTruck->fuelType = FuelTypes::DIESEL;
    newTruck->type = Types::TRUCK;

    if (popUp.askForData()) {
        try { 
            popUp.saveToObject(newTruck);
            data->addVehicle(newTruck);
        }
        catch (const std::exception& e) {
            badInputError(e.what(), mainWin);
        }
    }
}

void addElectric(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    AddElectricWindow popUp(mainWin);
    std::shared_ptr<Electric> newElectric = std::make_shared<Electric>();

    newElectric->fuelType = FuelTypes::ELECTRIC;
    newElectric->type = Types::ELECTRIC_CAR;

    if (popUp.askForData()) {
        try { 
            popUp.saveToObject(newElectric);
            data->addVehicle(newElectric);
        }
        catch (const std::exception& e) {
            badInputError(e.what(), mainWin);
        }
    }
}

void addMotorbike(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    AddMotorbikeWindow popUp(mainWin);
    std::shared_ptr<Motorbike> newMotorbike = std::make_shared<Motorbike>();

    SelectionList window1(mainWin, FUEL_TYPE_TEXTS);
    uint8_t fuel = window1.handleList();
    newMotorbike->fuelType = calculateFuelType(fuel);
    newMotorbike->type = Types::MOTORBIKE;

    if (popUp.askForData()) {
        try { 
            popUp.saveToObject(newMotorbike);
            data->addVehicle(newMotorbike);
        }
        catch (const std::exception& e) {
            badInputError(e.what(), mainWin);
        }
    }
}
