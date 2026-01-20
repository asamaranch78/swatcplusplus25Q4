#include <iostream>
#include <string>
#include <sstream>
#include "Utils.h"
#include "Exceptions.h"

//Function Definitions
std::istream &operator>>(std::istream &is, Actions &action) {
    std::underlying_type_t<Actions> user_input;
    is >> user_input;
    user_input= std::toupper(user_input);
    switch (user_input) {
        case Add:
        case List:
        case Sort:
        case Filter:
        case Compute:
        case Quit:
            action = Actions(user_input);
            break;
        default:
            action = Unknown;
            throw IncorrectUserInputException();
    }
    return is;
}
std::istream &operator>>(std::istream &is, VehicleType &type) {
    std::underlying_type_t<VehicleType> user_input;
    is >> user_input;
    switch (user_input) {
        case Cars:
        case Bikes:
        case Trucks:
            type = VehicleType(user_input);
            break;
        default:
            type = Unknown2;
            throw IncorrectUserInputException();
    }
    return is;
}
std::istream &operator>>(std::istream &is, BikeType &type) {
    static std::underlying_type_t<BikeType> user_input;
    is >> user_input;
    switch (user_input) {
        case Road:
        case Mountain:
        case Standard:
        case Mountain_Electric:
        case Standard_Electric:
            type = BikeType(user_input);
            break;
        default:
            type = Unknown3;
            throw IncorrectUserInputException();
    }
    return is;
}
std::istream &operator>>(std::istream &is, FuelType &type) {
    static std::underlying_type_t<FuelType> user_input;
    is >> user_input;
    switch (user_input) {
        case Electric:       
        case Hybrid:
        case Gasoline:
        case Diesel:
        case Human:
            type = FuelType(user_input);
            break;
        default:                   
            std::cout << "User input is not a valid option" << std::endl;
            type = Unknown4;
            throw IncorrectUserInputException();
    }
    return is;
}
std::istream &operator>>(std::istream &is, YesNo &type) {
    static std::underlying_type_t<YesNo> user_input;
    is >> user_input;
    user_input= std::tolower(user_input);
    switch (user_input) {
        case Yes:
        case No:
            type = YesNo(user_input);
            break;
        default:                   
            type = No;
            throw IncorrectUserInputException();
    }
    return is;
}
std::istream &operator>>(std::istream &is, Attribute &type){
    static std::underlying_type_t<Attribute> user_input;
    is >> user_input;
    switch (user_input) {
        case Efficiency:      
        case VehType:
        case Id:
        case Brand:
        case Model:
        case Year:
            type = Attribute(user_input);
            break;
        default:                   
            //std::cout << "User input is not a valid option" << std::endl;
            type = Unknown6;
            //throw IncorrectUserInputException();
    }
    return is;
}
std::istream &operator>>(std::istream &is, ActionsFilter &action) {
    std::underlying_type_t<ActionsFilter> user_input;
    is >> user_input;
    user_input= std::tolower(user_input);
    switch (user_input) {
        case AddFilter:
        case RemoveFilter:
        case ClearFilters:
            action = ActionsFilter(user_input);
            break;
        default:
            action = Unknown7;
            throw IncorrectUserInputException();
    }
    return is;
}

std::string VehicleType_to_string(const VehicleType &type) {
    std::string result;
    switch (type) {
        case Cars:
            result = "Car";
            break;
        case Bikes:
            result = "Bike";
            break;
        case Trucks:
            result = "Truck";
            break;
        default:
            result = "Unknown";
    }
    return result;
}
std::string BikeType_to_string(const BikeType &type) {
    std::string result;
    switch (type) {
        case Road:
            result = "Road";
            break;
        case Mountain:
            result = "Mountain";
            break;
        case Standard:
            result = "Standard";
            break;
        case Mountain_Electric:
            result = "Mount-Elec";
            break;
        case Standard_Electric:
            result = "Stand-Elec";
            break;
        default:
            result = "Unknown";
    }
    return result;
}
std::string FuelType_to_string(const FuelType &type) {
    std::string result;
    switch (type) {
        case Electric:
            result = "Electric";
            break;      
        case Hybrid:
            result = "Hybrid";
            break;
        case Gasoline:
            result = "Gasoline";
            break;
        case Diesel:
            result = "Diesel";
            break;
        case Human:
            result = "Human";
            break;
        default:
            result = "Unknown";
    }
    return result;
}
std::string YesNo_to_string(const YesNo &type) {
    std::string result;
    switch (type) {
        case Yes:
            result = "Yes";
            break;
        case No:
            result = "No";
            break;
        default:
            result = "Unknown";
    }
    return result;
}
std::string Attribute_to_string(const Attribute &type){
    std::string result;
    switch (type) {
        case Efficiency:
            result = "Efficiency";
            break;
        case VehType:
            result = "VehType";
            break;
        case Id:
            result = "Id";
            break;
        case Brand:
            result = "Brand";
            break;
        case Model:
            result = "Model";
            break;
        case Year:
            result = "Year";
            break;
        default:
            result = "Unknown";
    }
    return result;
}
VehicleType string_to_VehicleType(const std::string &s) {
    VehicleType result;
    if(s=="Car")
        result = Cars;
    else if(s=="Bike")
        result = Bikes;
    else if(s=="Truck")
        result = Trucks;
    else
        result = Unknown2;
    return result;
}
BikeType string_to_BikeType(const std::string &s) {
    BikeType result;
    if(s=="Road")
        result = Road;
    else if(s=="Mountain")
        result = Mountain;
    else if(s=="Standard")
        result = Standard;
    else if(s=="Mount-Elec")
        result = Mountain_Electric;
    else if(s=="Stand-Elec")
        result = Standard_Electric;
    else
        result = Unknown3;
    return result;
}
FuelType string_to_FuelType(const std::string &s) {
    FuelType result;
    if(s=="Electric")
        result = Electric;
    else if(s=="Hybrid")
        result = Hybrid;
    else if(s=="Gasoline")
        result = Gasoline;
    else if(s=="Diesel")
        result = Diesel;
    else if(s=="Human")
        result = Human;
    else
        result = Unknown4;
    return result;
}
YesNo string_to_YesNo(const std::string &s) {
    YesNo result;
    if(s=="Yes")
        result = Yes;
    else if(s=="No")
        result = No;
    else
        result = Unknown5;
    return result;
}

void clearScreen() {
    std::cout << "\033[2J\033[H";  // Clear screen + move cursor to home
}

std::stringstream getUserInput(const std::string &user_output){
    std::string line {};
    std::cout << user_output;
    std::getline(std::cin, line);
    std::stringstream full_line {line};
    return full_line;
}

void checkStringValidity(const std::string &s){
    if(s.empty())
        throw IncorrectStringException();
    for(auto c: s){
        if(!std::isalnum(c)){
            std::cout << s;
            throw IncorrectStringException();
        }
    }
}

void checkIntInRange(const int& value, const int& min, const int&max){
    if(value < min || value > max){
        std::cout << "Value: " << value << " (Min,Max) (" << min << "," << max << ")";
        throw IncorrectIntegerException();
    }
}