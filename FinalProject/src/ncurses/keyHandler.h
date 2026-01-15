#ifndef __KEY_HANDLER_H__
#define __KEY_HANDLER_H__

#include <cstdint>
#include "mainWindow.h"
#include <memory>
class KeyHandler {
private:
    int16_t pressedKey;
    std::shared_ptr<MainWindow> mainWin;

    void addVehicle(void);
public:
    KeyHandler(std::shared_ptr<MainWindow> win);
    bool listenKeyboard(void);
    void handleKey(void);
};

#endif
