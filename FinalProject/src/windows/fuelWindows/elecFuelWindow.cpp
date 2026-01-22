#include "elecFuelWindow.h"

ElecFuelWindow::ElecFuelWindow(std::shared_ptr<MainWindow> mainWin) :
    FormWindow(mainWin,2) {
    inputNames.push_back("Kilometers:");
    inputNames.push_back("Charging hours:");
}

int16_t ElecFuelWindow::getKilometers(void) {
    return std::stoi(field_buffer(inputFields[0], 0));
}

double ElecFuelWindow::getHours(void) {
    return std::stof(field_buffer(inputFields[1], 0));
}
