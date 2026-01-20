#ifndef __ADD_TRUCK_WINDOW_H__
#define __ADD_TRUCK_WINDOW_H__

#include "popUpWindow.h"
#include "formDriver.h"
#include "constants.h"
#include "truck.h"
#include <form.h>
#include <memory>

class AddTruckWindow: public PopUpWindow, public FormDriver {
private:
    static constexpr int16_t NUMBER_OF_FIELDS = 7;
    static constexpr int16_t FIELD_ARRAY_SIZE = NUMBER_OF_FIELDS + 1;
    static constexpr int16_t WINDOW_HEIGHT = (NUMBER_OF_FIELDS + 2) * FORM_SPACE + 2 * FORM_START;
    static constexpr int16_t WINDOW_WIDTH = FORM_WIN_WIDTH;
    static constexpr int8_t WINDOW_COLOR = SELECTED_COLOR;
    static constexpr int8_t INPUT_COLOR = SELECTED_COLOR;
    FIELD *inputFields[FIELD_ARRAY_SIZE];
    std::vector<std::string> inputNames;

public:
    AddTruckWindow(std::shared_ptr<MainWindow> mainWin);
    bool askForData(void);
    void saveToObject(std::shared_ptr<Truck> car);
};


#endif
