/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"
#include "Movie.h"

using namespace std;

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) {

    if (pointer_to_movie(name) != nullptr) { return false; }
    movies.push_back(Movie(name, rating, watched));
    return true;
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) {
    // you implement this method
    Movie *ptrMovie = pointer_to_movie(name);
    if (ptrMovie == nullptr) { return false; }
    ptrMovie->increment_watched();
    return true;
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const {
    for (size_t i = 0; i < movies.size(); i++) {
        movies.at(i).display();
    }
}


Movie* Movies::pointer_to_movie(std::string name) {
    Movie* result {nullptr};

    for (size_t i = 0; i < movies.size(); i++) {
        if (movies.at(i).get_name() == name) { return &movies.at(i);}
    }

    return result;
}
