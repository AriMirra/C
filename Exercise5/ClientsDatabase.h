#ifndef CFROMJAVA_CLIENTSDATABASE_H
#define CFROMJAVA_CLIENTSDATABASE_H

#include "Client.h"

/*
 * Description: The ClientsDatabase struct contains a list of registered clients
 */
typedef struct clientsDatabase ClientsDatabase;
struct clientsDatabase {
    Client* clientsList[500];               // A maximum of 500 clients can be in the system at a time
    int counter;
};

// Functions
ClientsDatabase* new_ClientsDatabase();
void freeClientsDatabase(ClientsDatabase* clientsDatabase);

void addClient(ClientsDatabase* clientsDatabase, Client* client);
void showClientsList(ClientsDatabase* clientsDatabase);

#endif //CFROMJAVA_CLIENTSDATABASE_H
