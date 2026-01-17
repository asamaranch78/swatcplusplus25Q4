#include "formDriver.h"
#include "constants.h"
#include <ncurses.h>
#include <form.h>

FormDriver::FormDriver(std::shared_ptr<Window> win) {
    window = win;
    keypad(stdscr, TRUE);
}

void FormDriver::createForm(FIELD *field[], std::string *msg[], size_t fieldSize) {
    int32_t yPos;
    // Create form
    form = new_form(field);
    set_form_win(form, window->window);
    post_form(form);
    window->refresh();

    // Print Label
    for (size_t i = 0; i < fieldSize; i++) {
        yPos =  FORM_START + (FORM_SPACE * i);
        window->print(yPos, FORM_TEST_COL, *msg[i]);
    }
    window->refresh();
}

void FormDriver::handleFrom() {
    while ((key = getch()) != KEY_ENTER) {
        switch (key) {
            case KEY_DOWN:
            case '\t':
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
}
void FormDriver::destroyForm() {
    unpost_form(form);
    free_form(form);
}
