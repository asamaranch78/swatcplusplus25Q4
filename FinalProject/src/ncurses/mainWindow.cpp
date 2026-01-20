#include "mainWindow.h"
#include "constants.h"
#include "vehicle.h"
#include "window.h"
#include "actions.h"
#include <cstddef>
#include <iterator>
#include <memory>
#include <panel.h>
#include <string>

MainWindow::MainWindow(uint16_t windowHeight, uint16_t windowCenterX, uint16_t mainColor) :
    Window(windowHeight, SCREEN_WIDTH, windowCenterX - (SCREEN_WIDTH/2), 0, mainColor, true) {
    centerX = windowCenterX;
    centerY = windowHeight/2;
    menuLine = windowHeight - MENU_OFFSET;
    separatorLine = windowHeight - (SEP_OFFSET);
    dataLines = windowHeight - 2 - (SEP_OFFSET);
    cursor = DATA_OFFSET;
    cursorMin = DATA_OFFSET;
    panel = new_panel(window);
}

void MainWindow::refresh() {
    update_panels();
    Window::refresh();
}

void MainWindow::drawDisplayData(std::shared_ptr<DataSet> data) {
    uint8_t line {DATA_OFFSET};
    for (const auto & point: data->dataSet) {
        if (line == cursor) {
            Window::changeColor(SELECTED_COLOR);
        }
        printBlankLine(line);
        printVehicle(point, line);
        if (line == cursor) { Window::removeColor(SELECTED_COLOR); }
        line++;
    }
    cursorMax = line - 1;
}

void MainWindow::drawConstantPart(void) {
    for (std::size_t i = 1; i < SCREEN_WIDTH - 1; i++) {
         Window::print(separatorLine, i, "=");
    }
    Window::changeColor(MENU_COLOR);
    Window::print(menuLine, WIDE_GAP, "A: Add\tD: Delete\tX: Export\tI: Import\t F:Filter\tQ: Quit");
    Window::removeColor(MENU_COLOR);

    Window::print(HEARDER_LINE, MANUFACTURER_COL, "Manufacturer");
    Window::print(HEARDER_LINE, MODEL_COL, "Model");
    Window::print(HEARDER_LINE, YEAR_COL, "Year");
    Window::print(HEARDER_LINE, WEIGHT_COL, "Weight");
    Window::print(HEARDER_LINE, FUEL_EFFI_COL, "Fuel Effi");
    Window::print(HEARDER_LINE, FUEL_TYPE_COL, "Fuel Type");
    Window::print(HEARDER_LINE, TYPE_COL, "Type");
    Window::print(HEARDER_LINE, SPECIAL_COL, "Special");
        
}

void MainWindow::printVehicle(std::shared_ptr<Vehicle> ptr, int8_t line) {
    Window::print(line, MANUFACTURER_COL, ptr->manufacturer);
    Window::print(line, MODEL_COL, ptr->model);
    Window::print(line, YEAR_COL, std::to_string(ptr->year));
    Window::print(line, WEIGHT_COL, std::to_string(ptr->weight));
    Window::print(line, FUEL_EFFI_COL, std::to_string(ptr->fuelEfficiency));
    Window::print(line, FUEL_TYPE_COL, ptr->getFuelType());
    Window::print(line, TYPE_COL, ptr->getType());
    Window::print(line, SPECIAL_COL, ptr->getSpecial());

}

bool MainWindow::listenKeyboard(void) {
    pressedKey = getch();

    if (pressedKey == 'q' || pressedKey == 'Q') {
        return false;
    }
    else {
        return true;
    }
}

void MainWindow::cursorDown() {
    cursor++;
    if (cursor > cursorMax) { cursor = cursorMax; }
}

void MainWindow::cursorUp() {
    cursor--;
    if (cursor < cursorMin) { cursor = cursorMin; }
}
