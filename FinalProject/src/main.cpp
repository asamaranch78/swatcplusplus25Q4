#include <memory>
#include <iostream>
#include "menucli.h"
#include "dataSet.h"
#include "constants.h"

int main (void);

int main (void) {
    MenuCLI menu;
    std::shared_ptr<DataSet> data = std::make_shared<DataSet>();

    initData(data);


    while (true) {
        if (!menu.askForSelection()) {return 0;} 
        menu.handleSelection(data);
    }
}
