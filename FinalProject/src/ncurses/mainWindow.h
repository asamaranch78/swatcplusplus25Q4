#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include <cstdint>
#include <ncurses.h>
#include "window.h"

class MainWindow: public Window {
public:
    char selectedAction;
    uint8_t dataLines;

    MainWindow(uint16_t windowHeight, uint16_t windowCenterX, uint16_t mainColor);
    void drawDisplayData(uint16_t lines);
    char checkKeyboardCmd();
};

#endif
