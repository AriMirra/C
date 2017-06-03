#ifndef CFROMJAVA_ADMIN_H
#define CFROMJAVA_ADMIN_H

#include "Client.h"
#include "License.h"
#include "Movie.h"
#include "ClientsDatabase.h"
#include "MoviesDatabase.h"

typedef struct admin Admin;
struct admin {
    char* name;
    char* surname;
    int id;
    License* licensesList[500];             // A maximum of 500 licenses can be registered
    int licensesCounter;
};

Admin* new_Admin(char* name, char* surname, int id);
void freeAdmin(Admin* admin);

void registerClient(Admin* admin, Client* client, ClientsDatabase* clientsDatabase);
void registerMovie(Movie* movie, MoviesDatabase* moviesDatabase);

#endif //CFROMJAVA_ADMIN_H
