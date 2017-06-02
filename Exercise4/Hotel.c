#include "Hotel.h"
#include <malloc.h>
#include <memory.h>

/*
 * Description: creates a Hotel
 * Returns: Hotel pointer
 */
Hotel* new_Hotel() {

    Hotel* hotel = malloc(sizeof(Hotel));

    hotel->name = "Hotel";          // Standard name if it is not changed by the admin
    hotel->basicRoomPrice = 200;
    hotel->deluxeRoomPrice = 500;

    for (int i = 0; i < sizeof(hotel->roomList) / sizeof(hotel->roomList[0]); i++) {
        // Rooms numbered 0 to 399 are basic, and the ones from 400 all the way to 499 are deluxe
        hotel->roomList[i]->isOccupied = 0;
        if (i < 400) {
            new_Room(i, 0);
            hotel->roomList[i]->price = hotel->basicRoomPrice;
        } else {
            new_Room(i, 1);
            hotel->roomList[i]->price = hotel->deluxeRoomPrice;
        }
    }

    return hotel;
}

void setHotelName(Hotel* hotel, char* name) {
    hotel->name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(hotel->name, name);
}

void freeHotel(Hotel* hotel) {
    free(hotel);
}
