#ifndef __TRUCK_H__
#define __TRUCK_H__
#include "Vehicle.h"

class Truck : public Vehicle {
public:
    double maxLoad;
    int numAxles;
    Truck(string b, string m, int y, Vehicle::fuelType f, double w, double load, int axles)
        : Vehicle{b, m, y, f, w}, maxLoad{load}, numAxles{axles} {}

    std::string info() override;

    double fuelEfficiency() override;

    string toCSV() override;

    void fromCSV(const string csv) override;
    ~Truck() = default;
};

std::string Truck::info(){
    return "Truck: " + brand + " " + model + ", Year: " + to_string(year) +
           ", Fuel: " + (fuel == Petrol ? "Petrol" : fuel == Diesel ? "Diesel" : "Electric") +
           ", Weight: " + to_string(weigth) + "kg, Max Load: " + to_string(maxLoad) +
           "kg, Axles: " + to_string(numAxles);
}

double Truck::fuelEfficiency(){
    return 8.0 - (weigth / 2000.0) - (maxLoad / 1000.0);
}

std::string Truck::toCSV() {
    return "Truck," + brand + "," + model + "," + to_string(year) +
           "," + (fuel == Petrol ? "Petrol" : fuel == Diesel ? "Diesel" : "Electric") +
           "," + to_string(weigth) + "," + to_string(maxLoad) +
           "," + to_string(numAxles);
}

void Truck::fromCSV(const string csv) {
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
                year=std::stoi(vec[i]);;
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
                maxLoad=std::stod(vec[i]);
                break;
            case 7:
                numAxles=std::stoi(vec[i]);;
                break;
        }
    }
}

#endif