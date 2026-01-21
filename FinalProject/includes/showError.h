#ifndef __SHOW_ERROR_H__
#define __SHOW_ERROR_H__

#include <string>
#include <memory>
#include "mainWindow.h"

const auto TEST_ERROR = std::vector<std::string>(
        std::initializer_list<std::string>{
            "This is a test error message",
            "",
            "Any key to continue"}
    );

void showError (std::vector<std::string> msg, std::shared_ptr<MainWindow> mainWin);

#endif

