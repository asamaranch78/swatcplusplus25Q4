#ifndef __POP_UP_WINDOW_H_
#define __POP_UP_WINDOW_H_

#include "mainWindow.h"
#include "window.h"
#include <memory>
#include <panel.h>
#include <cstdint>

class PopUpWindow: public Window {
public:
    PANEL *panel;
    std::shared_ptr<MainWindow> mainWindow;

    PopUpWindow(uint16_t height,
                uint16_t width,
                uint16_t backgroundColor,
                std::shared_ptr<MainWindow> mainWin);

    ~PopUpWindow(void);
    void close(void);
    void refresh(void) override;
    void putOnTop(void);
    void hide(void);
    void show(void);
};

#endif
