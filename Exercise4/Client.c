#include "Client.h"
#include <malloc.h>
#include <memory.h>

Client* new_Client(char* name, char* surname, int id) {

    Client* client = malloc(sizeof(Client));

    client->name = malloc(sizeof(char) * (strlen(name) + 1));
    client->surname = malloc(sizeof(char) * (strlen(surname) + 1));
    client->id = id;

    strcpy(client->name, name);
    strcpy(client->surname, surname);

    return client;
}

void checkIn(Client* client) {

}

void askForInfo(Client* client) {

}

void freeClient(Client* client) {
    free(client->name);
    free(client->surname);
    free(client);
}
