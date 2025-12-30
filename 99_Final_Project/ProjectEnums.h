#pragma once

enum class VehicleType
{
    Car,
    Truck,
    Motorbike,
    All
};

enum class CarType
{
    Sedan,           
    Station_wagon,
    MPV,             // Multi-purpose vehicle
    Van,
    Sports_car,
    SUV,             // Sports Utility Vehicle
    Off_road
};

enum class MotorbikeType
{
    Sport_bike,
    Custom,
    Chopper,
    Naked,
    Scooter,
    Touring,
    Motocross
};

enum class TruckType
{
    Two_axle,
    Three_axle,
    Four_axle,
    Five_axle
};

enum class FuelType
{
    Gas,            // Gasoline
    Diesel,
    Electric,
    Hybrid,
    None            // For bikes...
};