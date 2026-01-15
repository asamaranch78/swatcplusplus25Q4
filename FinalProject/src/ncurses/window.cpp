#include "window.h"
#include <cstdint>
#include <ncurses.h>

Window::Window(uint16_t par_height,
               uint16_t par_width,
               uint16_t startX,
               uint16_t startY,
               uint16_t parBackgroundColor,
               bool drawBorder) {
    height = par_height;
    width = par_width;
    centerY = height / 2;
    centerX = width / 2;
    backgroundColor = parBackgroundColor;

    window = newwin(height, width, startY, startX);
    wbkgd(window, COLOR_PAIR(parBackgroundColor));

    if (drawBorder) { box(window, 0, 0); }
}

void Window::print(uint16_t y,uint16_t x, std::string str, uint16_t color) {
    mvwprintw(window, y, x, str.data(), COLOR_PAIR(color));
}

void Window::append(std::string str) {
    printw(str.data());
}

void Window::refresh() {
    wrefresh(window);
}
    
