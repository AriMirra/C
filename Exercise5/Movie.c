#include "Movie.h"
#include <malloc.h>
#include <memory.h>

/*
 * Description: Contains the functions of the Movie struct
 */

/*
 * Description: Creates a Movie
 * Returns: The Movie created
 */
Movie* new_Movie(char* name, double price) {

    Movie* movie = malloc(sizeof(Movie));

    movie->name = malloc(sizeof(char) * (strlen(name) + 1));
    movie->price = price;

    strcpy(movie->name, name);

    return movie;
}

/*
 * Description: Frees the space of memory assigned for a movie and all its components
 * Returns: Void
 */
void freeMovie(Movie* movie) {
    free(movie->name);
    free(movie);
}
