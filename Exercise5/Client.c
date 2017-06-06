#include "Client.h"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>

/*
 * Description: Contains the functions related to the Client structure
 */

/*
 * Description: Creates a Client
 * Returns: The Client created
 */
Client* new_Client(char* name, char* surname, int id) {

    Client* client = malloc(sizeof(Client));

    client->name = malloc(sizeof(char) * (strlen(name) + 1));
    client->surname = malloc(sizeof(char) * (strlen(surname) + 1));
    client->id = id;
    client->debt = 0;
    client->moviesCounter = 0;

    strcpy(client->name, name);
    strcpy(client->surname, surname);

    return client;
}

/*
 * Description: Rents a movie
 * Returns: Void
 */
void rentMovie(Client* client, int days, MoviesDatabase* moviesDatabase, int position, Excess* excess) {
    if (client->moviesCounter < sizeof(client->moviesList) / sizeof(client->moviesList[0])) {
        client->debt += moviesDatabase->moviesList[position]->price * days;
        excess->income += moviesDatabase->moviesList[position]->price * days;
        client->moviesList[client->moviesCounter] = moviesDatabase->moviesList[position];
        excess->rentedMovies[excess->rentedMoviesCounter] = moviesDatabase->moviesList[position]->name;
        removeMovie(moviesDatabase, position);
        client->moviesCounter++;
        excess->rentedMoviesCounter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Prints a list of movies in my possession
 * Returns: Void
 */
void showMyMovies(Client* client) {
    for (int i = 0; i < client->moviesCounter; i++) {
        printf("\n#%s\n", client->moviesList[i]->name);
    }
}

/*
 * Description: Shows the total debt of a client
 * Returns: Void
 */
void showTotalDebt(Client* client) {
    printf("\n$%.2f\n", client->debt);
}

/*
 * Description: Frees the space of memory assigned to a client and all its components
 * Returns: Void
 */
void freeClient(Client* client) {
    free(client->name);
    free(client->surname);
    free(client);
}
