#include "ClientsDatabase.h"
#include <malloc.h>
#include <stdio.h>

ClientsDatabase* new_ClientsDatabase() {

    ClientsDatabase* clientsDatabase = malloc(sizeof(ClientsDatabase));

    clientsDatabase->counter = 0;

    return clientsDatabase;
}

void addClient(ClientsDatabase* clientsDatabase, Client* client) {
    if (clientsDatabase->counter < sizeof(clientsDatabase->clientsList) / sizeof(clientsDatabase->clientsList[0])) {
        clientsDatabase->clientsList[clientsDatabase->counter] = client;
        clientsDatabase->counter++;
    } else printf("Max capacity reached");
}

void removeClient(ClientsDatabase* clientsDatabase, int position) {
    for (int i = position; i < clientsDatabase->counter; i++) {
        clientsDatabase->clientsList[i] = clientsDatabase->clientsList[i + 1];
    }
    clientsDatabase->counter--;
}

void showClientsList(ClientsDatabase* clientsDatabase) {
    for (int i = 0; i < clientsDatabase->counter; i++) {
        printf("\n#%i", i);
        printf("\nName: %s", clientsDatabase->clientsList[i]->name);
        printf("\nSurname: %s", clientsDatabase->clientsList[i]->surname);
        printf("\nID: %i\n", clientsDatabase->clientsList[i]->id);
    }
}

void freeClientsDatabase(ClientsDatabase* clientsDatabase) {
    free(clientsDatabase);
}
