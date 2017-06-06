#include "Admin.h"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>

/*
 * Description: Contains the functions related to the Admin structure
 */

/*
 * Description: Creates an Admin
 * Returns: The Admin created
 */
Admin* new_Admin(char* name, char* surname, int id) {

    Admin* admin = malloc(sizeof(Admin));

    admin->name = malloc(sizeof(char) * (strlen(name) + 1));
    admin->surname = malloc(sizeof(char) * (strlen(surname) + 1));
    admin->id = id;
    admin->licensesCounter = 0;

    strcpy(admin->name, name);
    strcpy(admin->surname, surname);

    return admin;
}

/*
 * Description: Registers a new client, and creates a license for him
 * Returns: Void
 */
void registerClient(Admin* admin, Client* client, ClientsDatabase* clientsDatabase) {
    addClient(clientsDatabase, client);
    if (admin->licensesCounter < 500) {
        License* license = new_License(client->id);
        admin->licensesList[admin->licensesCounter] = license;
        admin->licensesCounter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Registers a new movie
 * Returns: Void
 */
void registerMovie(Movie* movie, MoviesDatabase* moviesDatabase) {
    addMovie(moviesDatabase, movie);
}

/*
 * Description: Frees the space of memory assigned to an admin and all its components
 * Returns: Void
 */
void freeAdmin(Admin* admin) {
    free(admin->name);
    free(admin->surname);
    free(admin);
}
