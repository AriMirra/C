#ifndef CFROMJAVA_MOVIE_H
#define CFROMJAVA_MOVIE_H

typedef struct movie Movie;
struct movie {
    char* name;
    double price;
};

Movie* new_Movie(char* name, double price);
void freeMovie(Movie* movie);

#endif //CFROMJAVA_MOVIE_H
