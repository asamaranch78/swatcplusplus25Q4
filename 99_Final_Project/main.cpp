/*
    Author: Juan M. Lagostena
    Dec 18, 2025
*/

#include "VehiclesManager.h"
#include "Menus.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

template<class T>
T ask_enum(const string &prompt, const int &maxValue)
{
    int value = ask_int(prompt, maxValue, true);
    std::underlying_type_t<T> a_Type {value};
    T aType {T{a_Type}};

    return aType;
}

int main()
{
    int menu_option {-1};

    // Initial objects for the vehicles collection.
    Car myCar {"Toyota", "Corolla", 2006, 978.3, 62.3, FuelType::Gas, 8.9, 1100.25};
    Car otherCar {"Nissan", "Yuke", 2022, 1150.7, 60, FuelType::Gas, 4.9, 2200.3};
    Motorbike myBike {"Harley-Davidson", "883", 2017, 110.2, 18.2, FuelType::Gas, 6.5, MotorbikeType::Custom};
    Truck myTruck {"Volvo", "Wolf", 2018, 2500, 325.2, FuelType::Diesel, 14.2, TruckType::Three_axle};

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

    while (true)
    {
        print_menu();
        menu_option = ask_int("Choose an option", 7, true);

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
                FuelType vFuel {FuelType::Unknown};
                double baseConsumption {};

                // Car related params.
                CarType cType {CarType::Sedan};
                double trunkCapacity {};
                int numDoors {};
                // Motorbike related params.
                MotorbikeType mType {MotorbikeType::Naked};
                // Truck related params.
                TruckType tType {TruckType::Two_axle};
                // Vehicle type extraction from user input using template function.
                VehicleType vVType = ask_enum<VehicleType>("\nSelect type\n0 > Car, 1 > Truck, 2 > Motorbike", 3);

                system("clear");

                // Shows an ASCII graphic
                print_graphic(vVType);

                string brand = ask_string("Brand");
                string model = ask_string("Model");
                int year = ask_int("Year", 2026, true);
                double weight = ask_double("Weight (kg)", 0, false);
                
                // Super class parameters.
                tank = ask_double("Tank capacity (l)", 0, false);
                vFuel = ask_enum<FuelType>("Fuel type\n0 > Gas, 1 > Diesel, 2 > Electric, 3 > Hybrid", 3);
                baseConsumption = ask_double("Consumption (l/kWh per 100km)", 0, false);

                if (vVType == VehicleType::Car)
                {
                    cType = ask_enum<CarType>("Car type\n0 > Sedan, 1 > Station wagon, 2 > MPV, 3 > Van, 4 > Sports car, 5 > SUV, 6 > Off-road", 6);
                    trunkCapacity = ask_double("Trunk capacity (l)", 0, false);
                    numDoors = ask_int("Doors (2 to 5)", 5, true);

                    Car aCar {brand, model, year, weight, tank, vFuel, baseConsumption, trunkCapacity, numDoors, cType};
                    auto vCar = std::make_unique<Car>(aCar);
                    vVehicles.emplace_back(std::move(vCar));
                }
                else if (vVType == VehicleType::Motorbike)
                {
                    mType = ask_enum<MotorbikeType>("Motorbike type\n0 > Sport bike, 1 > Custom, 2 > Chopper, 3 > Naked, 4 > Scooter, 5 > Touring, 6 > Motocross", 5);

                    Motorbike aMBike {brand, model, year, weight, tank, vFuel, baseConsumption, mType};
                    auto vMBike = std::make_unique<Motorbike>(aMBike);
                    vVehicles.emplace_back(std::move(vMBike));
                }
                else if (vVType == VehicleType::Truck)
                {
                    tType = ask_enum<TruckType>("Truck type\n0 > Two axle, 1 > Three axle, 2 > Four axle, 3 > Five axle", 3);

                    Truck aTruck {brand, model, year, weight, tank, vFuel, baseConsumption, tType};
                    auto vTruck = std::make_unique<Truck>(aTruck);
                    vVehicles.emplace_back(std::move(vTruck));
                }

                string msg = "Vehicle added to collection (Total: " + std::to_string(vVehicles.size()) + ")\nPress enter to continue.";
                pause_app(msg.c_str());
            }
                break;

            // List vehicles.
            case 2:
                print_collection(vVehicles);
                break;

            // Search vehicles.
            case 3:
            {
                uint64_t id = static_cast<uint64_t>(ask_int("Enter id to search"));
                search_by_id(vVehicles, id);
            }
                break;

            // Sort vehicles.
            case 4:
            {
                print_sort_menu();
                int sort_option = ask_int("Choose an option", 5, true);
                if (sort_option == 0) break;
                sort_collection(vVehicles, sort_option);
                print_collection(vVehicles);
            }
                break;

            // Filter collection.
            case 5:
            {
                print_filter_menu();
                int filter_option = ask_int("Choose an option", 6, true);
                if (filter_option == 0) break;

                // By vehicle type.
                if (filter_option == 1)
                {
                    VehicleType vehicle_option = ask_enum<VehicleType>("\nSelect type\n0 > Car, 1 > Truck, 2 > Motorbike", 3);
                    if (vehicle_option == VehicleType::Unknown) break;

                    system("clear");
                    filter_by_vehicle(vVehicles, vehicle_option);
                }
                // By brand.
                else if (filter_option == 2)
                {
                    string brand = ask_string("Brand");
                    if (brand.length() == 0) break;

                    system("clear");
                    filter_by_string(vVehicles, brand);
                }
                // By Model.
                else if (filter_option == 3)
                {
                    string model = ask_string("Model");
                    if (model.length() == 0) break;

                    system("clear");
                    filter_by_string(vVehicles, model, true);
                }
                // By year.
                else if (filter_option == 4)
                {
                    int yearFrom = ask_int("Year", 2026, true);
                    if (yearFrom <= 0) break;

                    system("clear");
                    filter_by_year(vVehicles, yearFrom);
                }
                // By year range.
                else if (filter_option == 5)
                {
                    int yearFrom = ask_int("From year", 2026, true);
                    int yearTo = ask_int("To year", 2026, true);

                    if (yearFrom <= 0 || yearTo <= 0 || yearFrom > yearTo)
                    {
                        string msg = "Invalid range -> from: " + std::to_string(yearFrom) + ", to: " + std::to_string(yearTo) + "\nPress enter to continue.";
                        pause_app(msg.c_str());

                        break;
                    }

                    system("clear");
                    filter_by_year(vVehicles, yearFrom, yearTo);
                }
                // By fuel type.
                else if (filter_option == 6)
                {
                    FuelType fType = ask_enum<FuelType>("Fuel type\n0 > Gas, 1 > Diesel, 2 > Electric, 3 > Hybrid", 3);
                    if (fType == FuelType::Unknown) break;

                    system("clear");
                    filter_by_fuel(vVehicles, fType);
                }
                else
                {
                    break;
                }
            }
                break;

            // Save data.
            case 6:
                if (save_data(vVehicles))
                {
                    pause_app("Save completed.\nPress enter to continue.");
                }
                else
                {
                    pause_app("No data was saved.\nPress enter to continue.");
                }
                break;

            // Load data.
            case 7:
            {
                vVehicles = std::move(load_data());
                string message {};

                if (vVehicles.empty())
                {
                    pause_app("No data was loaded.\nPress enter to continue.");
                }
                else
                {
                    message = "Data loaded (" + std::to_string(vVehicles.size()) + " vehicles).\nPress enter to continue.";
                    pause_app(message.c_str());
                }
            }
                break;

            default:
                pause_app(" Option invalid, press Enter to retry.");
                break;
        }
    }

    return 0;
}