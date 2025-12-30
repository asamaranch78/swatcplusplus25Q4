/*
    Author: Juan M. Lagostena
    Dec 18, 2025
*/

#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <limits>
#include <vector>
#include <memory>
//#include <algorithm>
//#include <functional>

#include "VehiclesManager.h"
#include "Menus.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
//using std::stringstream;

int main()
{
    int menu_option {-1};

    // Initial objects for the vehicles collection.
    Car myCar {"Toyota", "Corolla", 2006, 978.3, 62.3, FuelType::Gas, 1100.25};
    Car otherCar {"Toyota", "Corolla", 2002, 970.3, 60, FuelType::Gas, 2200.3};
    Motorbike myBike {"Harley-Davidson", "883", 2017, 110.2, 18.2, MotorbikeType::Custom};
    Truck myTruck {"Volvo", "Wolf", 2018, 2500, 325.2};

    auto v1 = std::make_unique<Car>(myCar);
    auto v2 = std::make_unique<Car>(otherCar);
    auto v3 = std::make_unique<Motorbike>(myBike);
    auto v4 = std::make_unique<Truck>(myTruck);

    std::vector<std::unique_ptr<Vehicle>> vVehicles;
    vVehicles.emplace_back(std::move(v1));
    vVehicles.emplace_back(std::move(v2));
    vVehicles.emplace_back(std::move(v3));
    vVehicles.emplace_back(std::move(v4));

    cout << std::boolalpha;
    /*
    cout << " Vehicles set contains " << vVehicles.size() << " elements" << endl;
    cout << " BEFORE" << endl;
    print_collection(vVehicles);

    std::sort(vVehicles.begin(), vVehicles.end(), [](auto &a, auto &b){ return *a < *b; });
    cout << " AFTER" << endl;
    print_collection(vVehicles);

    // PROVISIONAL
    return 0;
    
    pause_menu(" Press Enter to continue");
    */

    while (true)
    {
        print_menu();
        menu_option = get_menu_option(7);

        // Exit.
        if (menu_option == 0) break;

        switch (menu_option)
        {
            // Add vehicle.
            case 1:
            {
                system("clear");
                cout << "ADD VEHICLE" << endl;

                // Common params.
                double tank {};
                FuelType vFuel {FuelType::None};

                // Car related params.
                CarType cType {CarType::Sedan};
                double trunkCapacity {};
                int numDoors {};
                // Motorbike related params.
                MotorbikeType mType {MotorbikeType::Naked};
                // Truck related params.
                TruckType tType {TruckType::Two_axle};
                // Vehicle type extraction from user input using template function.
                VehicleType vVType = get_enum_value<VehicleType>("\nSelect type\n0 > Car, 1 > Truck, 2 > Motorbike\nSelect (0 - 3): ", 3);

                system("clear");

                // Shows an ASCII graphic
                print_graphic(vVType);

                std::string brand = get_user_answer<std::string>("Brand: ");
                std::string model = get_user_answer<std::string>("Model: ");
                int year = get_user_answer<int>("Year: ");
                double weight = get_user_answer<double>("Weight (kg): ");
                
                // Super class parameters.
                tank = get_user_answer<double>("Tank capacity (l): ");
                vFuel = get_enum_value<FuelType>("Fuel type\n0 > Gas, 1 > Diesel, 2 > Electric, 3 > Hybrid\nSelect (0 - 3): ", 3);

                if (vVType == VehicleType::Car)
                {
                    cType = get_enum_value<CarType>("Car type\n0 > Sedan, 1 > Station wagon, 2 > MPV, 3 > Van, 4 > Sports car, 5 > SUV, 6 > Off-road\nSelect (0 - 6): ", 6);
                    trunkCapacity = get_user_answer<double>("Trunk capacity (l): ");
                    numDoors = get_user_answer<int>("Doors (2 to 5): ");

                    Car aCar {brand, model, year, weight, tank, vFuel, trunkCapacity, numDoors, cType};
                    auto vCar = std::make_unique<Car>(aCar);
                    vVehicles.emplace_back(std::move(vCar));
                }
                else if (vVType == VehicleType::Motorbike)
                {
                    mType = get_enum_value<MotorbikeType>("Motorbike type\n0 > Sport bike, 1 > Custom, 2 > Chopper, 3 > Naked, 4 > Scooter, 5 > Touring, 6 > Motocross\n"
                        "Select (0 - 5): ", 5);

                    Motorbike aMBike {brand, model, year, weight, tank, mType, vFuel};
                    auto vMBike = std::make_unique<Motorbike>(aMBike);
                    vVehicles.emplace_back(std::move(vMBike));
                }
                else if (vVType == VehicleType::Truck)
                {
                    tType = get_enum_value<TruckType>("Truck type\n0 > Two axle, 1 > Three axle, 2 > Four axle, 3 > Five axle,\nSelect (0 - 3): ", 3);

                    Truck aTruck {brand, model, year, weight, tank, tType, vFuel};
                    auto vTruck = std::make_unique<Truck>(aTruck);
                    vVehicles.emplace_back(std::move(vTruck));
                }
            }
                break;

            // List vehicles.
            case 2:
                print_collection(vVehicles);
                break;

            // Search vehicles.
            case 3:
                break;

            // Sort vehicles.
            case 4:
            {
                print_sort_menu();
                int sort_option = get_menu_option(5);
                if (sort_option == 0) break;
                sort_collection(vVehicles, sort_option);
                print_collection(vVehicles);
            }
                break;

            // Filter collection.
            case 5:
            {
                print_filter_menu();
                int filter_option = get_menu_option(6);
                if (filter_option == 0) break;

                // By vehicle type.
                if (filter_option == 1)
                {
                    VehicleType vehicle_option = get_enum_value<VehicleType>("\nSelect type\n0 > Car, 1 > Truck, 2 > Motorbike\nSelect (0 - 3): ", 3);
                    if (vehicle_option == VehicleType::All) break;

                    system("clear");
                    filter_by_vehicle(vVehicles, vehicle_option);
                }
                // By brand.
                else if (filter_option == 2)
                {
                    std::string brand = get_user_answer<std::string>("Brand: ");
                    if (brand.length() == 0) break;

                    system("clear");
                    filter_by_string(vVehicles, brand);
                }
                // By Model.
                else if (filter_option == 3)
                {
                    std::string model = get_user_answer<std::string>("Model: ");
                    if (model.length() == 0) break;

                    system("clear");
                    filter_by_string(vVehicles, model, true);
                }
                // By year.
                else if (filter_option == 4)
                {
                    int yearFrom = get_user_answer<int>("Year: ");
                    if (yearFrom <= 0) break;

                    system("clear");
                    filter_by_year(vVehicles, yearFrom);
                }
                // By year range.
                else if (filter_option == 5)
                {
                    int yearFrom = get_user_answer<int>("From year: ");
                    int yearTo = get_user_answer<int>("To year: ");
                    if (yearFrom <= 0 || yearTo <= 0 || yearFrom > yearTo) break;

                    system("clear");
                    filter_by_year(vVehicles, yearFrom, yearTo);
                }
                // By fuel type.
                else if (filter_option == 6)
                {
                    FuelType fType = get_enum_value<FuelType>("Fuel type\n0 > Gas, 1 > Diesel, 2 > Electric, 3 > Hybrid\nSelect (0 - 3): ", 3);
                    if (fType == FuelType::None) break;

                    system("clear");
                    filter_by_fuel(vVehicles, fType);
                }
                else
                {
                    break;
                }
                //filter_collection(vVehicles, 0);
            }
                break;

            // Save data.
            case 6:
            // Load data.
            case 7:
                break;

            default:
                pause_menu(" Option invalid, press Enter to retry.");
                break;
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}