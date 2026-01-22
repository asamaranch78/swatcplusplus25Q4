#ifndef __DATA_SET_H__
#define __DATA_SET_H__

#include <memory>
#include <vector>
#include "vehicle.h"

class DataSet {
private:
    void importCar(YAML::Node node);
    void importTruck(YAML::Node node);
    void importMotorbike(YAML::Node node);
public:
    std::vector<std::shared_ptr<Vehicle>> dataSet;
    std::vector<std::shared_ptr<Vehicle>> filteredData;
    std::vector<std::shared_ptr<Vehicle>> preFilteredSet;
    bool filtering;
    DataSet();
    void addVehicle(std::shared_ptr<Vehicle> ptr);
    void deleteVehicle(size_t index);
    std::shared_ptr<Vehicle> getVehicle (uint16_t index);
    void deletaAllData();
    std::vector<std::shared_ptr<Vehicle>> getDisplayData();
    void clearFilter();
    void preFilter();
    void filterByYear(uint16_t beginYear, uint16_t endYear);
    void filterByManufacturer(std::string manufacturer);
    void filterByType(enum Types type);
    void exportToYaml(std::string path);
    void importFromYaml(std::string path);
};

#endif
