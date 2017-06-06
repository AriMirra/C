#ifndef CFROMJAVA_CLIENT_H
#define CFROMJAVA_CLIENT_H

#include "Invoice.h"

/*
 * Description: The Client structure contains information about the client, his name, surname, ID, current debt, and,
 * once effectuated, his invoice
 */
typedef struct Client{
    char* name;
    char* surname;
    int id;
    Invoice* invoice;
    double debt;
}Client;

// Functions
Client* new_Client(char* name, char* surname, int id);
void freeClient(Client* client);

void payForRoom(Invoice* invoice, Client* client);

#endif //CFROMJAVA_CLIENT_H
