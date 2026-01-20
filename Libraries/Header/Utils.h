#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include <string>
#include <sstream>

// VARIABLES
const int vehicle_parameter_width {14};
const int vehicle_num_parameter {10};
const int menu_width {vehicle_parameter_width*vehicle_num_parameter-vehicle_parameter_width/2};

//ENUMS
enum Actions : char {Add = 'A', List = 'L', Sort = 'S', Filter = 'F', Compute = 'C', Quit = 'Q', Unknown = 'U'};
std::istream &operator>>(std::istream &is, Actions &action);
enum VehicleType {Cars = 1, Bikes, Trucks, Unknown2};
std::istream &operator>>(std::istream &is, VehicleType &type);
std::string VehicleType_to_string(const VehicleType &type);
VehicleType string_to_VehicleType(const std::string &s);
enum BikeType {Road = 1, Mountain, Standard, Mountain_Electric, Standard_Electric, Unknown3};
std::istream &operator>>(std::istream &is, BikeType &type);
std::string BikeType_to_string(const BikeType &type);
BikeType string_to_BikeType(const std::string &s);
enum FuelType {Electric = 1, Hybrid, Gasoline, Diesel, Human, Unknown4};
std::istream &operator>>(std::istream &is, FuelType &type);
std::string FuelType_to_string(const FuelType &type);
FuelType string_to_FuelType(const std::string &s);
enum YesNo : char {Yes = 'y', No = 'n', Unknown5};
std::istream &operator>>(std::istream &is, YesNo &type);
std::string YesNo_to_string(const YesNo &type);
YesNo string_to_YesNo(const std::string &s);
enum Attribute {Unknown6 = 0, Efficiency, VehType, Id, Brand, Model, Year};
std::istream &operator>>(std::istream &is, Attribute &type);
std::string Attribute_to_string(const Attribute &type);
enum ActionsFilter : char {AddFilter = 'a', RemoveFilter = 'r', ClearFilters = 'c', Unknown7 = 'u'};
std::istream &operator>>(std::istream &is, ActionsFilter &action);

//STRUCTS 
struct MyFilter {
    int id;
    Attribute atr;
    std::string min_range;
    std::string max_range;
    bool active;
};

//FUNCTIONS
void clearScreen();
std::stringstream getUserInput(const std::string& user_output);
void checkStringValidity(const std::string& s);
void checkIntInRange(const int& value, const int& min, const int&max);

#endif //_UTILS_H_