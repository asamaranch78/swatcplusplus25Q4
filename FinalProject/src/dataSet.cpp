#include "dataSet.h"
#include <memory>

void DataSet::addVehicle(std::shared_ptr<Vehicle> ptr) {
    dataSet.push_back(ptr);
}

void DataSet::deleteVehicle(size_t index) {
    dataSet.erase(dataSet.begin() + index);
}

void DataSet::deletaAllData() {
    dataSet.clear();
}
