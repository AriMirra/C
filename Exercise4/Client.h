#ifndef CFROMJAVA_CLIENT_H
#define CFROMJAVA_CLIENT_H

#include "Invoice.h"
/*
 * Description:
 */
typedef struct Client{
    char* name;
    char* surname;
    int id;
    Invoice* invoice;
    double debt;
}Client;

Client* new_Client(char* name, char* surname, int id);
void freeClient(Client* client);

void payForRoom(Invoice* invoice, Client* client);

#endif //CFROMJAVA_CLIENT_H
