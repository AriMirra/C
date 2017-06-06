#ifndef CFROMJAVA_ROOM_H
#define CFROMJAVA_ROOM_H

#include "Client.h"

/*
 * Description: The Room structure contains information about the room, its number, type, its availability status, price, and, 
 * if it is occupied, the Client in it
 */
typedef struct Room{
    int number;
    int type;                       // 0 = Basic, 1 = Deluxe
    int isOccupied;                 // 0 = No, 1 = Yes
    Client* client;
    double price;
}Room;

// Functions
Room* new_Room(int number, int type);
void freeRoom(Room* room);

void accommodateClient(Room* room, Client* client);

#endif //CFROMJAVA_ROOM_H
