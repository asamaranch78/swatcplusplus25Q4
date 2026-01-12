#include "mainWindow.h"
#include "constants.h"
#include "vehicle.h"
#include <cstddef>
#include <memory>
#include <string>

MainWindow::MainWindow(uint16_t windowHeight, uint16_t windowCenterX, uint16_t mainColor) :
    Window(windowHeight, SCREEN_WIDTH, 0, windowCenterX - (SCREEN_WIDTH/2), mainColor, true) {
    menuLine = windowHeight - MENU_OFFSET;
    separatorLine = windowHeight - (SEP_OFFSET);
    dataLines = windowHeight - 2 - (SEP_OFFSET);
}


void MainWindow::drawDisplayData(std::shared_ptr<DataSet> data) {
    uint8_t line {DATA_OFFSET};
    for (const auto & point: data->dataSet) {
        printVehicle(point, line);
        line++;
    }


}

void MainWindow::drawConstantPart(void) {
    for (std::size_t i = 1; i < SCREEN_WIDTH - 1; i++) {
         Window::print(separatorLine, i, "=", MAIN_COLOR);
    }

    Window::print(menuLine, WIDE_GAP, "A: Add\tD: Delete\tX: Export\tI: Import\t F:Filter\tQ: Quit", MENU_COLOR);

    Window::print(HEARDER_LINE, MANUFACTURER_COL, "Manufacturer", MAIN_COLOR);
    Window::print(HEARDER_LINE, MODEL_COL, "Model", MAIN_COLOR);
    Window::print(HEARDER_LINE, YEAR_COL, "Year", MAIN_COLOR);
    Window::print(HEARDER_LINE, WEIGHT_COL, "Weight", MAIN_COLOR);
    Window::print(HEARDER_LINE, FUEL_EFFI_COL, "Fuel Effi", MAIN_COLOR);
    Window::print(HEARDER_LINE, FUEL_TYPE_COL, "Fuel Type", MAIN_COLOR);
    Window::print(HEARDER_LINE, TYPE_COL, "Type", MAIN_COLOR);
    Window::print(HEARDER_LINE, SPECIAL_COL, "Special", MAIN_COLOR);
        
}

void MainWindow::printVehicle(std::shared_ptr<Vehicle> ptr, int8_t line) {
    Window::print(line, MANUFACTURER_COL, ptr->manufacturer, MAIN_COLOR);
    Window::print(line, MODEL_COL, ptr->model, MAIN_COLOR);
    Window::print(line, YEAR_COL, std::to_string(ptr->year), MAIN_COLOR);
    Window::print(line, WEIGHT_COL, std::to_string(ptr->weight), MAIN_COLOR);
    Window::print(line, FUEL_EFFI_COL, std::to_string(ptr->fuelEfficiency), MAIN_COLOR);
    Window::print(line, FUEL_TYPE_COL, ptr->getFuelType(), MAIN_COLOR);
    Window::print(line, TYPE_COL, ptr->getType(), MAIN_COLOR);
    Window::print(line, SPECIAL_COL, ptr->getSpecial(), MAIN_COLOR);

}

char MainWindow::checkKeyboardCmd() {
    return 'A';
}
