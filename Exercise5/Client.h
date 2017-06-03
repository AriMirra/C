#ifndef CFROMJAVA_CLIENT_H
#define CFROMJAVA_CLIENT_H

#include "Movie.h"
#include "MoviesDatabase.h"
#include "Excess.h"

typedef struct client Client;
struct client {
    char* name;
    char* surname;
    int id;
    double debt;
    Movie* moviesList[5];                      // A client can have in possession as much as 5 movies at a time
    int moviesCounter;
};

Client* new_Client(char* name, char* surname, int id);
void freeClient(Client* client);

void rentMovie(Client* client, int days, MoviesDatabase* moviesDatabase, int position, Excess* excess);
void showMyMovies(Client* client);
void showTotalDebt(Client* client);

#endif //CFROMJAVA_CLIENT_H
