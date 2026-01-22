#include "addTruckWindow.h"
#include "constants.h"
#include "stringManip.h"

AddTruckWindow::AddTruckWindow(std::shared_ptr<MainWindow> mainWin) :
    FormWindow(mainWin, 7) {
    inputNames.push_back("Manufacturer:");
    inputNames.push_back("Model:");
    inputNames.push_back("Year:");
    inputNames.push_back("Weight:");
    inputNames.push_back("Fuel Effi:");
    inputNames.push_back("Axles:");
    inputNames.push_back("Payload cap.:");
}

void AddTruckWindow::saveToObject(std::shared_ptr<Truck> truck) {
    truck->manufacturer = cleanUp(field_buffer(inputFields[MANUFACTURER_INDEX], 0));
    truck->model = cleanUp(field_buffer(inputFields[MODEL_INDEX], 0));
    truck->year = std::stoi(field_buffer(inputFields[YEAR_INDEX], 0));
    truck->weight = std::stoi(field_buffer(inputFields[WEIGHT_INDEX], 0));
    truck->fuelEfficiency = std::stof(field_buffer(inputFields[EFFICIENCY_INDEX], 0));

    truck->axles = std::stoi(field_buffer(inputFields[AXLE_INDEX], 0));
    truck->payloadCapacity = std::stoi(field_buffer(inputFields[LOAD_INDEX], 0));

}
