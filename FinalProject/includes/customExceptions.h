#ifndef __CUSTOM_EXCEPTION_H__
#define __CUSTOM_EXCEPTION_H__

#include <stdexcept>

class badVehicleType: public std::exception {
public:
    ~badVehicleType() = default;
    virtual const char * what() const noexcept {
        return "This vehicle type can't be handled";
    }
};

class badFuelType: public std::exception {
public:
    ~badFuelType() = default;
    virtual const char * what() const noexcept {
        return "This fuel type can't be handled";
    }
};

class badFilterType: public std::exception {
public:
    ~badFilterType() = default;
    virtual const char * what() const noexcept {
        return "This filter type can't be handled";
    }
};

class kmIsZero: public std::exception {
public:
    ~kmIsZero() = default;
    virtual const char * what() const noexcept {
        return "Kilometers can't be zero";
    }
};

class hoursIsZero: public std::exception {
public:
    ~hoursIsZero() = default;
    virtual const char * what() const noexcept {
        return "Hours can't be zero";
    }
};

class tooManyFields: public std::exception {
public:
    ~tooManyFields() = default;
    virtual const char * what() const noexcept {
        return "System can only handle 10 field per form";
    }
};

class yamlIsNotList: public std::exception {
public:
    ~yamlIsNotList() = default;
    virtual const char * what() const noexcept {
        return "Provided yaml is not a list";
    }
};

class badYaml: public std::exception {
public:
    std::string originalMsg;
    badYaml(std::string original) {
        originalMsg = original;
    }
    ~badYaml() = default;
    virtual const char * what() const noexcept {
        return "Error occured during yaml processing";
    }
};

#endif
