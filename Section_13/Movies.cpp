#include <iostream>
#include "Movies.h"

/*
bool Movies::movie_exists(std::string name) {

    bool exists {false};

    for (auto mv: movies) {
        if (mv.get_name() == name) {
            exists = true;
            break;
        }
    }

    return exists;
}
*/

int Movies::get_movie_index(std::string name) {

    int idx {-1};

    for (size_t i {0}; i < movies.size(); ++i) {
        if (movies.at(i).get_name() == name) {
            idx = i;
            break;
        }
    }

    return idx;
}

bool Movies::add_movie(std::string name, std::string peggy, int watched) {

    int idx {-1};

    idx = get_movie_index(name);

    if (idx == -1) {
        this->movies.push_back(Movie{ name, peggy, watched });
    }

    return (idx == -1);
}

bool Movies::increment_watched(std::string name) {

    int idx {-1};

    idx = get_movie_index(name);

    if (idx > -1) {
        movies.at(idx).increment_watched();
    }

    return (idx > -1);
}

void Movies::display_all_movies() const {

    std::cout << "=========================" << std::endl;

    for (auto m: movies) {
        m.display();
    }
    
    std::cout << "=========================" << std::endl;
}