#ifndef __ENUMS_H__
#define __ENUMS_H__

#include <cstdint>
#include <memory>
#include <vector>
#include <string>

enum FuelTypes{
    DIESEL,
    GASOLINE,
    ELECTRIC};
enum Types {
    CAR,
    TRUCK,
    ELECTRIC_CAR,
    MOTORBIKE};

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

enum FuelTypes calculateFuelType(int8_t index);
enum Types calculateType(int8_t index);

#endif
