#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include <ncurses.h>
#include <cstdint>
#include <string>

class Window {
public:
    WINDOW *window;
    uint16_t width;
    uint16_t height;
    uint16_t backgroundColor;
    uint16_t centerY;
    uint16_t centerX;

    Window(uint16_t height,
           uint16_t width,
           uint16_t startX,
           uint16_t startY,
           uint16_t backgroundColor,
           bool drawBorder); 
    void print(uint16_t x,uint16_t y, std::string str, uint16_t color);
    void refresh();
};

#endif
