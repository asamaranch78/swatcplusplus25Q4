#ifndef __ADD_CAR_WINDOW_H__
#define __ADD_CAR_WINDOW_H__

#include "popUpWindow.h"
#include "constants.h"
#include <form.h>
#include <memory>

#define NUMBER_OF_FIELDS 8
#define COLOR MAIN_COLOR
#define INPUT_COLOR SELECTED_COLOR

class AddCarWindow: public PopUpWindow, FormDriver {
private:
    FIELD inputs[NUMBER_OF_FIELDS];
    std::string inputNames[NUMBER_OF_FIELDS];
    std::shared_ptr<DataSet> data;

    void saveToDataSet(void);

};


#endif
