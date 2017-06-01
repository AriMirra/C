#include "Client.h"

#ifndef CFROMJAVA_ROOM_H
#define CFROMJAVA_ROOM_H

typedef struct room Room;
struct room {
    int roomNumber;
    char* roomType;
};

Room* new_Room(int roomNumber, char* roomType);
void freeRoom(Room* room);

void accommodateClient(Room* room, Client* client);

#endif //CFROMJAVA_ROOM_H
