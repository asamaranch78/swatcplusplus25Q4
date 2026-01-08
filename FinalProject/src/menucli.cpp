#include <cctype>
#include <iostream>

#include "menucli.h"
#include "messages.h"


bool MenuCLI::askForSelection(void) {
    for (auto line: msg.menuMessages) { std::cout << line << std::endl; }
    std::cin >> selectedOption;
    selectedOption = std::toupper(selectedOption);
    if (selectedOption == 'Q') { return false; }
    return true;
}

void MenuCLI::handleSelection(void) {
    switch (selectedOption) {
        case 'A':
            addVehicle();
            break;
        case 'F':
            filterVehicle();
            break;
        case 'L':
            listVehicles();
            break;
        case 'C':
            computeFuelEfficiency();
            break;
        case 'X':
            exportData();
            break;
        case 'D':
            eraseData();
            break;
        case 'I':
            importData();
            break;
        case 'E':
            removeVehicle();
            break;
        default:
            std::cout << "Bad selection that option is not available" << std::endl;
    }
}

void MenuCLI::addVehicle(void) {
    return;
}

void MenuCLI::removeVehicle(void) {
    return;
}

void MenuCLI::listVehicles(void) {
    return;
}

void MenuCLI::filterVehicle(void) {
    return;
}

void MenuCLI::filterByType(void) {
    return;
}

void MenuCLI::filterByBrand(void) {
    return;
}

void MenuCLI::filterByYear(void) {
    return;
}

void MenuCLI::computeFuelEfficiency(void) {
    return;
}

void MenuCLI::exportData(void) {
    return;
}

void MenuCLI::eraseData(void) {
    return;
}

void MenuCLI::importData(void) {
    return;
}
