
#include <form.h>
#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Get terminal size
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    // Window size for the form
    int win_h = 15;
    int win_w = 50;

    // Center position
    int starty = (rows - win_h) / 2;
    int startx = (cols - win_w) / 2;

    // Create centered window
    WINDOW *win = newwin(win_h, win_w, starty, startx);
    box(win, 0, 0);
    keypad(win, TRUE);

    // Create fields
    FIELD *fields[4];

    fields[0] = new_field(1, 20, 2, 12, 0, 0);  // Name
    fields[1] = new_field(1, 20, 4, 12, 0, 0);  // Age
    fields[2] = new_field(1, 20, 6, 12, 0, 0);  // City
    fields[3] = NULL;

    // Field properties
    for (int i = 0; i < 3; i++) {
        set_field_back(fields[i], A_UNDERLINE);
        field_opts_off(fields[i], O_AUTOSKIP);
    }

    // Create form
    FORM *form = new_form(fields);

    // Attach form to window
    set_form_win(form, win);
    set_form_sub(form, derwin(win, win_h - 2, win_w - 2, 1, 1));

    // Post form
    post_form(form);
    wrefresh(win);

    // Labels inside window
    mvwprintw(win, 2, 2, "Name:");
    mvwprintw(win, 4, 2, "Age:");
    mvwprintw(win, 6, 2, "City:");
    mvwprintw(win, win_h - 3, 2, "Press F1 to submit");

    wrefresh(win);

    int ch;
    while ((ch = wgetch(win)) != KEY_F(1)) {
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
        wrefresh(win);
    }

    // Cleanup
    unpost_form(form);
    free_form(form);

    for (int i = 0; i < 3; i++)
        free_field(fields[i]);

    delwin(win);
    endwin();

    return 0;
}
