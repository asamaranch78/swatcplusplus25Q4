#include "dataSet.h"
#include "stringManip.h"
#include "truck.h"
#include "car.h"
#include "electric.h"
#include "motorbike.h"
#include "enums.h"
#include <cstdlib>
#include <fstream>
#include <memory>
#include <string>
#include <yaml-cpp/yaml.h>

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
        preFilteredSet = dataSet;
    }
    else {
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
        if (equal(vehicle->manufacturer, manufacturer)) {
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


void DataSet::exportToYaml(std::string path) {
    YAML::Node list = YAML::Node(YAML::NodeType::Sequence);
    std::ofstream output (path);
    std::vector<std::shared_ptr<Vehicle>> exportData;

    if (!filtering) { exportData = dataSet; }
    else { exportData = filteredData; }

    for (auto vehicle: exportData) {
        list.push_back(vehicle->getYaml());
    }

    output << list;
}

void DataSet::importFromYaml(std::string path) {
    YAML::Node list = YAML::LoadFile(path);
    Types type;
    
    if (!list.IsSequence()) {
        throw;
    }

    for (const auto vehicle: list) {
        type = decodeType(vehicle["Type"].as<std::string>());

        switch (type) {
            case Types::CAR:
                importCar(vehicle);
                break;
            case Types::TRUCK:
                importTruck(vehicle);
                break;
            case Types::MOTORBIKE:
                importMotorbike(vehicle);
                break;
            case Types::ELECTRIC_CAR:
                importElectric(vehicle);
                break;
        }
    }
}

void DataSet::importCar(YAML::Node node) {
    std::shared_ptr<Car> car = std::make_shared<Car>();
    car->loadYaml(node);
    addVehicle(car);
}

void DataSet::importTruck(YAML::Node node) {
    std::shared_ptr<Truck> truck = std::make_shared<Truck>();
    truck->loadYaml(node);
    addVehicle(truck);
}

void DataSet::importMotorbike(YAML::Node node) {
    std::shared_ptr<Motorbike> bike = std::make_shared<Motorbike>();
    bike->loadYaml(node);
    addVehicle(bike);
}

void DataSet::importElectric(YAML::Node node) {
    std::shared_ptr<Electric> car = std::make_shared<Electric>();
    car->loadYaml(node);
    addVehicle(car);
}

std::shared_ptr<Vehicle> DataSet::getVehicle (uint16_t index) {
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    vehicles = getDisplayData();
    return vehicles.at(index);
}
