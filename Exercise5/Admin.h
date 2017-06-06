#ifndef CFROMJAVA_ADMIN_H
#define CFROMJAVA_ADMIN_H

#include "Client.h"
#include "License.h"
#include "Movie.h"
#include "ClientsDatabase.h"
#include "MoviesDatabase.h"

/*
 * Description: The Admin structure contains information related to an admin, like his name, surname, ID, and he also has a 
 * list of all the licenses
 */
typedef struct admin Admin;
struct admin {
    char* name;
    char* surname;
    int id;
    License* licensesList[500];             // A maximum of 500 licenses can be registered
    int licensesCounter;
};

// Functions
Admin* new_Admin(char* name, char* surname, int id);
void freeAdmin(Admin* admin);

void registerClient(Admin* admin, Client* client, ClientsDatabase* clientsDatabase);
void registerMovie(Movie* movie, MoviesDatabase* moviesDatabase);

#endif //CFROMJAVA_ADMIN_H
