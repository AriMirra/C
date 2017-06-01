#include "Room.h"
#include <malloc.h>
#include <memory.h>

Room* new_Room(int roomNumber, char* roomType) {

    Room* room = malloc(sizeof(Room));

    room->roomNumber = roomNumber;
    room->roomType = malloc(sizeof(char) * (strlen(roomType) + 1));

    strcpy(room->roomType, roomType);

    return room;
}

void accommodateClient(Room* room, Client* client) {

}

void freeRoom(Room* room) {
    free(room->roomType);
    free(room);
}
