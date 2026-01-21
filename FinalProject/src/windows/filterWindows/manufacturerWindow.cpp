#include "manufacturerWindow.h"
#include "formWindow.h"
#include <form.h>


ManufacturerWindow::ManufacturerWindow(std::shared_ptr<MainWindow> mainWin) :
    FormWindow(mainWin, 1) {
    inputNames.push_back("Manufacturer:");
}

std::string ManufacturerWindow::getManufacturer() {
    return field_buffer(inputFields[0], 0);
}
