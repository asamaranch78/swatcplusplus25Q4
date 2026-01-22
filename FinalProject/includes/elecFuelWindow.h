#ifndef __ELEC_FUEL_WINDOW_H__
#define __ELEC_FUEL_WINDOW_H__


#include "formWindow.h"
#include <form.h>
#include <memory>

class ElecFuelWindow: public FormWindow {
public:
    ElecFuelWindow(std::shared_ptr<MainWindow> mainWin);
    double getHours(void);
    int16_t getKilometers(void);
};

#endif
