#ifndef __MESSAGES_H__
#define __MESSAGES_H__


#include <array>
#include <string>

struct Msg {
    std::array<std::string, 10> menuMessages = {
        "Select on of the following options",
        "\tA - Add new vehicle to system",
        "\tF - Filter vehicles on system",
        "\tL - Lisst all vehicles in system",
        "\tC - Calculate fuel efficiency of a vehicle",
        "\tE - Erase vehicle from system",
        "\tD - Delete all data",
        "\tX - Export data to a file",
        "\tI - Import data",
        "\tQ - Quit program"};
};

#endif
