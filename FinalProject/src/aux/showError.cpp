#include "showError.h"
#include "constants.h"
#include "popUpWindow.h"
#include <memory>

void showError (std::vector<std::string> msg, std::shared_ptr<MainWindow> mainWin) {
    uint16_t size = msg.size();
    PopUpWindow popUp(size + 4, 50, ERROR_COLOR, mainWin);

    for (uint16_t i = 0; i < size; i++) {
        popUp.print(i+2, 5, msg.at(i));
    }
    popUp.putOnTop();
    popUp.refresh();
    wgetch(popUp.window);
    popUp.hide();
    mainWin->refresh();
}
