#include "MoviesDatabase.h"
#include <malloc.h>
#include <stdio.h>

MoviesDatabase* new_MoviesDatabase() {

    MoviesDatabase* moviesDatabase = malloc(sizeof(MoviesDatabase));

    moviesDatabase->counter = 0;

    return moviesDatabase;
}

void addMovie(MoviesDatabase* moviesDatabase, Movie* movie) {
    if (moviesDatabase->counter < sizeof(moviesDatabase->moviesList) / sizeof(moviesDatabase->moviesList[0])) {
        moviesDatabase->moviesList[moviesDatabase->counter] = movie;
        moviesDatabase->counter++;
    } else printf("Max capacity reached");
}

void removeMovie(MoviesDatabase* moviesDatabase, int position) {
    for (int i = position; i < moviesDatabase->counter; i++) {
        moviesDatabase->moviesList[i] = moviesDatabase->moviesList[i + 1];
    }
    moviesDatabase->counter--;
}

void showMoviesList(MoviesDatabase* moviesDatabase) {
    for (int i = 0; i < moviesDatabase->counter; i++) {
        printf("\n#%i", i);
        printf("\nName: %s", moviesDatabase->moviesList[i]->name);
        printf("\nPrice: %.2f\n", moviesDatabase->moviesList[i]->price);
    }
}

void freeMoviesDatabase(MoviesDatabase* moviesDatabase) {
    free(moviesDatabase);
}
