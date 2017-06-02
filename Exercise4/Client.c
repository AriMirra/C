#include "Client.h"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
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

Reservation* bookBasicRoom(Client* client, Hotel* hotel) {
    Reservation* reservation = NULL;
    for (int i = 0; i < 400; i++) {
        if (!hotel->roomList[i]->isOccupied) {
            accommodateClient(hotel->roomList[i], client);
            reservation = new_Reservation(client->surname, client->id, hotel->roomList[i]->number);
        }
        if (i == 399) printf("\nThere are no basic rooms available at the moment");
    }
    return reservation;
}

Reservation* bookDeluxeRoom(Client* client, Hotel* hotel) {
    Reservation* reservation =  NULL;
    for (int i = 400; i < sizeof(hotel->roomList) / sizeof(hotel->roomList[0]); i++) {
        if (!hotel->roomList[i]->isOccupied) {
            accommodateClient(hotel->roomList[i], client);
            reservation = new_Reservation(client->surname, client->id, hotel->roomList[i]->number);
        }
        if (i == sizeof(hotel->roomList) / sizeof(hotel->roomList[0]) - 1) printf("\nThere are no deluxe rooms available at the moment\n\n");
    }
    return reservation;
}

void askForInfo(Hotel* hotel) {
    giveInfo(hotel);
}

void freeClient(Client* client) {
    free(client->name);
    free(client->surname);
    free(client);
}
