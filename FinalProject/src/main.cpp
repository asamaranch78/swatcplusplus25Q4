#include <cstdint>
#include <memory>
#include <unistd.h>
#include <ncurses.h>
#include "dataSet.h"
#include "constants.h"
#include "mainWindow.h"

int main (void);
void initCurses(void);

int main (void) {
    std::shared_ptr<DataSet> data = std::make_shared<DataSet>();
    uint16_t windowHeight, centerX;
    

    initData(data);
    initCurses();

    centerX = getmaxx(stdscr) / 2;
    windowHeight = getmaxy(stdscr);


    std::shared_ptr<MainWindow> mainWin;
    mainWin = std::make_shared<MainWindow>(windowHeight, centerX, MAIN_COLOR);
    mainWin->drawConstantPart();

    while (true) {
        mainWin->drawDisplayData(data);
        mainWin->refresh();

        napms(100);

        if (mainWin->listenKeyboard()) {
            mainWin->handleKey();
        }
        else {
            endwin();
            return 0;
        }
    }
}

void initCurses(void) {
    initscr();
    start_color();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0); // Hide cursor
    
    init_pair(MAIN_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(SELECTED_COLOR, COLOR_BLACK, COLOR_WHITE);
    init_pair(MENU_COLOR, COLOR_GREEN, COLOR_BLACK);
    init_pair(ERROR_COLOR, COLOR_WHITE, COLOR_RED);
}
