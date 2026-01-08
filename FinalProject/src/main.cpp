#include "menucli.h"
#include "car.h"
#include "vehicle.h"

int main (void);

int main (void) {
    MenuCLI menu;

    /*while (true) {
        if (!menu.askForSelection()) {return 0;} 
        menu.handleSelection();
    }*/

    Car car1, car2;

    car1.manufacturer = "Ford";
    car1.model = "Focus";
    car1.year = 2025;
    car1.weight = 1500;
    car1.fuelEfficiency = 5.1;
    car1.fuelType = FuelTypes::DIESEL;
    car1.type = Types::CAR;
    car1.doors = 4;
    car1.trunkCapacity = 100;

    car2.askUserData();

    printListHeader();
    car1.info();
    car2.info();


}
