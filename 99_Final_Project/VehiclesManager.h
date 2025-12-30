#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

#include "Car.h"
#include "Motorbike.h"
#include "Truck.h"

void print_graphic(const VehicleType &vType);
void print_collection(const std::vector<std::unique_ptr<Vehicle>> &vVehicles);
void sort_collection(std::vector<std::unique_ptr<Vehicle>> &vVehicles, const int &sort_option);
void filter_by_vehicle(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const VehicleType &vType = VehicleType::All);
void filter_by_string(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const std::string &strCriteria, const bool &isModel = false);
void filter_by_year(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const int &yearFrom, const int &yearTo = -1);
void filter_by_fuel(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const FuelType &fType);