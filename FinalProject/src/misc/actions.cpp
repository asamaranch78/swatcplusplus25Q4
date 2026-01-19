#include "actions.h"
#include "car.h"
#include "addCarWindow.h"

#include <memory>

void addCar(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    AddCarWindow popUp(mainWin);
    std::shared_ptr<Car> newCar = std::make_shared<Car>();

    if (popUp.askForData()) {
        try { 
            popUp.saveToObject(newCar);
            data->addVehicle(newCar);
        }
        catch (...) {
        }
    }
}
