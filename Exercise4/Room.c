#include "Room.h"
#include <malloc.h>

/*
 * Description: Contains the functions related to the Room structure
 */

/*
 * Description: Creates a Room
 * Returns: The Room created
 */
Room* new_Room(int number, int type) {

    Room* room = malloc(sizeof(Room));

    room->number = number;
    room->type = type;

    return room;
}

/*
 * Description: Accommodates a client in the room he previously booked
 * Returns: Void
 */
void accommodateClient(Room* room, Client* client) {
    room->client = client;
}

/*
 * Description: Frees the space of memory assigned for a room and all its components
 * Returns: Void
 */
void freeRoom(Room* room) {
    free(room);
}
