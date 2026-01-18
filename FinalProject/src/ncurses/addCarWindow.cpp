#include "addCarWindow.h"
#include "constants.h"
#include "formDriver.h"
#include "popUpWindow.h"
#include <cstdlib>
#include <form.h>
#include <ncurses.h>
#include <string>

AddCarWindow::AddCarWindow(std::shared_ptr<MainWindow> mainWin) :
    PopUpWindow(WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_COLOR, mainWin),
    FormDriver(PopUpWindow::window) {
    int16_t fieldRow;
    for (size_t i=0; i < NUMBER_OF_FIELDS; i++) {
        fieldRow = FORM_START + FORM_SPACE * 2;
        inputFields[i] = new_field(FORM_HEIGHT, FORM_WIDTH, fieldRow, FORM_COL, NO_OFF_SCREEN, NO_BUFFERS);
        field_opts_off(inputFields[i], O_AUTOSKIP);
        set_field_back(inputFields[i], COLOR_PAIR(INPUT_COLOR));
    }
    inputFields[NUMBER_OF_FIELDS] = NULL;

    inputNames.push_back("Manufacturer:");
    inputNames.push_back("Model:");
    inputNames.push_back("Year:");
    inputNames.push_back("Weight:");
    inputNames.push_back("Fuel Effi:");
    inputNames.push_back("Doors:");
    inputNames.push_back("Trunk cap.:");
}

void AddCarWindow::askForData(void) {
    putOnTop();
    system("touch file9");
    FormDriver::createForm(inputFields, inputNames);
    system("touch file8");
    FormDriver::handleFrom();
    FormDriver::destroyForm();
}

void AddCarWindow::saveToObject(std::shared_ptr<Car> car) {
    car->manufacturer = field_buffer(inputFields[MANUFACTURER_INDEX], 0);
    car->model = field_buffer(inputFields[MODEL_INDEX], 0);
    car->year = std::stoi(field_buffer(inputFields[YEAR_INDEX], 0));
    car->weight = std::stoi(field_buffer(inputFields[WEIGHT_INDEX], 0));
    car->fuelEfficiency = std::stof(field_buffer(inputFields[EFFICIENCY_INDEX], 0));

    car->doors = std::stoi(field_buffer(inputFields[DOORS_INDEX], 0));
    car->trunkCapacity = std::stoi(field_buffer(inputFields[TRUNK_INDEX], 0));
}
