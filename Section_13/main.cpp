#include <iostream>
#include <vector>

#include "Movies.h"

int main() {

    Movies movies;

    movies.add_movie("Terryfier", "18+");
    movies.add_movie("Pesadilla antes de Navidad", "7", 3);
    movies.add_movie("Lost in translation", "12", 5);

    movies.display_all_movies();

    return 0;
}