#include "popUpWindow.h"
#include "mainWindow.h"
#include <cstdint>
#include <memory>
#include <panel.h>

PopUpWindow::PopUpWindow(uint16_t height,
                         uint16_t width,
                         uint16_t backgroundColor,
                         std::shared_ptr<MainWindow> mainWin) :
Window(height, width, mainWin->centerX - (width/2), mainWin->centerY - (height/2), backgroundColor, true) {
    panel = new_panel(window);
    mainWindow = mainWin;
}

PopUpWindow::~PopUpWindow() {
    hide();
    update_panels();
    close();
    mainWindow->refresh();
}

void PopUpWindow::refresh() {
    Window::refresh();
    update_panels();
}

void PopUpWindow::putOnTop() {
    top_panel(panel);
}

void PopUpWindow::hide() {
    hide_panel(panel);
}

void PopUpWindow::show() {
    show_panel(panel);
}

void PopUpWindow::close (void) {
    delwin(window);
}
