#ifndef __ADD_MOTORBIKE_WINDOW__
#define __ADD_MOTORBIKE_WINDOW__

#include "formWindow.h"
#include <memory>
#include "motorbike.h"

class AddMotorbikeWindow: public FormWindow {
public:
    AddMotorbikeWindow(std::shared_ptr<MainWindow> mainWin);
    void saveToObject(std::shared_ptr<Motorbike> motorbike);
};

#endif
