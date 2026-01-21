#ifndef __MANUFACTURER_WINDOW_H__
#define __MANUFACTURER_WINDOW_H__


#include "formWindow.h"
#include <memory>

class ManufacturerWindow: public FormWindow {
public:
    ManufacturerWindow(std::shared_ptr<MainWindow> mainWin);
    std::string getManufacturer();
};

#endif
