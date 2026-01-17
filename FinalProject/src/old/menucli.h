#ifndef __MENUCLI_H__
#define __MENUCLI_H__

#include <ncurses.h>
#include <vector>
#include <array>
#include <string>

#include "messages.h"
#include "dataSet.h"

class MenuCLI {
private:
    Msg msg;
    unsigned char selectedOption;

    void addVehicle(std::shared_ptr<DataSet> data);
    void removeVehicle(std::shared_ptr<DataSet> data);
    void listVehicles(std::shared_ptr<DataSet> data);
    void filterVehicle(std::shared_ptr<DataSet> data);
    void filterByType(std::shared_ptr<DataSet> data);
    void filterByBrand(std::shared_ptr<DataSet> data);
    void filterByYear(std::shared_ptr<DataSet> data);
    void computeFuelEfficiency(std::shared_ptr<DataSet> data);
    void exportData(std::shared_ptr<DataSet> data);
    void eraseData(std::shared_ptr<DataSet> data);
    void importData(std::shared_ptr<DataSet> data);
public:
    bool askForSelection(void);
    void handleSelection(std::shared_ptr<DataSet> data);
};

#endif
