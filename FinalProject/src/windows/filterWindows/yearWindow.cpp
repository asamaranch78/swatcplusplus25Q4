#include "yearWindow.h"
#include <cstdint>
#include <form.h>

YearWindow::YearWindow(std::shared_ptr<MainWindow> mainWin) :
    FormWindow(mainWin, 2) {
    inputNames.push_back("Begin year:");
    inputNames.push_back("End year:");
}

uint16_t YearWindow::getBeginYear(void) {
    try {
        return std::stoi(field_buffer(inputFields[0], 0));
    }
    catch (...) {
        return 0;
    }
}

uint16_t YearWindow::getEndYear(void) {
    try {
        return std::stoi(field_buffer(inputFields[1], 0));
    }
    catch (...) {
        return 0;
    }
}
