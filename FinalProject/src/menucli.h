#ifndef __MENUCLI_H__
#define __MENUCLI_H__

#include <ncurses.h>
#include <vector>
#include <array>
#include <string>

#include "messages.h"

class MenuCLI {
private:
    Msg msg;
    unsigned char selectedOption;

    void addVehicle(void);
    void removeVehicle(void);
    void listVehicles(void);
    void filterVehicle(void);
    void filterByType(void);
    void filterByBrand(void);
    void filterByYear(void);
    void computeFuelEfficiency(void);
    void exportData(void);
    void eraseData(void);
    void importData(void);
public:
    bool askForSelection(void);
    void handleSelection(void);
};

#endif
