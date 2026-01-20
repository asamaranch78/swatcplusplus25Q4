#include "addTruckWindow.h"
#include "constants.h"

AddTruckWindow::AddTruckWindow(std::shared_ptr<MainWindow> mainWin) :
    PopUpWindow(WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_COLOR, mainWin),
    FormDriver(window) {
    int16_t fieldRow;
    keypad(window, TRUE);
    for (size_t i=0; i < NUMBER_OF_FIELDS; i++) {
        fieldRow = FORM_START + FORM_SPACE * i;
        inputFields[i] = new_field(FORM_HEIGHT, FORM_WIDTH, fieldRow, FORM_COL, NO_OFF_SCREEN, NO_BUFFERS);
        field_opts_off(inputFields[i], O_AUTOSKIP);
        set_field_back(inputFields[i], A_UNDERLINE);
    }
    inputFields[NUMBER_OF_FIELDS] = NULL;

    inputNames.push_back("Manufacturer:");
    inputNames.push_back("Model:");
    inputNames.push_back("Year:");
    inputNames.push_back("Weight:");
    inputNames.push_back("Fuel Effi:");
    inputNames.push_back("Axles:");
    inputNames.push_back("Payload cap.:");
}

bool AddTruckWindow::askForData(void) {
    putOnTop();
    curs_set(1); // Hide cursor
    FormDriver::createForm(inputFields, inputNames);
    refresh();
    form_driver(form, REQ_NEXT_FIELD);
    form_driver(form, REQ_PREV_FIELD);
    key = wgetch(window);
    while (key != KEY_F(1)) {
        FormDriver::handleFrom();
        if (key == KEY_F(2)) { return false; }
        refresh();
        key = wgetch(window);
    }
    form_driver(form, REQ_NEXT_FIELD);
    hide();
    curs_set(0);
    FormDriver::destroyForm();
    return true;
}

void AddTruckWindow::saveToObject(std::shared_ptr<Truck> truck) {
    truck->manufacturer = field_buffer(inputFields[MANUFACTURER_INDEX], 0);
    truck->model = field_buffer(inputFields[MODEL_INDEX], 0);
    truck->year = std::stoi(field_buffer(inputFields[YEAR_INDEX], 0));
    truck->weight = std::stoi(field_buffer(inputFields[WEIGHT_INDEX], 0));
    truck->fuelEfficiency = std::stof(field_buffer(inputFields[EFFICIENCY_INDEX], 0));

    truck->axles = std::stoi(field_buffer(inputFields[AXLE_INDEX], 0));
    truck->payloadCapacity = std::stoi(field_buffer(inputFields[LOAD_INDEX], 0));

}
