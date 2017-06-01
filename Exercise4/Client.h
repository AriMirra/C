#ifndef CFROMJAVA_CLIENT_H
#define CFROMJAVA_CLIENT_H

typedef struct client Client;
struct client {
    char* name;
    char* surname;
    int id;
};

Client* new_Client(char* name, char* surname, int id);
void freeClient(Client* client);

void checkIn(Client* client);
void askForInfo(Client* client);

#endif //CFROMJAVA_CLIENT_H
