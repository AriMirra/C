#include "MoviesDatabase.h"
#include <malloc.h>
#include <stdio.h>

/*
 * Description: Contains the functions related to the MoviesDatabase struct
 */

/*
 * Description: Creates a MoviesDatabase
 * Returns: The MoviesDatabase created
 */
MoviesDatabase* new_MoviesDatabase() {

    MoviesDatabase* moviesDatabase = malloc(sizeof(MoviesDatabase));

    moviesDatabase->counter = 0;

    return moviesDatabase;
}

/*
 * Description: Adds a movie to the database
 * Returns: Void
 */
void addMovie(MoviesDatabase* moviesDatabase, Movie* movie) {
    if (moviesDatabase->counter < sizeof(moviesDatabase->moviesList) / sizeof(moviesDatabase->moviesList[0])) {
        moviesDatabase->moviesList[moviesDatabase->counter] = movie;
        moviesDatabase->counter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Removes a movie from the database
 * Returns: Void
 */
void removeMovie(MoviesDatabase* moviesDatabase, int position) {
    for (int i = position; i < moviesDatabase->counter; i++) {
        moviesDatabase->moviesList[i] = moviesDatabase->moviesList[i + 1];
    }
    moviesDatabase->counter--;
}

/*
 * Description: Prints a list of all the movies in the database
 * Returns: Void
 */
void showMoviesList(MoviesDatabase* moviesDatabase) {
    for (int i = 0; i < moviesDatabase->counter; i++) {
        printf("\n#%i", i);
        printf("\nName: %s", moviesDatabase->moviesList[i]->name);
        printf("\nPrice: %.2f\n", moviesDatabase->moviesList[i]->price);
    }
}

/*
 * Description: Frees the space of memory assigned for a movies database and all its components
 * Returns: Void
 */
void freeMoviesDatabase(MoviesDatabase* moviesDatabase) {
    free(moviesDatabase);
}
