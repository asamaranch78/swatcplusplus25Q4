#include "addCarWindow.h"
#include "constants.h"
#include "formDriver.h"
#include "popUpWindow.h"
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

    inputNames[MANUFACTURER_INDEX] = "Manufacturer:";
    inputNames[MODEL_INDEX] = "Model:";
    inputNames[YEAR_INDEX] = "Year:";
    inputNames[WEIGHT_INDEX] = "Weight:";
    inputNames[EFFICIENCY_INDEX] = "Fuel Effi:";
    inputNames[DOORS_INDEX] = "Doors:";
    inputNames[TRUNK_INDEX] = "Trunk cap.:";
}

void AddCarWindow::askForData(void) {
    FormDriver::createForm(inputFields, inputNames);
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
