#include <memory>
#include <ncurses.h>
#include <unistd.h>
#include "popUpWindow.h"
#include "keyHandler.h"
#include "constants.h" 

KeyHandler::KeyHandler(std::shared_ptr<MainWindow> win) {
    mainWin = win;
}

bool KeyHandler::listenKeyboard(void) {
    pressedKey = getch();

    if (pressedKey == 'q' || pressedKey == 'Q') {
        return false;
    }
    else {
        return true;
    }
}

void KeyHandler::handleKey(void) {
    switch (pressedKey) {
        case 'a':
        case 'A':
            addVehicle();
            break;
        case 'j':
        case 'J':
        case KEY_DOWN:
            mainWin->cursorDown();
            break;
        case 'k':
        case 'K':
        case KEY_UP:
            mainWin->cursorUp();
            break;
    }
}

void KeyHandler::addVehicle(void) {
    std::unique_ptr<PopUpWindow> errorWin;
    errorWin = std::make_unique<PopUpWindow>(5, 40, ERROR_COLOR, mainWin);
    errorWin->putOnTop();

    for (std::size_t i = 0; i < 5; i++) {
        errorWin->print(1, 5, "Here we will add a vehicle");
        errorWin->print(2, 5, std::to_string(5-i));
        errorWin->refresh();
        sleep(1);
    }

    errorWin.reset();
}
