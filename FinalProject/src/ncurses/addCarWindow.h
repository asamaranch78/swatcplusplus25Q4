#ifndef __ADD_CAR_WINDOW_H__
#define __ADD_CAR_WINDOW_H__

#include "popUpWindow.h"
#include "formDriver.h"
#include "constants.h"
#include "car.h"
#include <form.h>
#include <memory>

class AddCarWindow: public PopUpWindow, public FormDriver {
private:
    static constexpr int16_t NUMBER_OF_FIELDS = 7;
    static constexpr int16_t FIELD_ARRAY_SIZE = NUMBER_OF_FIELDS + 1;
    static constexpr int16_t WINDOW_HEIGHT = NUMBER_OF_FIELDS * FORM_SPACE + 2 + FORM_START;
    static constexpr int16_t WINDOW_WIDTH = FORM_WIN_WIDTH;
    static constexpr int8_t WINDOW_COLOR = MAIN_COLOR;
    static constexpr int8_t INPUT_COLOR = SELECTED_COLOR;
    FIELD *inputFields[FIELD_ARRAY_SIZE];
    std::vector<std::string> inputNames;

public:
    AddCarWindow(std::shared_ptr<MainWindow> mainWin);
    void askForData(void);
    void saveToObject(std::shared_ptr<Car> car);
};


#endif
