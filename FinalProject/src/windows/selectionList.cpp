#include <memory>
#include <ncurses.h>

#include "selectionList.h"
#include "constants.h"
#include "popUpWindow.h"

SelectionList::SelectionList(std::shared_ptr<MainWindow> mainWin,
                             std::shared_ptr<std::vector<std::string>> optText) :
    PopUpWindow(optText->size() + 4, FORM_WIN_WIDTH, MAIN_COLOR, mainWin) {
    options = optText;
    size = optText->size();
    cursor = 0;
}

void SelectionList::cursorDown(void) {
    cursor++;
    if (cursor > size - 1) { cursor = size - 1; }
}

void SelectionList::cursorUp(void) {
    cursor--;
    if (cursor < 0) { cursor = 0; }
}

int8_t SelectionList::handleList(void) {
    drawList();
    keypad(window, TRUE);
    while (key != '\n') {

        key = wgetch(window);
        switch (key) {
            case 'j':
            case 'J':
            case KEY_DOWN:
                cursorDown();
                break;
            case 'k':
            case 'K':
            case KEY_UP:
                cursorUp();
                break;
        }
        drawList();
    }
    hide();

    return cursor;
}

void SelectionList::drawList(void) {
    for (int8_t i = 0; i < size; i++) {
        if (i == cursor) {
            changeColor(SELECTED_COLOR);
        }
        printBlankLine(i + 2);
        printOption(i);
        if (i == cursor) {
            removeColor(SELECTED_COLOR);
        }
    }
}

void SelectionList::printOption(size_t option) {
    print(option + 2, 5, options->at(option));
}
