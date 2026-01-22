#include "filterActions.h"
#include "enums.h"
#include "manufacturerWindow.h"
#include "selectionList.h"
#include "yearWindow.h"
#include "customExceptions.h"

void filter(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin){
    SelectionList window1(mainWin, FILTER_TYPE_TEXTS);
    uint8_t filter = window1.handleList();

    switch (calculateFilterType(filter)) {
        case FilterTypes::YEAR:
            filterByYear(data, mainWin);
            break;
        case FilterTypes::MANUFACTURER:
            filterByManufacturer(data, mainWin);
            break;
        case FilterTypes::TYPE:
            filterByType(data, mainWin);
            break;
        default:
            throw badFilterType {};
    }
}

void filterByYear(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    uint16_t beginYear, endYear;
    YearWindow form(mainWin);
    if (form.askForData()) {
        beginYear = form.getBeginYear();
        endYear = form.getEndYear();
        data->filterByYear(beginYear, endYear);
    }
}

void filterByManufacturer(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin) {
    std::string manufacturer;
    ManufacturerWindow form(mainWin);
    if (form.askForData()) {
        manufacturer = form.getManufacturer();
        data->filterByManufacturer(manufacturer);
    }
}

void filterByType(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin){
    SelectionList window1(mainWin, TYPES_TEXTS);
    uint8_t type = window1.handleList();
    data->filterByType(calculateType(type));
}

void sort(std::shared_ptr<DataSet> data, std::shared_ptr<MainWindow> mainWin){
    SelectionList window1(mainWin, FILTER_TYPE_TEXTS);
    uint8_t filter = window1.handleList();

    switch (calculateFilterType(filter)) {
        case FilterTypes::YEAR:
            data->sortByYear();
            break;
        case FilterTypes::MANUFACTURER:
            data->sortByManufacturer();
            break;
        case FilterTypes::TYPE:
            data->sortByType();
            break;
        default:
            throw badFilterType {};
    }
}
