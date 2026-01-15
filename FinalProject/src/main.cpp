#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <unistd.h>
#include <iostream>
#include <ncurses.h>
#include "menucli.h"
#include "dataSet.h"
#include "constants.h"
#include "mainWindow.h"
#include "keyHandler.h"
#include "popUpWindow.h"

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
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0); // Hide cursor
    centerX = getmaxx(stdscr) / 2;
    windowHeight = getmaxy(stdscr);

    init_pair(MAIN_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(SELECTED_COLOR, COLOR_BLACK, COLOR_WHITE);
    init_pair(MENU_COLOR, COLOR_CYAN, COLOR_BLACK);
    init_pair(ERROR_COLOR, COLOR_WHITE, COLOR_RED);

    std::shared_ptr<MainWindow> mainWin;
    mainWin = std::make_shared<MainWindow>(windowHeight, centerX, MAIN_COLOR);
    mainWin->drawConstantPart();
    mainWin->drawDisplayData(data);
    mainWin->refresh();
    KeyHandler keyboard(mainWin);

    while (true) {
        if (keyboard.listenKeyboard()) {
            keyboard.handleKey();

            mainWin->drawDisplayData(data);
            mainWin->refresh();

            napms(100);
        }
        else {
            endwin();
            return 0;
        }
    }
}
