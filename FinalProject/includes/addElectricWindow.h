#ifndef __ADD_ELECTRIC_WINDOW_H__
#define __ADD_ELECTRIC_WINDOW_H__

#include "formWindow.h"
#include "electric.h"
#include <form.h>
#include <memory>

class AddElectricWindow: public FormWindow {
public:
    AddElectricWindow(std::shared_ptr<MainWindow> mainWin);
    void saveToObject(std::shared_ptr<Electric> car);
};

#endif
