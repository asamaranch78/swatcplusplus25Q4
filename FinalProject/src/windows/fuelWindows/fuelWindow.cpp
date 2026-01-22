#include "fuelWindow.h"

FuelWindow::FuelWindow(std::shared_ptr<MainWindow> mainWin) :
    FormWindow(mainWin,2) {
    inputNames.push_back("Kilometers:");
    inputNames.push_back("Liters:");
}

int16_t FuelWindow::getKilometers(void) {
    return std::stoi(field_buffer(inputFields[0], 0));
}

double FuelWindow::getLiters(void) {
    return std::stof(field_buffer(inputFields[1], 0));
}
