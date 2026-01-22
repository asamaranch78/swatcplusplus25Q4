#ifndef __SHOW_ERROR_H__
#define __SHOW_ERROR_H__

#include <string>
#include <memory>
#include "mainWindow.h"

const auto COMMON_TEXT = std::vector<std::string>(
        std::initializer_list<std::string>{
            "",
            "Any key to continue"}
    );

const auto TEST_ERROR = std::vector<std::string>(
        std::initializer_list<std::string>{
            "This is a test error message"
        }
    );

void showError (std::vector<std::string> msg, std::shared_ptr<MainWindow> mainWin);
void showError (std::string msg, std::shared_ptr<MainWindow> mainWin);

#endif

