#include <cstdint>
#include <memory>
#include <unistd.h>
#include <iostream>
#include <ncurses.h>
#include "menucli.h"
#include "dataSet.h"
#include "constants.h"
#include "mainWindow.h"

int main (void);

int main (void) {
    std::shared_ptr<DataSet> data = std::make_shared<DataSet>();
    uint16_t windowHeight, centerX;

    initData(data);

    /*MenuCLI menu;
    while (true) {
        if (!menu.askForSelection()) {return 0;} 
        menu.handleSelection(data);
    }*/
    initscr();
    start_color();
    centerX = getmaxx(stdscr) / 2;
    windowHeight = getmaxy(stdscr);

    init_pair(MAIN_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(MENU_COLOR, COLOR_GREEN, COLOR_BLACK);

    //Window mainWin (windowHeight, 160, 0, centerX - 80, MAIN_COLOR, true);
    MainWindow mainWin (windowHeight, centerX, MAIN_COLOR);
    mainWin.drawConstantPart();
    mainWin.drawDisplayData(data);
    mainWin.refresh();

    sleep(60);
    
    endwin();

    return 0;
}
