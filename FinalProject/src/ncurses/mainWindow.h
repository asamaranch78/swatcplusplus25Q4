#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include <cstdint>
#include <memory>
#include <ncurses.h>
#include <panel.h>
#include "window.h"
#include "vehicle.h"
#include "dataSet.h"

class MainWindow: public Window {
private:
    void printVehicle(std::shared_ptr<Vehicle> ptr, int8_t line);
    void printBlankLine(int8_t line);

public:
    PANEL *panel;
    char selectedAction;
    uint8_t dataLines;
    uint8_t menuLine;
    uint8_t centerX;
    uint8_t centerY;
    uint8_t separatorLine;
    uint8_t cursor;
    uint8_t cursorMax;
    uint8_t cursorMin;

    MainWindow(uint16_t windowHeight, uint16_t windowCenterX, uint16_t mainColor);
    void cursorDown();
    void cursorUp();
    void refresh(void) override;
    void drawDisplayData(std::shared_ptr<DataSet> data);
    void drawConstantPart();
};

#endif
