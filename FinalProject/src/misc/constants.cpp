#include "car.h"
#include "motorbike.h"
#include "truck.h"
#include "dataSet.h"
#include <memory>


void initData(std::shared_ptr<DataSet> data) {
    std::shared_ptr<Car> car1 = std::make_shared<Car>();
    std::shared_ptr<Car> car2 = std::make_shared<Car>();
    std::shared_ptr<Truck> truck1 = std::make_shared<Truck>();
    std::shared_ptr<Motorbike> bike1 = std::make_shared<Motorbike>();
    
    car1->manufacturer = "Ford";
    car1->model = "Focus";
    car1->year = 2025;
    car1->weight = 1500;
    car1->fuelEfficiency = 5.1;
    car1->fuelType = FuelTypes::DIESEL;
    car1->type = Types::CAR;
    car1->doors = 4;
    car1->trunkCapacity = 100;
    data->addVehicle(car1);

    car2->manufacturer = "Honda";
    car2->model = "Civic";
    car2->year = 2023;
    car2->weight = 1400;
    car2->fuelEfficiency = 5.8;
    car2->fuelType = FuelTypes::GASOLINE;
    car2->type = Types::CAR;
    car2->doors = 3;
    car2->trunkCapacity = 120;
    data->addVehicle(car2);

    truck1->manufacturer = "Scania";
    truck1->model = "Unknown";
    truck1->year = 2015;
    truck1->fuelEfficiency = 15.0;
    truck1->fuelType = FuelTypes::DIESEL;
    truck1->weight = 10000;
    truck1->type = Types::TRUCK;
    truck1->axles = 6;
    truck1->payloadCapacity = 18000;
    data->addVehicle(truck1);

    bike1->manufacturer = "Kawasaki";
    bike1->model = "Ninja";
    bike1->year = 2023;
    bike1->weight = 400;
    bike1->fuelEfficiency = 15.8;
    bike1->fuelType = FuelTypes::GASOLINE;
    bike1->type = Types::MOTORBIKE;
    bike1->seats = 2;
    data->addVehicle(bike1);
}
