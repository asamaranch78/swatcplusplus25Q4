#ifndef __CAR_H__
#define __CAR_H__
#include "Vehicle.h"
#include <sstream>
#include <vector>

class Car : public Vehicle {
public:
    int numDoors;
    double trunkCapacity;

    

    Car(string b, string m, int y, Vehicle::fuelType f, double w, int doors, double trunkCap)
        : Vehicle{b, m, y, f, w}, numDoors{doors},trunkCapacity{trunkCap} {}

    std::string info() override;

    double fuelEfficiency()override;

    std::string toCSV() override;

    void fromCSV(const string csv) override;

    ~Car() = default;
};

std::string Car::info(){
    return "Car: " + brand + "model: " + model + ", Year: " + to_string(year) +
           ", Fuel: " + (fuel == Petrol ? "Petrol" : fuel == Diesel ? "Diesel" : "Electric") +
           ", Weight: " + to_string(weigth) + "kg, Doors: " + to_string(numDoors) +
           ", Trunk Capacity: " + to_string(trunkCapacity) + "L";
}

double Car::fuelEfficiency(){
    return 15.0 - (weigth / 1000.0) - (numDoors * 0.5);
}

std::string Car::toCSV(){
    return "Car," + brand + "," + model + "," + to_string(year) +
           "," + (fuel == Petrol ? "Petrol" : fuel == Diesel ? "Diesel" : "Electric") +
           "," + to_string(weigth) + "," + to_string(numDoors) +
           "," + to_string(trunkCapacity);
}

void Car::fromCSV(const string csv) {
    std::stringstream ss(csv);
    std::string line;
    vector <string> vec;
            while(std::getline(ss, line, ',')){
                vec.push_back(line);
            }
    for(int i=1;i<vec.size();i++){
        switch (i){
            case 1:
                brand=vec[i];
                break;
            case 2:
                model=vec[i];
                break;
            case 3:
                year=std::stoi(vec[i]);
                break;
            case 4:
                if(vec[i]=="Petrol"){
                    fuel=Vehicle::Petrol;
                }else if(vec[i]=="Diesel"){
                    fuel=Vehicle::Diesel;
                }else{
                    fuel=Vehicle::Electric;
                }
                break;
            case 5:
                weigth=std::stod(vec[i]);
                break;
            case 6:
                numDoors=std::stoi(vec[i]);
                break;
            case 7:
                trunkCapacity=std::stod(vec[i]);
                break;
        }
    }
}

#endif