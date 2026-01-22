#include "formWindow.h"
#include "constants.h"
#include "customExceptions.h"


FormWindow::FormWindow(std::shared_ptr<MainWindow> mainWin, uint16_t fields) :
    PopUpWindow((fields + 2) * FORM_SPACE + 2 * FORM_START,
                FORM_WIN_WIDTH, 
                SELECTED_COLOR, 
                mainWin),
    FormDriver(window) {
    if (fields > MAX_FIELDS) { throw tooManyFields(); }
    int16_t fieldRow;
    keypad(window, TRUE);
    for (size_t i=0; i < fields; i++) {
        fieldRow = FORM_START + FORM_SPACE * i;
        inputFields[i] = new_field(FORM_HEIGHT, FORM_WIDTH, fieldRow, FORM_COL, NO_OFF_SCREEN, NO_BUFFERS);
        field_opts_off(inputFields[i], O_AUTOSKIP);
    }
    inputFields[fields] = NULL;

}

bool FormWindow::askForData(void) {
    putOnTop();
    FormDriver::createForm(inputFields, inputNames);
    refresh();
    key = wgetch(window);
    while (key != KEY_F(1)) {
        FormDriver::handleFrom();
        if (key == KEY_F(2)) { return false; }
        refresh();
        key = wgetch(window);
    }
    form_driver(form, REQ_NEXT_FIELD);
    hide();
    FormDriver::destroyForm();
    return true;
}
