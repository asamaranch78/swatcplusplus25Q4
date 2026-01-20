#include "dataSet.h"
#include <memory>

DataSet::DataSet() {
    filtering = false;
}

void DataSet::addVehicle(std::shared_ptr<Vehicle> ptr) {
    dataSet.push_back(ptr);
}

void DataSet::deleteVehicle(size_t index) {
    dataSet.erase(dataSet.begin() + index);
}

void DataSet::deletaAllData() {
    dataSet.clear();
}

std::vector<std::shared_ptr<Vehicle>> DataSet::getDisplayData() {
    if (filtering)  { return filteredData;  }
    else            { return dataSet;       }
}

void DataSet::clearFilter() {
    filtering = false;
    filteredData.clear();
}

void DataSet::filterByYear(uint16_t beginYear, uint16_t endYear) {
    filtering = true;
    for (auto vehicle: dataSet) {
        if (beginYear <= vehicle->year && endYear >= vehicle->year) {
            filteredData.push_back(vehicle);
        }
    }
}

void DataSet::filterByManufacturer(std::string manufacturer) {
    filtering = true;
    for (auto vehicle: dataSet) {
        if (vehicle->manufacturer == manufacturer) {
            filteredData.push_back(vehicle);
        }
    }
}

void DataSet::filterByType(enum Types type) {
    filtering = true;
    for (auto vehicle: dataSet) {
        if (vehicle->type == type) {
            filteredData.push_back(vehicle);
        }
    }
}
