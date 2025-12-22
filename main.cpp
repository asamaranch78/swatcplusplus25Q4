#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include <iostream>
#include <vector>


using namespace std;

void clearScreen();
void mainMenu();
void typeMenu();
void addVehicle(vector<Vehicle*> &vehicles);
Car * inputCar();
Bike* inputBike();

using namespace std;

int main(){
    bool flag {true};
    int option{-1};
    vector <Vehicle*> vehicles;
 
    do
    {
        mainMenu();
        cin >> option;
    
        switch(option){

            case 1: // Añadir Vehículo
                clearScreen();
                addVehicle(vehicles);
                break;

            case 2: // Listar Vehículos
                clearScreen();
                for(const auto& v : vehicles){
                    cout << v->info() << endl;
                }
                cout<< vehicles.size() << " vehicles available:\n"<<endl;
                break;
            case 0: // Salir
                clearScreen();
                flag=false;
                break;

            default:
                clearScreen();
                break;
        } 

    } while (flag==true);
    
    return 0;
    
}

// Borra toda la pantalla y coloca el cursor al principio

void clearScreen() { 
    
    std::cout << "\x1b[2J\x1b[H" << std::flush;
}

// Añade un vehículo según el tipo seleccionado
void addVehicle(vector<Vehicle*> &vehicles){ 
    int option{-1};
    bool flag{true};

    do {

        typeMenu();

        cin >> option;

        switch(option){
            case 1:
                clearScreen();
                vehicles.push_back(inputCar());
                break;
          
            case 2:
                clearScreen();
                vehicles.push_back(inputBike());
                break;

            case 0:
                clearScreen();
                flag=false;
                break;
    
            default:
                
                break;
        } 

    } while (flag==true);
   
    
}

// Muestra el menú principal
void mainMenu(){ 
    cout << "**********************"<<endl;
    cout << "* VEHICLE MANAGEMENT *"<<endl;
    cout << "**********************\n"<<endl;
    cout << "\t 1 - Add Vehicle"<<endl;
    cout << "\t 2 - List Vehicles"<<endl;
    cout << "\t 3 - Sort Vehicles"<<endl;
    cout << "\t 4 - Save Data"<<endl;
    cout << "\t 5 - Load Data"<<endl;
    cout << "\t 0 - Salir\n"<<endl;
    cout << "Selecciona opcion:";
}


// Muestra el menú de tipos de vehículo
void typeMenu(){ 
    cout << "**********************"<<endl;
    cout << "*     TYPE TO ADD    *"<<endl;
    cout << "**********************\n"<<endl;
    cout << "\t 1 - Car"<<endl;
    cout << "\t 2 - Bike"<<endl;
    cout << "\t 3 - Truck"<<endl;
    cout << "\t 0 - Back\n"<<endl;
    cout << "Selecciona opcion:";
}

Car * inputCar(){
    string brand, model;
    int year, numDoors;
    double weight;
    double trunkCapacity;
    int fuelOption;
    Vehicle::fuelType fuel;

    cout << "Enter brand: ";
    cin >> brand;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter weight (kg): ";
    cin >> weight;
    cout << "Enter trunk capacity (L): ";
    cin >> trunkCapacity;
    cout << "Enter number of doors: ";
    cin >> numDoors;
    cout << "Select fuel type (0 - Petrol, 1 - Diesel, 2 - Electric): ";
    cin >> fuelOption;

    switch(fuelOption){
        case 0:
            fuel = Vehicle::Petrol;
            break;
        case 1:
            fuel = Vehicle::Diesel;
            break;
        case 2:
            fuel = Vehicle::Electric;
            break;
        default:
            fuel = Vehicle::Petrol; // Default to Petrol
            break;
    }

    return new Car(brand, model, year, fuel, weight, numDoors, trunkCapacity);

}

Bike* inputBike(){
    string brand, model;
    int year;
    double weight;
    bool hasCarrier;
    int typeOption;
    Bike::bikeType type;
    int fuelOption;
    Vehicle::fuelType fuel;

    cout << "Enter brand: ";
    cin >> brand;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter weight (kg): ";
    cin >> weight;
    cout << "Does it have a carrier? (1 - Yes, 0 - No): ";
    cin >> hasCarrier;
    cout << "Select bike type (0 - Mountain, 1 - Road, 2 - Hybrid): ";
    cin >> typeOption;

    switch(typeOption){
        case 0:
            type = Bike::Mountain;
            break;
        case 1:
            type = Bike::Road;
            break;
        case 2:
            type = Bike::Hybrid;
            break;
        default:
            type = Bike::Hybrid; // Default to Hybrid
            break;
    }

    cout << "Select fuel type (0 - Petrol, 1 - Diesel, 2 - Electric): ";
    cin >> fuelOption;

    switch(fuelOption){
        case 0:
            fuel = Vehicle::Petrol;
            break;
        case 1:
            fuel = Vehicle::Diesel;
            break;
        case 2:
            fuel = Vehicle::Electric;
            break;
        default:
            fuel = Vehicle::Petrol; // Default to Petrol
            break;
    }

    return new Bike(brand, model, year, fuel, weight, hasCarrier, type);
}