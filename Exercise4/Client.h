#ifndef CFROMJAVA_CLIENT_H
#define CFROMJAVA_CLIENT_H

#include "Receptionist.h"
#include "Reservation.h"
#include "Hotel.h"
#include "Invoice.h"

typedef struct client Client;
struct client {
    char* name;
    char* surname;
    int id;
    Invoice* invoice;
    double debt;
};

Client* new_Client(char* name, char* surname, int id);
void freeClient(Client* client);

Reservation* bookBasicRoom(Client* client, Hotel* hotel);
Reservation* bookDeluxeRoom(Client* client, Hotel* hotel);
void askForInfo(Hotel* hotel);

#endif //CFROMJAVA_CLIENT_H
