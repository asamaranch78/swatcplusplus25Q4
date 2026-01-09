#include <cctype>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <memory>

#include "menucli.h"
#include "constants.h"
#include "dataSet.h"
#include "messages.h"
#include "car.h"
#include "truck.h"


bool MenuCLI::askForSelection(void) {
    printMessage(&msg.menuMessages);
    std::cin >> selectedOption;
    selectedOption = std::toupper(selectedOption);
    if (selectedOption == 'Q') { return false; }
    return true;
}

void MenuCLI::handleSelection(std::shared_ptr<DataSet> data) {
    switch (selectedOption) {
        case 'A':
            addVehicle(data);
            break;
        case 'F':
            filterVehicle(data);
            break;
        case 'L':
            listVehicles(data);
            break;
        case 'C':
            computeFuelEfficiency(data);
            break;
        case 'X':
            exportData(data);
            break;
        case 'D':
            eraseData(data);
            break;
        case 'I':
            importData(data);
            break;
        case 'E':
            removeVehicle(data);
            break;
        default:
            std::cout << "Bad selection that option is not available" << std::endl;
    }
}

void MenuCLI::addVehicle(std::shared_ptr<DataSet> data) {
    uint16_t selectedType;
    std::shared_ptr<Car> car = std::make_shared<Car>();
    std::shared_ptr<Truck> truck = std::make_shared<Truck>();
    printMessage(&msg.menuTypeSelection);
    std::cin >> selectedType;
    switch (selectedType) {
        case 1:
            car->askUserData(&msg);
            data->addVehicle(car);
            break;
        case 2:
            //Make Electric car
            std::cout << "Not implemented";
            break;
        case 3:
            truck->askUserData(&msg);
            data->addVehicle(truck);
            break;
        case 4:
            //Make motorbike
            std::cout << "Not implemented";
            break;
        default:
            std::cout << "Invalid value";
    }

}

void MenuCLI::removeVehicle(std::shared_ptr<DataSet> data) {
    if (data) { return; }
}

void MenuCLI::listVehicles(std::shared_ptr<DataSet> data) {
    uint16_t index;
    printListHeader();
    for (const auto& point : data->dataSet) {
        std::cout << std::setw(SHORT_GAP) << index;
        index++;
        point->info();
    }

    return;
}

void MenuCLI::filterVehicle(std::shared_ptr<DataSet> data) {
    if (data) { return; }
}

void MenuCLI::filterByType(std::shared_ptr<DataSet> data) {
    if (data) { return; }
}

void MenuCLI::filterByBrand(std::shared_ptr<DataSet> data) {
    if (data) { return; }
}

void MenuCLI::filterByYear(std::shared_ptr<DataSet> data) {
    if (data) { return; }
}

void MenuCLI::computeFuelEfficiency(std::shared_ptr<DataSet> data) {
    if (data) { return; }
}

void MenuCLI::exportData(std::shared_ptr<DataSet> data) {
    if (data) { return; }
}

void MenuCLI::eraseData(std::shared_ptr<DataSet> data) {
    if (data) { return; }
}

void MenuCLI::importData(std::shared_ptr<DataSet> data) {
    if (data) { return; }
}
