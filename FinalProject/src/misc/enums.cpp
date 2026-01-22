#include "customExceptions.h"
#include <cstdint>

#include <enums.h>

enum FuelTypes calculateFuelType(int8_t index) {
    switch (index) {
        case 0:
            return FuelTypes::DIESEL;
        case 1:
            return FuelTypes::GASOLINE;
        case 2:
            return FuelTypes::ELECTRIC;
        default:
            throw badFuelType {};
    
    }
}

enum Types calculateType(int8_t index) {
    switch(index) {
        case 0:
            return Types::CAR;
        case 1:
            return Types::TRUCK;
        case 2:
            return Types::ELECTRIC_CAR;
        case 3:
            return Types::MOTORBIKE;
        default:
            throw badVehicleType {};
    }
}

enum FilterTypes calculateFilterType(int8_t index) {
    switch(index) {
        case 0:
            return FilterTypes::YEAR;
        case 1:
            return FilterTypes::MANUFACTURER;
        case 2:
            return FilterTypes::TYPE;
        default:
            throw badFilterType {};
    }
}

enum FuelTypes decodeFuelType(std::string type) {
    if (dieselString == type) { return FuelTypes::DIESEL;}
    if (gasolineString == type) { return FuelTypes::GASOLINE;}
    if (electricString == type) { return FuelTypes::ELECTRIC;}
    throw badFuelType {};
}

enum Types decodeType(std::string type) {
    if (carString == type) { return Types::CAR;}
    if (elecCarString == type) { return Types::ELECTRIC_CAR;}
    if (motorString == type) { return Types::MOTORBIKE;}
    if (truckString == type) { return Types::TRUCK; }
    throw badVehicleType {};
}
