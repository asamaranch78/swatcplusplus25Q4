#ifndef __BIKE_H__
#define __BIKE_H__
#include "Vehicle.h"

class Bike : public Vehicle {
    public:
        bool hasCarrier;
        enum bikeType { Mountain, Road, Hybrid };
        bikeType type;

        Bike(string b, string m, int y, Vehicle::fuelType f, double w, bool carrier, bikeType t)
            : Vehicle{b, m, y, f, w}, hasCarrier{carrier}, type {t} {}

        std::string info() override;

        double fuelEfficiency() override;

        string toCSV() override;

        void fromCSV(const string csv) override ;

        ~Bike() = default;
}; 

std::string Bike::info(){
    return "Bike: " + brand + " " + model + ", Year: " + to_string(year) +
           ", Fuel: " + (fuel == Petrol ? "Petrol" : fuel == Diesel ? "Diesel" : "Electric") +
           ", Weight: " + to_string(weigth) + "kg, Carrier: " + (hasCarrier ? "Yes" : "No") + (type == Mountain ? ", Type: Mountain" : type == Road ? ", Type: Road" : ", Type: Hybrid");
}

double Bike::fuelEfficiency(){
    return 50.0 - (weigth / 100.0) + (hasCarrier ? -2.0 : 0.0);
}


std::string Bike::toCSV(){
    return "Bike," + brand + "," + model + "," + to_string(year) +
           "," + (fuel == Petrol ? "Petrol" : fuel == Diesel ? "Diesel" : "Electric") +
           "," + to_string(weigth) + "," + (hasCarrier ? "1" : "0") +
           "," + (type == Mountain ? "Mountain" : type == Road ? "Road" : "Hybrid");
}

void Bike::fromCSV(const string csv) {
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
                hasCarrier=(vec[i]=="1");
                break;
            case 7:
                if(vec[i]=="Mountain"){
                    type=Bike::Mountain;
                }else if(vec[i]=="Road"){
                    type=Bike::Road;
                }else{
                    type=Bike::Hybrid;
                }
                break;
        }
    }                      
}
#endif