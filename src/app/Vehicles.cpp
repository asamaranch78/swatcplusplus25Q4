#include <iostream>
#include <iomanip>
#include <memory>
#include <fstream>
#include <algorithm>
#include "common/Utils.h"
#include "Vehicles.h"

void Vehicles::display() const {
    if (vehicles.size() == 0) {
        std::cout << "Sorry, no vehicles to display\n" << std::endl;
    } else {
        std::cout << std::setw(menu_width) << std::left << std::setfill('*') << "*" << std::endl; std::cout << std::setfill(' ');
        std::cout   << std::setw(vehicle_parameter_width) << std::left << "TYPE"
                    << std::setw(vehicle_parameter_width) << std::left << "ID"
                    << std::setw(vehicle_parameter_width) << std::left << "BRAND"
                    << std::setw(vehicle_parameter_width) << std::left << "MODEL"
                    << std::setw(vehicle_parameter_width) << std::left << "YEAR"
                    << std::setw(vehicle_parameter_width) << std::left << "FUEL TYPE"
                    << std::setw(vehicle_parameter_width) << std::left << "WEIGHT"
                    << std::setw(vehicle_parameter_width) << std::left << "EFFICIENCY"
                    << std::setw(vehicle_parameter_width) << std::left << "Spec1"
                    << std::setw(vehicle_parameter_width/2) << std::right << "Spec2" << std::endl;
        std::cout << std::setw(menu_width) << std::left << std::setfill('*') << "*" << std::endl; std::cout << std::setfill(' ');
        for (const auto &vehicle: vehicles)
            std::cout << *vehicle << std::endl;
        std::cout << std::setw(menu_width) << std::left << std::setfill('*') << "*" << std::endl; std::cout << std::setfill(' ');
        std::cout << std::endl;
    }
}

bool Vehicles::add_vehicle(std::unique_ptr<Vehicle> vehicle) {
    for (const auto &veh: vehicles) {
        if (veh->get_id() == vehicle->get_id())
            return false;
    }
    vehicles.push_back(std::move(vehicle));
    return true;
}

bool Vehicles::calc_efficiency(std::unique_ptr<Vehicle> vehicle) {
    bool result {false};
    if(vehicle == nullptr){
        for (const auto &veh: vehicles) {
            result = veh->compute_efficiency();
            if(!result)
                return result;
        }
    } else {
        result = vehicle->compute_efficiency();
    }
    return result;
}

bool Vehicles::save_data(std::unique_ptr<Vehicle> vehicle) {
    if(vehicle == nullptr){
        std::ofstream write_in {"data/data", std::ios::trunc};
        if(!write_in){
            std::cerr << "Error creating write file" << std::endl;
            return false;
        }
        if (vehicles.size() == 0) {
            std::cout << "Sorry, no vehicles to save\n" << std::endl;
            return false;
        } else {        
            for (const auto &veh: vehicles)
                write_in << *veh << std::endl;
        }
        write_in.close();
    } else {
        std::ofstream write_in {"data", std::ios::app};
        if(!write_in){
            std::cerr << "Error creating write file" << std::endl;
            return false;
        }
        write_in << *vehicle << std::endl;
        write_in.close();
    }
    return true;
}

void Vehicles::sort(const Attribute &sel){
    if(sel == Efficiency){ // default efficiency
        std::sort(vehicles.begin(), vehicles.end(),
            [](const auto &v1, const auto &v2) {
                return *v1 < *v2;
            });
    } else if(sel == VehType){ //type
        std::sort(vehicles.begin(), vehicles.end(),
            [](const auto &v1, const auto &v2) {
                return v1->get_type() < v2->get_type();
            });
    } else if(sel == Id){ //id
        std::sort(vehicles.begin(), vehicles.end(),
            [](const auto &v1, const auto &v2) {
                return v1->get_id() < v2->get_id();
            });
    } else if(sel == Brand){ //brand
        std::sort(vehicles.begin(), vehicles.end(),
            [](const auto &v1, const auto &v2) {
                return v1->get_brand() < v2->get_brand();
            });
    } else if(sel == Model){ //model
        std::sort(vehicles.begin(), vehicles.end(),
            [](const auto &v1, const auto &v2) {
                return v1->get_model() < v2->get_model();
            });
    } else if(sel == Year){ //year
        std::sort(vehicles.begin(), vehicles.end(),
            [](const auto &v1, const auto &v2) {
                return v1->get_year() < v2->get_year();
            });
    }
}

void Vehicles::filter(MyFilter &my_filter){
    std::stringstream ss {my_filter.min_range+" "+my_filter.max_range};
    std::string min {}, max {};
    ss >> min >> max;
    auto new_end = std::partition(vehicles.begin(), vehicles.end(),
        [&] (auto &v) {
            if(my_filter.atr == Efficiency){ // default efficiency
                return (v->get_efficiency_class()>=min && v->get_efficiency_class()<=max);
            } else if(my_filter.atr == VehType){
                return (v->get_type() == string_to_VehicleType(min));
            } else if(my_filter.atr == Id){
                return (v->get_id() == min);
            } else if(my_filter.atr == Brand){
                return (v->get_brand() == min);
            } else if(my_filter.atr == Model){
                return (v->get_model() == min);
            } else if(my_filter.atr == Year){ 
                return (v->get_year()>=stoi(min) && v->get_year()<=stoi(max));
            } else
                return false;
        });
    if (new_end == vehicles.begin()) { //Everything erased
        std::cout << "Selected filter is invalid, full list is empty!" << std::endl;
    } else if (new_end != vehicles.end()){ //Something erased
        for (auto it = new_end; it != vehicles.end(); ++it) { //Backup vector elements before erasing
            backup.push_back(std::move(*it));
        }
        vehicles.erase(new_end, vehicles.end());
        my_filter.active = true;
    } 
}

void Vehicles::unfilter(MyFilter &my_filter){
    std::stringstream ss {my_filter.min_range+" "+my_filter.max_range};
    std::string min {}, max {};
    ss >> min >> max;
    auto new_end = std::partition(backup.begin(), backup.end(),
        [&] (auto &v) {
            if(my_filter.atr == Efficiency){ // default efficiency
                return (v->get_efficiency_class()>=min && v->get_efficiency_class()<=max);
            } else if(my_filter.atr == VehType){
                return (v->get_type() == string_to_VehicleType(min));
            } else if(my_filter.atr == Id){
                return (v->get_id() == min);
            } else if(my_filter.atr == Brand){
                return (v->get_brand() == min);
            } else if(my_filter.atr == Model){
                return (v->get_model() == min);
            } else if(my_filter.atr == Year){ 
                return (v->get_year()>=stoi(min) && v->get_year()<=stoi(max));
            } else
                return true;
        });
    for (auto it = new_end; it != backup.end(); ++it) { //Backup vector elements before erasing
            this->vehicles.push_back(std::move(*it));
    }
    backup.erase(new_end, backup.end());
    my_filter.active = false;
}