#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>
#include <memory>
#include <algorithm>
#include <map>
#include "common/Utils.h"
#include "app/Vehicles.h"
#include "app/Car.h"
#include "app/Bike.h"
#include "app/Truck.h"
#include "common/Exceptions.h"

bool user_interface(Vehicles &vehicles);
void display_menu();
void add_vehicle(Vehicles &vehicles);
void list_vehicles(const Vehicles &vehicles);
void calculate_efficiency(Vehicles &vehicles);
void save_data_in_file(Vehicles &vehicles);
void load_data_from_file(Vehicles &vehicles);
void sort_list(Vehicles &vehicles);
void filter_list(Vehicles &vehicles);

int main() {
    Vehicles list;
    load_data_from_file(list);
    
    bool loop_active {1};
    while(loop_active){
        loop_active = user_interface(list);
    }
    
    YesNo save {};
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getUserInput("\nDo you want to save the current data list? (Y/N) ") >> save;
    if(save == Yes)
        save_data_in_file(list);
    return 0;
}

void display_menu(){
    std::cout << std::setw(menu_width) << std::left << std::setfill('-') << "-" << std::endl; std::cout << std::setfill(' ');
    std::cout << std::setw(menu_width) << std::left << "\n A - Add a new vehicle" << std::endl;
    std::cout << std::setw(menu_width) << std::left << " L - List all the vehicles" << std::endl;
    std::cout << std::setw(menu_width) << std::left << " S - Sort the vehcile list" << std::endl;
    std::cout << std::setw(menu_width) << std::left << " F - Filter the vehicle list" << std::endl;
    std::cout << std::setw(menu_width) << std::left << " C - Compute fuell efficiency\n" << std::endl;
    std::cout << std::setw(menu_width) << std::left << std::setfill('-') << "-" << std::endl; std::cout << std::setfill(' ');
    std::cout << "Enter a selection (Q to quit): ";
}

bool user_interface(Vehicles &vehicles){
    bool result {true};
    Actions user_selection;
    display_menu();
    try{
        std::cin >> user_selection;
    } catch (const IncorrectUserInputException &ex){
            std::cerr << ex.what() << std::endl;
    }
    clearScreen();
    switch (user_selection)
    {
    case Add:
        add_vehicle(vehicles);
        break;
    case List:
        list_vehicles(vehicles);
        break;
    case Sort:
        sort_list(vehicles);
        break;
    case Filter:
        filter_list(vehicles);
        list_vehicles(vehicles);
        break;
    case Compute:
        calculate_efficiency(vehicles);
        list_vehicles(vehicles);
        break;
    case Quit:
        result = false;
        break;
    case Unknown:
        /* Case executed after exception, To Do nothing */
        break;
    default:
        break;
    }
    std::cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return result;
}

void add_vehicle(Vehicles &vehicles){
    std::unique_ptr<Vehicle> Veh;
    VehicleType vehType;
    static std::string brand {}; 
    static std::string model {};
    static int year {};
    static FuelType fuelType {};
    static int weight {};
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Introduce the following information about the vehicle:" << std::endl;
    try {
        getUserInput("Select the vehicle type ( 1-CAR | 2-BIKE | 3-TRUCK ): ") >> vehType;
        getUserInput("Brand: ") >> brand;
        getUserInput("Model: ") >> model;
        getUserInput("Year: ") >> year;
        getUserInput("Weight(KG): ") >> weight;
        if(vehType == Bikes){
            static BikeType bikeType;
            static YesNo hasCarrier;
            getUserInput("Bike Type ( 1-Road | 2-Mountain | 3-Standard | 4-Mountain_Electric | 5-Standard_Electric): ") >> bikeType;
            if(bikeType < 4)
                fuelType = Human;
            else
                fuelType = Electric;
            getUserInput("Has Carrier ( Yes | No ): ") >> hasCarrier;
            Veh = std::make_unique<Bike>(brand, model, year, fuelType, weight, bikeType, hasCarrier);
        } else {
            getUserInput("Fuel Type ( 1-Electric | 2-Hybrid | 3-Gasoline | 4-Diesel ): ") >> fuelType;
            if(fuelType > 4)
                throw IncorrectUserInputException();
            if(vehType == Cars){
                static int doors;
                static int trunk;
                getUserInput("Number of Doors: ") >> doors;
                getUserInput("Trunk Capacity (L): ") >> trunk;
                Veh = std::make_unique<Car>(brand, model, year, fuelType, weight, trunk, doors);
            } else if(vehType == Trucks) {
                static int axles;
                static int load;
                getUserInput("Number of Axles: ") >> axles;
                getUserInput("Payload Capacity (KG): ") >> load;
                Veh = std::make_unique<Truck>(brand, model, year, fuelType, weight, load, axles);
            } else {
                std::cout << "INVALID VEHICLE" << std::endl;
                throw IncorrectUserInputException();
            }
        }
        if (vehicles.add_vehicle(std::move(Veh))) {
            std::cout << "Vehicle " << brand << " " << model << " correctly added" << std::endl;
            vehicles.save_data(std::move(Veh));
        } else {
            std::cout << "Vehicle " << brand << " " << model << " already exists" <<  std::endl;
        }
    } catch (const IncorrectUserInputException &ex){
            std::cerr << ex.what() << std::endl;
    } catch (const IncorrectStringException &ex){
            std::cerr << ex.what() << std::endl;
    } catch (const IncorrectIntegerException &ex){
            std::cerr << ex.what() << std::endl;
    }
}

void list_vehicles(const Vehicles &vehicles) {
    vehicles.display();
}

void calculate_efficiency(Vehicles &vehicles){
    vehicles.calc_efficiency();
}

void save_data_in_file(Vehicles &vehicles){
    vehicles.save_data();
}

void load_data_from_file(Vehicles &vehicles){
    std::unique_ptr<Vehicle> Veh;
    VehicleType vehType {};
    std::string vehType_s {};
    std::string id {};
    std::string brand {}; 
    std::string model {};
    int year {};
    FuelType fuelType {};
    std::string fuelType_s {};
    int weight {};
    std::string efficiency {};
    std::ifstream read_in("data/data");
    try{
        if(!read_in){
            std::cerr << "File not found" << std::endl;
            throw InvalidReadFileDataException();
        }
        std::string word {};
        std::string line {};
        std::stringstream line_split {};
        while(std::getline(read_in, line)){
            line_split.str(line);
            line_split >> vehType_s >> id >> brand >> model >> year >> fuelType_s >> weight >> efficiency;
            vehType = string_to_VehicleType(vehType_s);
            fuelType = string_to_FuelType(fuelType_s);
            if(vehType == Bikes){
                BikeType bikeType;
                std::string bikeType_s;
                YesNo hasCarrier;
                std::string hasCarrier_s;
                line_split >> bikeType_s >> hasCarrier_s;
                bikeType = string_to_BikeType(bikeType_s);
                hasCarrier = string_to_YesNo(hasCarrier_s);
                Veh = std::make_unique<Bike>(brand, model, year, fuelType, weight, bikeType, hasCarrier, efficiency);
            } else {
                int spec1;
                int spec2;
                line_split >> spec1 >> spec2;
                if(vehType == Cars){
                    Veh = std::make_unique<Car>(brand, model, year, fuelType, weight, spec1, spec2, efficiency);
                } else if(vehType == Trucks) {
                    Veh = std::make_unique<Truck>(brand, model, year, fuelType, weight, spec1, spec2, efficiency);
                } else {
                    std::cerr << "Something went wrong! Vehicle type is invalid, please check the data file." << std::endl;
                    throw InvalidReadFileDataException();
                }
            }
            if (!vehicles.add_vehicle(std::move(Veh))) {
                std::cout << "Vehicle " << brand << " " << model << " could not be added from the data file" <<  std::endl;
                throw InvalidReadFileDataException();
            }
            line_split.str("");
            line_split.clear();
        }
        read_in.close();
    } catch (const IncorrectUserInputException &ex){
        std::cerr << ex.what() << std::endl;
        read_in.close();
    }
}

void sort_list(Vehicles &vehicles){
    Attribute sel;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    do {
        clearScreen();
        std::cout << "SORTING MODE - Select a sorting type or press any other key to exit\n" << std::endl; 
        vehicles.display();
        std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        getUserInput("Select sorting ( 1-Efficiency | 2-VehType | 3-Id | 4-Brand | 5-Model | 6-Year): ") >> sel;
        vehicles.sort(sel);
    } while(sel != Unknown6);
}

void filter_list(Vehicles &vehicles){
    ActionsFilter user_selection;
    int filter_id {};
    int filter_selected {};
    //std::vector<MyFilter> filter_list;
    static std::map<int, MyFilter> filter_list {};
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    do {
        MyFilter my_filter;
        clearScreen();
        std::cout << "FILTER MODE - Select a filter type or press any other key to exit\n" << std::endl; 
        vehicles.display();
        std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(!filter_list.empty()){
            std::cout << "Filters active:" << std::endl;
            std::cout   << std::setw(vehicle_parameter_width) << std::left << "ID"
                        << std::setw(vehicle_parameter_width) << std::left << "ATTRIBUTE"
                        << std::setw(vehicle_parameter_width) << std::left << "VALUE/MIN"
                        << std::setw(vehicle_parameter_width) << std::left << "MAX" << std::endl;
            for(const auto f:filter_list) {
                std::cout << std::setw(vehicle_parameter_width) << std::left << f.second.id
                          << std::setw(vehicle_parameter_width) << std::left << Attribute_to_string(f.second.atr)
                          << std::setw(vehicle_parameter_width) << std::left << f.second.min_range
                          << std::setw(vehicle_parameter_width) << std::left << f.second.max_range << std::endl;
            }
            std:: cout << std::endl;
        }
        try{
            getUserInput("Select the action to perform ( A - Add Filter | R - Remove Filter | C - Clear all filters ): ") >> user_selection;
        } catch (const IncorrectUserInputException &ex){
            //std::cerr << ex.what() << std::endl;
            // Clean Exit, no need to do anything
        }
        switch (user_selection)
        {
        case AddFilter:
            getUserInput("Select filter attribute ( 1-Efficiency | 2-VehType | 3-Id | 4-Brand | 5-Model | 6-Year): ") >> my_filter.atr;
            if(my_filter.atr != Unknown6){
                if(my_filter.atr == Efficiency || my_filter.atr == Year){
                    getUserInput("Select filter value range ( Min Max ): ") >> my_filter.min_range >> my_filter.max_range;
                    if(my_filter.min_range.empty() || my_filter.max_range.empty())
                        break;
                } else {
                    getUserInput("Select filter value: ") >> my_filter.min_range;
                    my_filter.max_range = "";
                }
                vehicles.filter(my_filter);
                if(my_filter.active){
                    my_filter.id = filter_id++;
                    filter_list.insert({my_filter.id, my_filter});
                    //filter_list.emplace_back(my_filter);
                }
            }
            break;
        case RemoveFilter:
            getUserInput("Select filter ID from active list: ") >> filter_selected;
            vehicles.unfilter(filter_list[filter_selected]);
            filter_list.erase(filter_selected);
            for(auto f: filter_list)
                vehicles.filter(f.second);
            break;
        case ClearFilters:
            for(auto f: filter_list)
                vehicles.unfilter(f.second);
            filter_list.clear();
            break;
        case Unknown7:
            /* Case executed after exception, To Do nothing */
            break;
        default:
            break;
        }
    } while(user_selection != Unknown7);
}
