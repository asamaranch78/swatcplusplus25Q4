#include "formDriver.h"
#include "constants.h"
#include <cstdlib>
#include <ncurses.h>
#include <form.h>

FormDriver::FormDriver(WINDOW* win) {
    windowPtr = win;
    keypad(stdscr, TRUE);
}

void FormDriver::createForm(FIELD *field[], std::vector<std::string> msg) {
    size_t vectorSize = msg.size();
    int32_t yPos;
    // Create form
    form = new_form(field);
    set_form_win(form, windowPtr);
    set_form_sub(form, windowPtr);
    post_form(form);

    // Print Label
    for (size_t i = 0; i < vectorSize; i++) {
        yPos =  FORM_START + (FORM_SPACE * i);
        mvwprintw(windowPtr, yPos, FORM_TEST_COL, "%s",msg[i].data());
    }

    yPos = FORM_START + (FORM_SPACE * (vectorSize));
    mvwprintw(windowPtr, yPos, FORM_TEST_COL, "Press F1 to Save");
    yPos = FORM_SPACE + (FORM_SPACE * (vectorSize + 1));
    mvwprintw(windowPtr, yPos, FORM_TEST_COL, "Press F2 to Cancel");
}

void FormDriver::handleFrom() {
        switch (key) {
            case KEY_DOWN:
            case '\t':
            case '\n':
                form_driver(form, REQ_NEXT_FIELD);
                form_driver(form, REQ_END_LINE);
                break;
            case KEY_UP:
                form_driver(form, REQ_PREV_FIELD);
                form_driver(form, REQ_END_LINE);
                break;
            case KEY_BACKSPACE:
            case 127:
                form_driver(form, REQ_DEL_PREV);
                break;
            default:
                form_driver(form, key);
                break;
        }
}

void FormDriver::destroyForm() {
    unpost_form(form);
    free_form(form);
}
