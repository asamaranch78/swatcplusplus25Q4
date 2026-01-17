#ifndef __MESSAGES_H__
#define __MESSAGES_H__


#include <vector>
#include <ncurses.h>
#include <string>

struct Msg {
    std::vector<std::string> menuMessages = {
        "Select on of the following options",
        "\tA - Add new vehicle to system",
        "\tF - Filter vehicles on system",
        "\tL - Lisst all vehicles in system",
        "\tC - Calculate fuel efficiency of a vehicle",
        "\tE - Erase vehicle from system",
        "\tD - Delete all data",
        "\tX - Export data to a file",
        "\tI - Import data",
        "\tQ - Quit program"
    };

    std::vector<std::string> menuTypeSelection = {
        "Select type of car:",
        "\t1 - Car",
        "\t2 - Electric car",
        "\t3 - Truck",
        "\t4 - Motorbike"
    };

    std::vector<std::string> menuFuelTypeSelection = {
        "Select fuel type:",
        "\t1 - Diesel",
        "\t2 - Gasoline"
    };

    std::string askManufacturer {"What is the manufacturer? "};
    std::string askModel {"What is the model? "};
    std::string askYear {"What year? "};
    std::string askWeight {"What is the weight? "};
    std::string askWeight2 {"What is the weight? "};
};

extern void printListHeader(void);
extern void printMessage(std::vector<std::string> *message);

#endif
