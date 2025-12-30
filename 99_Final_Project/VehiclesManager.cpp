#include <cmath>
#include <iterator>

#include "VehiclesManager.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

std::string toLower(const std::string &s)
{
    std::string b {s};
    std::transform(b.begin(), b.end(), b.begin(), [] (unsigned char c) {
        return std::tolower(c);
    });

    return b;
}

std::string get_fuel_string(const FuelType &fType)
{
    switch (fType)
    {
        case (FuelType::Diesel): return "Diesel"; break;
        case (FuelType::Gas): return "Gas"; break;
        case (FuelType::Electric): return "Electric"; break;
        case (FuelType::Hybrid): return "Hybrid"; break;
        case (FuelType::None): return "-"; break;
        default: return "Unknown"; break;
    }
}

std::string get_vehicle_string(const VehicleType &vType)
{
    switch (vType)
    {
        case (VehicleType::Car): return "CAR"; break;
        case (VehicleType::Truck): return "TRUCK"; break;
        case (VehicleType::Motorbike): return "MOTORBIKE"; break;
        default: return "UNKNOWN"; break;
    }    
}

void print_graphic(const VehicleType &vehicle) 
{
    std::string fGraphic {"graphics/"};
    std::string vFile {};

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
    std::string gLine {};

    while (std::getline(graphic_file, gLine))
    {
        std::cout << gLine << std::endl;
    }

    graphic_file.close();
}

void print_collection(const std::vector<std::unique_ptr<Vehicle>> &vVehicles)
{
    int i {1};
    int cPage {1};

    system("clear");

    for (const auto &v: vVehicles)
    {
        cout << *v;
        
        if (i % 2 == 0)
        {
            cout << " PAGE " << cPage << "/" << static_cast<int>(std::ceil(vVehicles.size() / 2.0)) << endl;
            cout << endl << "Press enter to continue." << endl;
            cin.get();
            
            i = 0;
            ++cPage;
            system("clear");
        }

        ++i;
    }
}

void sort_collection(std::vector<std::unique_ptr<Vehicle>> &vVehicles, const int &sort_option)
{
    std::string sortedBy {};

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

        // By fuel efficency (ascending).
        case 4:
            std::stable_sort(vVehicles.begin(), vVehicles.end(), [] (const auto &a, const auto &b) { return a->fuelEfficiency() < b->fuelEfficiency(); });
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

void filter_by_vehicle(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const VehicleType &vType)
{
    std::ostringstream oss;
    oss << "FILTERED BY VEHICLE TYPE: " << get_vehicle_string(vType);

    if (vType == VehicleType::Car)
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
            [](const auto &v) { 
                if (dynamic_cast<Car *>(v.get()) != nullptr)
                {
                    std::cout << *v;
                } 
            });
    }
    else if (vType == VehicleType::Truck)
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
            [](const auto &v) { 
                if (dynamic_cast<Truck *>(v.get()) != nullptr)
                {
                    std::cout << *v;
                } 
            });
    }
    else if (vType == VehicleType::Motorbike)
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
            [](const auto &v) { 
                if (dynamic_cast<Motorbike *>(v.get()) != nullptr)
                {
                    std::cout << *v;
                } 
            });
    }
    else
    {
        return;
    }

    cout << oss.str() << endl;

    cout << endl << "Press enter to continue." << endl;
    cin.get();
}

void filter_by_string(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const std::string &strCriteria, const bool &isModel)
{
    std::ostringstream oss;
    oss << "FILTERED BY ";
    oss << (isModel 
        ? ("MODEL: " + strCriteria)
        : ("BRAND: " + strCriteria));

    if (!isModel)
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
        [strCriteria](const auto &v) {
            std::string b{v->get_brand()};
            if (toLower(b) == toLower(strCriteria))
            {
                std::cout << *v;
            }
        });
    }
    else
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
        [strCriteria](const auto &v) {
            std::string b {v->get_model()};
            if (toLower(b) == toLower(strCriteria))
            {
                std::cout << *v;
            }
        });
    }

    cout << oss.str() << endl;

    cout << endl << "Press enter to continue." << endl;
    cin.get();    
}

void filter_by_year(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const int &yearFrom, const int &yearTo)
{
    std::ostringstream oss;
    oss << (yearTo == -1
        ? ("FILTERED BY YEAR: " + std::to_string(yearFrom)) 
        : ("FILTERED BY YEARS: " + std::to_string(yearFrom) + " TO " + std::to_string(yearTo)));

    if (yearTo == -1)
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
        [yearFrom](const auto &v) { 
            if (v->get_year() == yearFrom)
            {
                std::cout << *v;
            }
        });
    }
    else
    {
        std::for_each(vVehicles.begin(), vVehicles.end(),
        [yearFrom, yearTo](const auto &v) { 
            if (v->get_year() >= yearFrom && v->get_year() <= yearTo)
            {
                std::cout << *v;
            }
        });
    }

    cout << oss.str() << endl;

    cout << endl << "Press enter to continue." << endl;
    cin.get();    
}

void filter_by_fuel(const std::vector<std::unique_ptr<Vehicle>> &vVehicles, const FuelType &fType)
{
    std::ostringstream oss {};
    oss << "FILTERED BY FUEL TYPE " << get_fuel_string(fType);

    std::for_each(vVehicles.begin(), vVehicles.end(),
    [fType](const auto &v) { 
        if (v->get_fuel_type() == fType)
        {
            std::cout << *v;
        }
    });

    cout << oss.str() << endl;

    cout << endl << "Press enter to continue." << endl;
    cin.get();    
}
