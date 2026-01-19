#include <form.h>
#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Create fields: 3 input fields + 1 terminating NULL
    FIELD *fields[4];

    fields[0] = new_field(1, 20, 4, 18, 0, 0);  // Name
    fields[1] = new_field(1, 20, 6, 18, 0, 0);  // Age
    fields[2] = new_field(1, 20, 8, 18, 0, 0);  // City
    fields[3] = NULL;

    // Field options
    for (int i = 0; i < 3; i++) {
        set_field_back(fields[i], A_UNDERLINE); // underline input area
        field_opts_off(fields[i], O_AUTOSKIP);  // don't jump automatically
    }

    // Create form
    FORM *form = new_form(fields);
    post_form(form);
    refresh();

    // Labels
    mvprintw(4, 10, "Name:");
    mvprintw(6, 10, "Age:");
    mvprintw(8, 10, "City:");
    mvprintw(12, 10, "Press F1 to submit");

    refresh();

    int ch;
    while ((ch = getch()) != KEY_F(1)) {
        switch (ch) {
            case KEY_DOWN:
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
                form_driver(form, ch);
                break;
        }
    }

    // Unpost form and cleanup
    unpost_form(form);
    free_form(form);

    for (int i = 0; i < 3; i++)
        free_field(fields[i]);

    endwin();

    return 0;
}

