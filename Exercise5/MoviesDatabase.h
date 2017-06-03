#ifndef CFROMJAVA_MOVIESDATABASE_H
#define CFROMJAVA_MOVIESDATABASE_H

#include "Movie.h"

typedef struct moviesDatabase MoviesDatabase;
struct moviesDatabase {
    Movie* moviesList[2000];               // A maximum of 2000 movies can be loaded
    int counter;
};

MoviesDatabase* new_MoviesDatabase();
void freeMoviesDatabase(MoviesDatabase* moviesDatabase);

void addMovie(MoviesDatabase* moviesDatabase, Movie* movie);
void removeMovie(MoviesDatabase* moviesDatabase, int position);
void showMoviesList(MoviesDatabase* moviesDatabase);

#endif //CFROMJAVA_MOVIESDATABASE_H
