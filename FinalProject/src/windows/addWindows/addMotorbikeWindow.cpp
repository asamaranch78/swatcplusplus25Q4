#include "addMotorbikeWindow.h"
#include "stringManip.h"

AddMotorbikeWindow::AddMotorbikeWindow(std::shared_ptr<MainWindow> mainWin) :
    FormWindow(mainWin, 6) {
    inputNames.push_back("Manufacturer:");
    inputNames.push_back("Model:");
    inputNames.push_back("Year:");
    inputNames.push_back("Weight:");
    inputNames.push_back("Fuel Effi:");
    inputNames.push_back("Seats: ");
}


void AddMotorbikeWindow::saveToObject(std::shared_ptr<Motorbike> motorbike) {
    motorbike->manufacturer = cleanUp(field_buffer(inputFields[MANUFACTURER_INDEX], 0));
    motorbike->model = cleanUp(field_buffer(inputFields[MODEL_INDEX], 0));
    motorbike->year = std::stoi(field_buffer(inputFields[YEAR_INDEX], 0));
    motorbike->weight = std::stoi(field_buffer(inputFields[WEIGHT_INDEX], 0));
    motorbike->fuelEfficiency = std::stof(field_buffer(inputFields[EFFICIENCY_INDEX], 0));

    motorbike->seats = std::stoi(field_buffer(inputFields[SEATS_INDEX],0));
}
