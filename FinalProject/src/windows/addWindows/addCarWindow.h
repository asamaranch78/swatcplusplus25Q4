#ifndef __ADD_CAR_WINDOW_H__
#define __ADD_CAR_WINDOW_H__

#include "formWindow.h"
#include "car.h"
#include <form.h>
#include <memory>

class AddCarWindow: public FormWindow {
public:
    AddCarWindow(std::shared_ptr<MainWindow> mainWin);
    void saveToObject(std::shared_ptr<Car> car);
};


#endif
