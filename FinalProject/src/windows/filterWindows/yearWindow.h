#ifndef __YEAR_WINDOW_H__
#define __YEAR_WINDOW_H__

#include "formWindow.h"
#include <cstdint>
#include <memory>

class YearWindow: public FormWindow {
public:
    YearWindow(std::shared_ptr<MainWindow> mainWin);
    uint16_t getBeginYear();
    uint16_t getEndYear();
};

#endif
