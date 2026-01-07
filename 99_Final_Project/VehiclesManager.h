#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "Car.h"
#include "Motorbike.h"
#include "Truck.h"

void pause_app(const char *message);
void print_graphic(const VehicleType &vType);
void print_collection(const std::vector<std::unique_ptr<Vehicle>> &vVehicles);
void search_by_id(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const uint64_t &id);
void sort_collection(std::vector<std::unique_ptr<Vehicle>> &vVehicles, const int &sort_option);
void filter_by_vehicle(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const VehicleType &vType = VehicleType::Unknown);
void filter_by_string(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const std::string &strCriteria, const bool &isModel = false);
void filter_by_year(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const int &yearFrom, const int &yearTo = -1);
void filter_by_fuel(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const FuelType &fType);
bool save_data(const std::vector<std::unique_ptr<Vehicle>> &vVehicles);
std::vector<std::unique_ptr<Vehicle>> load_data();