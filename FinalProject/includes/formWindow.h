#ifndef __FORM_WINDOW_H__
#define __FORM_WINDOW_H__

#include "popUpWindow.h"
#include "formDriver.h"
#include "constants.h"

class FormWindow: public PopUpWindow, public FormDriver {
public:
    FIELD *inputFields[MAX_FIELDS + 1];
    std::vector<std::string> inputNames;

    FormWindow(std::shared_ptr<MainWindow> mainWin, uint16_t fields);
    bool askForData(void);
};

#endif
