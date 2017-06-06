#include "Client.h"
#include <malloc.h>
#include <memory.h>

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

    strcpy(client->name, name);
    strcpy(client->surname, surname);

    return client;
}

/*
 * Description: Pays for the hotel room
 * Returns: Void
 */
void payForRoom(Invoice* invoice, Client* client) {
    client->debt += invoice->priceToPay;
}

/*
 * Description: Frees the space of memory assigned for a client and all its components
 * Returns: 
 */
void freeClient(Client* client) {
    free(client->name);
    free(client->surname);
    free(client);
}
