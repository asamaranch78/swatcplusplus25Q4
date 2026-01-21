#include "dataSet.h"
#include <cstdlib>
#include <memory>
#include <string>

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

void DataSet::preFilter() {
    if (!filtering) { 
        system("touch file1000");
        preFilteredSet = dataSet;
    }
    else {
        system("touch file1001");
        preFilteredSet = filteredData;
    }
    filteredData.clear();
}

void DataSet::filterByYear(uint16_t beginYear, uint16_t endYear) {
    preFilter();
    filtering = true;
    if (endYear != 0) {
        for (auto vehicle: preFilteredSet) {
            if (beginYear <= vehicle->year && endYear >= vehicle->year) {
                filteredData.push_back(vehicle);
            }
        }
    }
    else {
        for (auto vehicle: preFilteredSet) {
            if (beginYear <= vehicle->year) {
                filteredData.push_back(vehicle);
            }
        }
    }
}

void DataSet::filterByManufacturer(std::string manufacturer) {
    preFilter();
    filtering = true;
    for (auto vehicle: preFilteredSet) {
        if (vehicle->manufacturer.data() == manufacturer.data()) {
            filteredData.push_back(vehicle);
        }
    }
}

void DataSet::filterByType(enum Types type) {
    preFilter();
    filtering = true;
    for (auto vehicle: preFilteredSet) {
        if (vehicle->type == type) {
            filteredData.push_back(vehicle);
        }
    }
}
