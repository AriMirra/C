#ifndef CFROMJAVA_ROOM_H
#define CFROMJAVA_ROOM_H

#include "Client.h"
/*
 * Description:
 */
typedef struct Room{
    int number;
    int type;                       // 0 = Basic, 1 = Deluxe
    int isOccupied;                 // 0 = No, 1 = Yes
    Client* client;
    double price;
}Room;

Room* new_Room(int number, int type);
void freeRoom(Room* room);

void accommodateClient(Room* room, Client* client);

#endif //CFROMJAVA_ROOM_H
