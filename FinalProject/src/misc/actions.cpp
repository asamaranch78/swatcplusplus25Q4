#include "actions.h"
#include "car.h"
#include "truck.h"
#include "addCarWindow.h"
#include "addTruckWindow.h"
#include "enums.h"
#include "selectionList.h"

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
        default:
            throw;
    }
}

void addCar(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    AddCarWindow popUp(mainWin);
    std::shared_ptr<Car> newCar = std::make_shared<Car>();

    SelectionList window1(mainWin, FUEL_TYPE_TEXTS);
    uint8_t fuel = window1.handleList();
    newCar->fuelType = calculateFuelType(fuel);

    if (popUp.askForData()) {
        try { 
            popUp.saveToObject(newCar);
            data->addVehicle(newCar);
        }
        catch (...) {
        }
    }
}

void addTruck(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    AddTruckWindow popUp(mainWin);
    std::shared_ptr<Truck> newTruck = std::make_shared<Truck>();

    newTruck->fuelType = FuelTypes::DIESEL;

    if (popUp.askForData()) {
        try { 
            popUp.saveToObject(newTruck);
            data->addVehicle(newTruck);
        }
        catch (...) {
        }
    }
}

