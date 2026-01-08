#include <iostream>

#include "messages.h"
#include "menucli.h"

int main (void);

int main (void) {
    MenuCLI menu;

    while (true) {
        if (!menu.askForSelection()) {return 0;} 
        menu.handleSelection();
    }
}
