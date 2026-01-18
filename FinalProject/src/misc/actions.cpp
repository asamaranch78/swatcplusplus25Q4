#include "actions.h"
#include "car.h"
#include "addCarWindow.h"

#include <cstdlib>
#include <memory>

void addCar(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    AddCarWindow popUp(mainWin);
    std::shared_ptr<Car> newCar = std::make_shared<Car>();
    system("touch file1");

    popUp.askForData();
    system("touch file2");
    popUp.saveToObject(newCar);
    data->addVehicle(newCar);
}
