#pragma once

#include <string>

class Movie {

    private:
    std::string name;
    std::string peggy;
    int watched;

    public:
    Movie(std::string name_val, std::string peggy_val, int watched_val = 0)
    : name{name_val}, peggy{peggy_val}, watched{watched_val} {
    };

    ~Movie() {};

    // Copy constructor.
    Movie(const Movie &source)
    : Movie { source.name, source.peggy, source.watched } {}

    inline std::string get_name() const { return this->name; }
    inline void increment_watched() { watched++; }

    void display() const;
};