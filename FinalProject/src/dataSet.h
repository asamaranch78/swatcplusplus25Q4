#ifndef __DATA_SET_H__
#define __DATA_SET_H__

#include <memory>
#include <vector>
#include "vehicle.h"

class DataSet {
public:
    std::vector<std::shared_ptr<Vehicle>> dataSet;
    void addVehicle(std::shared_ptr<Vehicle> ptr);
    void deleteVehicle(size_t index);
    void deletaAllData();
};

#endif
