#include "ClientsDatabase.h"
#include <malloc.h>
#include <stdio.h>

/*
 * Description: Contains the functions of the ClientsDatabase struct 
 */

/*
 * Description: Creates a ClientsDatabase
 * Returns: The ClientsDatabase created
 */
ClientsDatabase* new_ClientsDatabase() {

    ClientsDatabase* clientsDatabase = malloc(sizeof(ClientsDatabase));

    clientsDatabase->counter = 0;

    return clientsDatabase;
}

/*
 * Description: Adds a client to the database
 * Returns: Void
 */
void addClient(ClientsDatabase* clientsDatabase, Client* client) {
    if (clientsDatabase->counter < sizeof(clientsDatabase->clientsList) / sizeof(clientsDatabase->clientsList[0])) {
        clientsDatabase->clientsList[clientsDatabase->counter] = client;
        clientsDatabase->counter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Prints a list of clients that are in the database
 * Returns: Void
 */
void showClientsList(ClientsDatabase* clientsDatabase) {
    for (int i = 0; i < clientsDatabase->counter; i++) {
        printf("\n#%i", i);
        printf("\nName: %s", clientsDatabase->clientsList[i]->name);
        printf("\nSurname: %s", clientsDatabase->clientsList[i]->surname);
        printf("\nID: %i\n", clientsDatabase->clientsList[i]->id);
    }
}

/*
 * Description: Frees the space of memory assigned to a clients database and all its components
 * Returns: Void
 */
void freeClientsDatabase(ClientsDatabase* clientsDatabase) {
    free(clientsDatabase);
}
