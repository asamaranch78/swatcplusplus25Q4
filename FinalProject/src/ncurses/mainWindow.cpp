#include "mainWindow.h"
#include "constants.h"

MainWindow::MainWindow(uint16_t windowHeight, uint16_t windowCenterX, uint16_t mainColor) :
    Window(windowHeight, 160, 0, windowCenterX - 80, mainColor, true) {
        
}


void MainWindow::drawDisplayData(uint16_t lines) {
    return;
}

char MainWindow::checkKeyboardCmd() {
    return 'A';
}
