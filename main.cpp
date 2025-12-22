#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>


using namespace std;

/* Declaración de funciones Auxiliares*/
void clearScreen();
void mainMenu();
void typeMenu();
void addVehicle(map<int,Vehicle*> &vehicles);
void saveToFile(const map<int,Vehicle*> &vehicles);
void loadFromFile(map<int,Vehicle*> &vehicles);

/* Funciones de entrada de tipos de clases */
Car * inputCar();
Bike* inputBike();
Truck * inputTruck();

using namespace std;

int main(){
    bool flag {true};
    int option{-1};
    map <int,Vehicle*> vehicles;
 
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
                    cout << v.first ;
                    cout << "-" + v.second->info() << endl;
                }
                cout<< vehicles.size() << " vehicles available:\n"<<endl;
                break;

            case 4: // Guardar Datos
                clearScreen();
                saveToFile(vehicles);
                cout << "Data saved.\n"<<endl;
                break;
            
            case 5: // Cargar Datos
                clearScreen();
                loadFromFile(vehicles);
                cout << "Data loaded.\n"<<endl;
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
void addVehicle(map<int,Vehicle*> &vehicles){ 
    int option{-1};
    bool flag{true};

    do {

        typeMenu();

        cin >> option;

        switch(option){
            case 1:
                clearScreen();
                vehicles.insert({vehicles.size() + 1, inputCar()});
                break;
          
            case 2:
                clearScreen();
                vehicles.insert({vehicles.size() + 1, inputBike()});
                break;

            case 3:
                clearScreen();
                vehicles.insert({vehicles.size() + 1, inputTruck()});
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

// Funciones de entrada de datos para cada tipo de vehículo
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

Truck * inputTruck(){
    string brand, model;
    int year, numAxles;
    double weight, maxLoad;
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
    cout << "Enter max load (kg): ";
    cin >> maxLoad;
    cout << "Enter number of axles: ";
    cin >> numAxles;
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

    return new Truck(brand, model, year, fuel, weight, maxLoad, numAxles);
}

void saveToFile(const map<int,Vehicle*> &vehicles) {
    
    std::ofstream file("data.csv"); // crea o sobrescribe el fichero
    
    if (!file) { // comprobar si se abrió correctamente
        std::cerr << "Failed to open File\n";
    }else{
        for(const auto& v : vehicles){
            file <<v.second->toCSV() << "\n";
        }
    }
    
    file.close();
    }



void loadFromFile(map<int,Vehicle*> &vehicles) {
        std::ifstream file("data.csv");
        string line;
    
        if (!file) {
            std::cerr << "Failed to open File\n";
        } else {
                  
    
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                vector <string> aux;
                string tempLine;
                while(std::getline(ss, tempLine, ',')){
                    aux.push_back(tempLine);
                }
                if(aux[0]=="Car"){
                    Car* car = new Car("","",0,Vehicle::Petrol,0.0,0,0.0);
                    car->fromCSV(line);
                    vehicles.insert({vehicles.size() + 1, car});
                } else if(aux[0]=="Bike"){
                    Bike* bike = new Bike("","",0,Vehicle::Petrol,0.0,false,Bike::Hybrid);
                    bike->fromCSV(line);
                    vehicles.insert({vehicles.size() + 1, bike});
                } else if(aux[0]=="Truck"){
                    Truck* truck = new Truck("","",0,Vehicle::Petrol,0.0,0.0,0);
                    truck->fromCSV(line);
                    vehicles.insert({vehicles.size() + 1, truck});
                }
            }
        }
    
        file.close();
    }