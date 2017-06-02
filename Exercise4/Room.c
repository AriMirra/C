#include "Room.h"
#include <malloc.h>

/*
 * Description: creates a Room
 * Returns: Room pointer
 */
Room* new_Room(int number, int type) {

    Room* room = malloc(sizeof(Room));

    room->number = number;
    room->type = type;

    return room;
}

void accommodateClient(Room* room, Client* client) {
    room->client = client;
}

void freeRoom(Room* room) {
    free(room);
}
