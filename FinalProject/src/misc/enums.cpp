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
            throw;
    
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
            throw;
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
            throw;
    }
}
