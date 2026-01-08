
#include <ncurses.h>
#include <panel.h>   // panels let us stack windows

// Helper: create a framed window
WINDOW* create_framed_win(int h, int w, int y, int x, const char* title) {
    WINDOW* win = newwin(h, w, y, x);
    box(win, 0, 0);                    // draw border
    mvwprintw(win, 0, 2, " %s ", title); // title in the top border
    wrefresh(win);
    return win;
}

// Helper: center coordinates for a window
void center_coords(int win_h, int win_w, int& out_y, int& out_x) {
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    out_y = (max_y - win_h) / 2;
    out_x = (max_x - win_w) / 2;
}

int main() {
    // --- init ncurses ---
    initscr();            // start
    cbreak();             // immediate input
    noecho();             // don't echo keys
    keypad(stdscr, TRUE); // enable arrows/F-keys
    curs_set(0);          // hide cursor

    // Optional: colors
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_CYAN,   COLOR_BLACK); // frame title
        init_pair(2, COLOR_BLACK,  COLOR_YELLOW); // popup background
    }

    // --- main content window (subwindow) ---
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    int main_h = max_y - 4;   // leave margins
    int main_w = max_x - 6;
    int main_y = 2;
    int main_x = 3;

    WINDOW* main_win = create_framed_win(main_h, main_w, main_y, main_x, "Main Window");
    if (has_colors()) wattron(main_win, COLOR_PAIR(1));
    mvwprintw(main_win, 1, 2, "Press 'p' to toggle popup, 'q' to quit.");
    wattroff(main_win, COLOR_PAIR(1));
    mvwprintw(main_win, 3, 2, "This is your main working area.");
    wrefresh(main_win);

    // --- popup window (initially hidden) ---
    const int pop_h = 7, pop_w = 40;
    int pop_y, pop_x;
    center_coords(pop_h, pop_w, pop_y, pop_x);

    WINDOW* popup = newwin(pop_h, pop_w, pop_y, pop_x);
    // Style the popup
    if (has_colors()) wbkgd(popup, COLOR_PAIR(2));
    box(popup, 0, 0);
    mvwprintw(popup, 0, 2, " Popup ");
    mvwprintw(popup, 2, 2, "Hello! This is a centered popup.");
    mvwprintw(popup, 4, 2, "Press ESC or 'p' to close.");
    // Create a panel so we can stack/raise it
    PANEL* popup_panel = new_panel(popup);   // panel wraps the window
    hide_panel(popup_panel);                 // start hidden
    update_panels();                         // update stacking
    doupdate();                              // draw all

    // --- event loop ---
    bool popup_visible = false;
    while (true) {
        int ch = getch();
        if (ch == 'q' || ch == 'Q') break;

        if (ch == 'p' || ch == 'P') {
            popup_visible = !popup_visible;
            if (popup_visible) {
                // recenter on resize & show
                center_coords(pop_h, pop_w, pop_y, pop_x);
                wresize(popup, pop_h, pop_w); // not strictly needed unless you change size
                mvwin(popup, pop_y, pop_x);
                top_panel(popup_panel);     // raise on top
                show_panel(popup_panel);
            } else {
                hide_panel(popup_panel);
            }
            update_panels();
            doupdate();
        }

        // Close popup with ESC
        if ((ch == 27) && popup_visible) {
            popup_visible = false;
            hide_panel(popup_panel);
            update_panels();
            doupdate();
        }

        // Optional: redraw main window on resize
        if (ch == KEY_RESIZE) {
            getmaxyx(stdscr, max_y, max_x);
            // recompute main window geometry
            main_h = max_y - 4;
            main_w = max_x - 6;
            wresize(main_win, main_h, main_w);
            // keep margins
            mvwin(main_win, main_y, main_x);
            // redraw frame and contents
            werase(main_win);
            box(main_win, 0, 0);
            mvwprintw(main_win, 0, 2, " Main Window ");
            mvwprintw(main_win, 1, 2, "Press 'p' to toggle popup, 'q' to quit.");
            mvwprintw(main_win, 3, 2, "This is your main working area.");
            wrefresh(main_win);

            // If popup is visible, keep it centered
            if (popup_visible) {
                center_coords(pop_h, pop_w, pop_y, pop_x);
                mvwin(popup, pop_y, pop_x);
                update_panels();
                doupdate();
            }
        }
    }

    // --- cleanup ---
    del_panel(popup_panel);
    delwin(popup);
    delwin(main_win);
    endwin();
    return 0;
}
