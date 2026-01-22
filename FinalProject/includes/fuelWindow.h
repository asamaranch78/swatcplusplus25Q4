#ifndef __FUEL_WINDOW_H__
#define __FUEL_WINDOW_H__


#include "formWindow.h"
#include <form.h>
#include <memory>

class FuelWindow: public FormWindow {
public:
    FuelWindow(std::shared_ptr<MainWindow> mainWin);
    int16_t getKilometers(void);
    double getLiters(void);
};

#endif
