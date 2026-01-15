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
#include "ncurses/popUpWindow.h"

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
    curs_set(0); // Hide cursor
    centerX = getmaxx(stdscr) / 2;
    windowHeight = getmaxy(stdscr);

    init_pair(MAIN_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(SELECTED_COLOR, COLOR_BLACK, COLOR_WHITE);
    init_pair(MENU_COLOR, COLOR_GREEN, COLOR_BLACK);
    init_pair(ERROR_COLOR, COLOR_WHITE, COLOR_RED);

    std::shared_ptr<MainWindow> mainWin;
    mainWin = std::make_shared<MainWindow>(windowHeight, centerX, MAIN_COLOR);
    mainWin->drawConstantPart();
    mainWin->drawDisplayData(data);
    mainWin->refresh();

    sleep(1);

    std::unique_ptr<PopUpWindow> errorWin;
    errorWin = std::make_unique<PopUpWindow>(5, 40, centerX - 20, windowHeight / 2, ERROR_COLOR, mainWin);
    errorWin->putOnTop();

    for (std::size_t i = 0; i < 20; i++) {
        errorWin->print(1, 5, std::to_string(20 - i), ERROR_COLOR);
        errorWin->refresh();
        sleep(1);
    }

    errorWin.reset();

    sleep(5);
    endwin();

    return 0;
}
