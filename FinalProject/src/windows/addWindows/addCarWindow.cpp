#include "addCarWindow.h"
#include "constants.h"
#include "stringManip.h"

AddCarWindow::AddCarWindow(std::shared_ptr<MainWindow> mainWin) :
    FormWindow(mainWin,7) {
    inputNames.push_back("Manufacturer:");
    inputNames.push_back("Model:");
    inputNames.push_back("Year:");
    inputNames.push_back("Weight:");
    inputNames.push_back("Fuel Effi:");
    inputNames.push_back("Doors:");
    inputNames.push_back("Trunk cap.:");
}

void AddCarWindow::saveToObject(std::shared_ptr<Car> car) {
    car->manufacturer = cleanUp(field_buffer(inputFields[MANUFACTURER_INDEX], 0));
    car->model = cleanUp(field_buffer(inputFields[MODEL_INDEX], 0));
    car->year = std::stoi(field_buffer(inputFields[YEAR_INDEX], 0));
    car->weight = std::stoi(field_buffer(inputFields[WEIGHT_INDEX], 0));
    car->fuelEfficiency = std::stof(field_buffer(inputFields[EFFICIENCY_INDEX], 0));

    car->doors = std::stoi(field_buffer(inputFields[DOORS_INDEX], 0));
    car->trunkCapacity = std::stoi(field_buffer(inputFields[TRUNK_INDEX], 0));

}
