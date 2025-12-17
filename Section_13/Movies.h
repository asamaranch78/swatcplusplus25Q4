#pragma once

#include <vector>
#include "Movie.h"

class Movies {

    private:
    std::vector<Movie> movies;

    // Internal tool to looking for a movie in collection.
    // returns -1 if it doesn't exists, a positive number if it does.
    int get_movie_index(std::string name);

    public:

    bool add_movie(std::string name, std::string peggy, int watched = 0);
    bool increment_watched(std::string name);

    void display_all_movies() const;

};