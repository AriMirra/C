#ifndef CFROMJAVA_MOVIE_H
#define CFROMJAVA_MOVIE_H

/*
 * Description: The Movie struct contains information about a movie, its name and its price
 */
typedef struct movie Movie;
struct movie {
    char* name;
    double price;
};

// Functions
Movie* new_Movie(char* name, double price);
void freeMovie(Movie* movie);

#endif //CFROMJAVA_MOVIE_H
