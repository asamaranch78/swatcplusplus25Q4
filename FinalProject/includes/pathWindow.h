#ifndef __PATH_WINDOW_H__
#define __PATH_WINDOW_H__

#include "formWindow.h"
#include <form.h>
#include <memory>

class PathWindow: public FormWindow {
public:
    PathWindow(std::shared_ptr<MainWindow> mainWin);
    std::string getPath();
};

#endif
