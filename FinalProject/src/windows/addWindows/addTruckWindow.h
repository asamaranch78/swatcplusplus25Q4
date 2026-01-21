#ifndef __ADD_TRUCK_WINDOW_H__
#define __ADD_TRUCK_WINDOW_H__

#include "formWindow.h"
#include "truck.h"
#include <form.h>
#include <memory>

class AddTruckWindow: public FormWindow {
public:
    AddTruckWindow(std::shared_ptr<MainWindow> mainWin);
    void saveToObject(std::shared_ptr<Truck> car);
};


#endif
