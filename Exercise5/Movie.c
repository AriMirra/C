#include "Movie.h"
#include <malloc.h>
#include <memory.h>

Movie* new_Movie(char* name, double price) {

    Movie* movie = malloc(sizeof(Movie));

    movie->name = malloc(sizeof(char) * (strlen(name) + 1));
    movie->price = price;

    strcpy(movie->name, name);

    return movie;
}

void freeMovie(Movie* movie) {
    free(movie->name);
    free(movie);
}
