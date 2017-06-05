#include "Client.h"
#include <malloc.h>
#include <memory.h>

/*
 * Description: creates a Client
 * Returns: Client pointer
 */
Client* new_Client(char* name, char* surname, int id) {

    Client* client = malloc(sizeof(Client));

    client->name = malloc(sizeof(char) * (strlen(name) + 1));
    client->surname = malloc(sizeof(char) * (strlen(surname) + 1));
    client->id = id;
    client->debt = 0;

    strcpy(client->name, name);
    strcpy(client->surname, surname);

    return client;
}

void payForRoom(Invoice* invoice, Client* client) {
    client->debt += invoice->priceToPay;
}

void freeClient(Client* client) {
    free(client->name);
    free(client->surname);
    free(client);
}
