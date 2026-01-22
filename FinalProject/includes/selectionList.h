#ifndef __SELECTION_LIST_H__
#define __SELECTION_LIST_H__

#include "popUpWindow.h"
#include <cstddef>
#include <memory>
#include <vector>
#include <string>

class SelectionList: public PopUpWindow {
public: 
    std::shared_ptr<std::vector<std::string>> options;
    int8_t cursor;
    int8_t size;
    int16_t key;

    SelectionList(std::shared_ptr<MainWindow> mainWin,
                  std::shared_ptr<std::vector<std::string>> optText);
    void cursorDown(void);
    void cursorUp(void);
    int8_t handleList(void);
    void drawList(void);
    void printOption(size_t option);
};

#endif
