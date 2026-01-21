#include "pathWindow.h"


PathWindow::PathWindow(std::shared_ptr<MainWindow> mainWin) :
    FormWindow(mainWin,1) {
    inputNames.push_back("Path:");
}

std::string PathWindow::getPath() {
    return field_buffer(inputFields[0], 0);
}
