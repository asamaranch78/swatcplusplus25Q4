#include "pathWindow.h"
#include "stringManip.h"


PathWindow::PathWindow(std::shared_ptr<MainWindow> mainWin) :
    FormWindow(mainWin,1) {
    inputNames.push_back("Path:");
}

std::string PathWindow::getPath() {
    std::string path = field_buffer(inputFields[0], 0);
    rtrim_in_place(path);
    ltrim_in_place(path);
    normalize_newlines(path);
    return path;
}
