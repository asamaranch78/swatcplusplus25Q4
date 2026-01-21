#ifndef __ENUMS_H__
#define __ENUMS_H__

#include <cstdint>
#include <memory>
#include <vector>
#include <string>

const std::string dieselString {"Diesel"};
const std::string electricString {"Electric"};
const std::string gasolineString {"Gasoline"};
const std::string carString {"Car"};
const std::string elecCarString {"Electric car"};
const std::string motorString {"Motorbike"};
const std::string truckString {"Truck"};

enum FuelTypes{
    DIESEL,
    GASOLINE,
    ELECTRIC};
enum Types {
    CAR,
    TRUCK,
    ELECTRIC_CAR,
    MOTORBIKE};

enum FilterTypes{
    YEAR,
    MANUFACTURER,
    TYPE};

const auto FUEL_TYPE_TEXTS = std::make_shared<std::vector<std::string>>(
        std::initializer_list<std::string>{
            "DIESEL",
            "GASOLINE"}
    );

const auto TYPES_TEXTS = std::make_shared<std::vector<std::string>>(
        std::initializer_list<std::string>{
            "CAR",
            "TURCK",
            "ELECTRIC_CAR",
            "MOTOR_BIKE"}
    );

const auto FILTER_TYPE_TEXTS = std::make_shared<std::vector<std::string>>(
        std::initializer_list<std::string>{
            "YEAR",
            "MANUFACTURER",
            "TYPE"}
    );

enum FuelTypes calculateFuelType(int8_t index);
enum Types calculateType(int8_t index);
enum FilterTypes calculateFilterType(int8_t index);
enum FuelTypes decodeFuelType(std::string type);
enum Types decodeType(std::string type);

#endif
