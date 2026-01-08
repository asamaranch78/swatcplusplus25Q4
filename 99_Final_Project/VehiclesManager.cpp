#include <iomanip>
#include <fstream>
#include <limits>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>

#include "VehiclesManager.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void pause_app(const char *message)
{
    cout << endl << message << endl;
    cin.get();
}

string toLower(const string &s)
{
    string b {s};
    std::transform(b.begin(), b.end(), b.begin(), [] (unsigned char c) {
        return std::tolower(c);
    });

    return b;
}

string get_fuel_string(const FuelType &fType)
{
    switch (fType)
    {
        case (FuelType::Diesel): return "Diesel"; break;
        case (FuelType::Gas): return "Gas"; break;
        case (FuelType::Electric): return "Electric"; break;
        case (FuelType::Hybrid): return "Hybrid"; break;
        case (FuelType::Unknown): return "Unknown"; break;
        default: return "-";
    }
}

string get_vehicle_string(const VehicleType &vType)
{
    switch (vType)
    {
        case (VehicleType::Car): return "CAR"; break;
        case (VehicleType::Truck): return "TRUCK"; break;
        case (VehicleType::Motorbike): return "MOTORBIKE"; break;
        case (VehicleType::Unknown): return "UNKNOWN"; break;
        default: return "-"; break;
    }    
}

void print_graphic(const VehicleType &vehicle) 
{
    string fGraphic {"graphics/"};
    string vFile {};

    system("clear");

    switch (vehicle)
    {
        case VehicleType::Car:
            vFile = "car.txt";
            break;

        case VehicleType::Truck:
            vFile = "truck.txt";
            break;

        case VehicleType::Motorbike:
            vFile = "motorbike.txt";
            break;

        default:
            break;
    }

    fGraphic += vFile;

    std::ifstream graphic_file {fGraphic};
    string gLine {};

    while (std::getline(graphic_file, gLine))
    {
        std::cout << gLine << std::endl;
    }

    graphic_file.close();
}

void print_collection(const vector<std::unique_ptr<Vehicle>> &vVehicles)
{
    int cPage {1};
    size_t i {1};

    system("clear");

    for (const auto &v: vVehicles)
    {
        cout << *v;
        
        if (i % 2 == 0)
        {
            cout << " PAGE " << cPage << "/" << static_cast<int>(std::ceil(vVehicles.size() / 2.0)) << endl;
            if (&v != &vVehicles.back())
            {
                pause_app("Press enter for next page.");
                
                i = 0;
                ++cPage;
                system("clear");
            }
        }

        ++i;
    }

    pause_app("No more elements.\nPress enter to continue.");
}

void search_by_id(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const std::uint64_t &id)
{
    int found {};
    system("clear");

    std::for_each(vVehicles.begin(), vVehicles.end(), [&found, &id](const auto &v) {
        if (v->getId() == id)
        {
            std::cout << *v;
            found++;
        } 
    });

    std::cout << "Found " << found << " vehicles with id: " << id << std::endl;
    pause_app("Press enter to continue...");
}

void sort_collection(vector<std::unique_ptr<Vehicle>> &vVehicles, const int &sort_option)
{
    string sortedBy {};

    switch (sort_option)
    {
        // By year (ascending).
        case 1:
            sortedBy = " Sorted by year (ascending)";
            std::stable_sort(vVehicles.begin(), vVehicles.end(), [] (const auto &a, const auto &b) { return a->get_year() < b->get_year(); });
            break;

        // By brand (ascending).
        case 2:
            sortedBy = " Sorted by brand (ascending)";
            std::stable_sort(vVehicles.begin(), vVehicles.end(), [] (const auto &a, const auto &b) { return a->get_brand() < b->get_brand(); });
            break;
        
        // By model (ascending).
        case 3:
            sortedBy = " Sorted by model (ascending)";
            std::stable_sort(vVehicles.begin(), vVehicles.end(), [] (const auto &a, const auto &b) { return a->get_model() < b->get_model(); });
            break;

        // By fuel efficency (best to worst).
        case 4:
            sortedBy = " Sorted by fuel efficiency (best to worst)";
            std::stable_sort(vVehicles.begin(), vVehicles.end(), [] (const auto &a, const auto &b) { return a->fuel_efficiency() > b->fuel_efficiency(); });
            break;

        // By fuel type (ascending).
        case 5:
            sortedBy = " Sorted by fuel type (ascending)";
            std::stable_sort(vVehicles.begin(), vVehicles.end(), [] (const auto &a, const auto &b) { return a->get_fuel_type() > b->get_fuel_type(); });
            break;

        default:
            break;
    }

    cout << sortedBy << endl;
}

void print_filter_result(std::ostringstream &oss, const int &found)
{
    if (found > 0)
    {
        oss << endl << found << " vehicles match criteria." << endl;
    }
    else
    {
        oss << endl << "No vehicles match criteria." << endl;
    }

    cout << oss.str() << endl;
    pause_app("Press enter to continue...");
}

void filter_by_vehicle(const vector<std::unique_ptr<Vehicle>> &vVehicles, const VehicleType &vType)
{
    std::ostringstream oss;
    oss << "FILTERED BY VEHICLE TYPE: " << get_vehicle_string(vType);
    int found {};

    if (vType == VehicleType::Car)
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
            [&found](const auto &v) { 
                if (dynamic_cast<Car *>(v.get()) != nullptr)
                {
                    std::cout << *v;
                    ++found;
                } 
            });
    }
    else if (vType == VehicleType::Truck)
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
            [&found](const auto &v) { 
                if (dynamic_cast<Truck *>(v.get()) != nullptr)
                {
                    std::cout << *v;
                    ++found;
                } 
            });
    }
    else if (vType == VehicleType::Motorbike)
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
            [&found](const auto &v) { 
                if (dynamic_cast<Motorbike *>(v.get()) != nullptr)
                {
                    std::cout << *v;
                    ++found;
                } 
            });
    }
    else
    {
        return;
    }

    print_filter_result(oss, found);
}

void filter_by_string(const vector<std::unique_ptr<Vehicle>> &vVehicles, const string &strCriteria, const bool &isModel)
{
    std::ostringstream oss;
    oss << "FILTERED BY ";
    oss << (isModel 
        ? ("MODEL: " + strCriteria)
        : ("BRAND: " + strCriteria));

    int found {};

    if (!isModel)
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
        [strCriteria, &found](const auto &v) {
            string b{v->get_brand()};
            if (toLower(b) == toLower(strCriteria))
            {
                std::cout << *v;
                ++found;
            }
        });
    }
    else
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
        [strCriteria, &found](const auto &v) {
            string b {v->get_model()};
            if (toLower(b) == toLower(strCriteria))
            {
                std::cout << *v;
                ++found;
            }
        });
    }

    print_filter_result(oss, found);
}

void filter_by_year(const vector<std::unique_ptr<Vehicle>> &vVehicles, const int &yearFrom, const int &yearTo)
{
    std::ostringstream oss;
    oss << (yearTo == -1
        ? ("FILTERED BY YEAR: " + std::to_string(yearFrom)) 
        : ("FILTERED BY YEARS: " + std::to_string(yearFrom) + " TO " + std::to_string(yearTo)));
    int found {};

    if (yearTo == -1)
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
        [&yearFrom, &found](const auto &v) { 
            if (v->get_year() == yearFrom)
            {
                std::cout << *v;
                ++found;
            }
        });
    }
    else
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
        [&yearFrom, &yearTo, &found](const auto &v) { 
            if (v->get_year() >= yearFrom && v->get_year() <= yearTo)
            {
                std::cout << *v;
                ++found;
            }
        });
    }

    print_filter_result(oss, found);
}

void filter_by_fuel(const vector<std::unique_ptr<Vehicle>> &vVehicles, const FuelType &fType)
{
    std::ostringstream oss {};
    oss << "FILTERED BY FUEL TYPE " << get_fuel_string(fType);
    int found {};

    std::for_each(vVehicles.begin(), vVehicles.end(),
    [&fType, &found](const auto &v) { 
        if (v->get_fuel_type() == fType)
        {
            std::cout << *v;
            ++found;
        }
    });

    print_filter_result(oss, found);
}

bool save_data(const vector<std::unique_ptr<Vehicle>> &vVehicles)
{
    std::ofstream saveFile {};
    saveFile.open("saved/saved_data.bck");

    if (!saveFile.is_open())
    {
        return false;
    }

    std::ostringstream oss;

    for (const auto &v: vVehicles)
    {
        saveFile << v->save_object() << std::endl;
    }

    saveFile.close();
    return true;
}

FuelType get_fuel_from_string(const string &fuelStr)
{
    if (fuelStr == "gas")
    {
        return FuelType::Gas;
    }
    else if (fuelStr == "diesel")
    {
        return FuelType::Diesel;
    }
    else if (fuelStr == "electric")
    {
        return FuelType::Electric;
    }
    else if (fuelStr == "hybrid")
    {
        return FuelType::Hybrid;
    }

    return FuelType::Unknown;
}

CarType get_car_type_from_string(const string &cType)
{
    string carType = toLower(cType);
    
    if (carType == "sedan")
    {
        return CarType::Sedan;
    }
    else if (carType == "station wagon")
    {
        return CarType::Station_wagon;
    }
    else if (carType == "van")
    {
        return CarType::Van;
    }    
    else if (carType == "sports car")
    {
        return CarType::Sports_car;
    }
    else if (carType == "suv")
    {
        return CarType::SUV;
    }
    else if (carType == "mpv")
    {
        return CarType::MPV;
    }
    else if (carType == "off-road")
    {
        return CarType::Off_road;
    }

    return CarType::Unknown;
}

TruckType get_truck_type_from_string(const string &tType)
{
    if (tType == "two axle")
    {
        return TruckType::Two_axle;
    }
    else if (tType == "three axle")
    {
        return TruckType::Three_axle;
    }
    else if (tType == "four axle")
    {
        return TruckType::Four_axle;
    }
    else if (tType == "five axle")
    {
        return TruckType::Five_axle;
    }

    return TruckType::Unknown;
}

MotorbikeType get_motorbike_type_from_string(const string &mType)
{
    if (mType == "sport_bike")
    {
        return MotorbikeType::Sport_bike;
    }
    else if (mType == "custom")
    {
        return MotorbikeType::Custom;
    }
    else if (mType == "chopper")
    {
        return MotorbikeType::Chopper;
    }
    else if (mType == "naked")
    {
        return MotorbikeType::Naked;
    }
    else if (mType == "scooter")
    {
        return MotorbikeType::Scooter;
    }
    else if (mType == "touring")
    {
        return MotorbikeType::Touring;
    }
    else if (mType == "motocross")
    {
        return MotorbikeType::Motocross;
    }

    return MotorbikeType::Unknown;
}

void load_data(vector<std::unique_ptr<Vehicle>> &v, const bool replaceData)
{
    std::ifstream loadFile {};
    loadFile.open("load/loadable_data.bck");
    vector<std::unique_ptr<Vehicle>> loaded_vehicles;

    if (loadFile)
    {
        string fLine {};
        size_t start {};
        size_t pos {};
        vector<string> words;
        int lineNumber {};

        while (std::getline(loadFile, fLine))
        {
            ++lineNumber;

            while ((pos = fLine.find(',', start)) != string::npos)
            {
                words.emplace_back(fLine.substr(start, pos - start));
                start = pos + 1;
            }

            // Vehicle attributes.
            string brand {};
            string model {};
            int year {};
            double weight {};
            double tankCapacity {};
            FuelType fType {FuelType::Unknown};
            double baseConsumption {};

            try 
            {
                string vehicle_type = words.at(0);
                brand = words.at(1);
                model = words.at(2);
                year = std::stoi(words.at(3));
                weight = std::stod(words.at(4));
                fType = get_fuel_from_string(toLower(words.at(5)));
                tankCapacity = std::stod(words.at(6));
                baseConsumption = std::stod(words.at(7));

                if (vehicle_type == "CAR")
                {
                    // Car attributes.
                    double trunkCapacity {std::stod(words.at(8))};
                    CarType cType {get_car_type_from_string(toLower(words.at(9)))};
                    int numDoors {std::stoi(words.at(10))};

                    Car aCar {brand, model, year, weight, tankCapacity, fType, baseConsumption, trunkCapacity, numDoors, cType};
                    auto sCar = std::make_unique<Car>(aCar);
                    loaded_vehicles.emplace_back(std::move(sCar));
                }
                else if (vehicle_type == "TRUCK")
                {
                    // Truck attributes.
                    TruckType tType = get_truck_type_from_string(toLower(words.at(8)));

                    Truck aTruck {brand, model, year, weight, tankCapacity, fType, baseConsumption, tType};
                    auto sTruck = std::make_unique<Truck>(aTruck);
                    loaded_vehicles.emplace_back(std::move(sTruck));
                }
                else if (vehicle_type == "MOTORBIKE")
                {
                    // Motorbike attributes.
                    MotorbikeType mType = get_motorbike_type_from_string(toLower(words.at(8)));

                    Motorbike aMoto {brand, model, year, weight, tankCapacity, fType, baseConsumption, mType};
                    auto sMoto = std::make_unique<Motorbike>(aMoto);
                    loaded_vehicles.emplace_back(std::move(sMoto));
                }                
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "Loading data: Invalid argument (line " << lineNumber << ")" << std::endl;
            }
            catch (const std::out_of_range &o)
            {
                std::cerr << "Loading data: Out of range (line " << lineNumber << ")" << std::endl;
            }

            words.clear();
            start = 0;
            pos = 0;
        }
    }

    if (!loaded_vehicles.empty())
    {
        if (replaceData)
        {
            // Clears original collection and moves loaded elements.
            v = std::move(loaded_vehicles);
        }
        else
        {
            // Appends loaded elements at the end of the original collection.
            v.insert(v.end(), std::make_move_iterator(loaded_vehicles.begin()), std::make_move_iterator(loaded_vehicles.end()));
        }
    }
}