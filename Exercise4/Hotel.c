#include "Hotel.h"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>

/*
 * Description: creates a Hotel
 * Returns: Hotel pointer
 */
Hotel* new_Hotel() {

    Hotel* hotel = malloc(sizeof(Hotel));

    hotel->name = "Hotel";          // Standard name if it is not changed by the admin
    hotel->basicRoomPrice = 200;
    hotel->deluxeRoomPrice = 500;
    hotel->roomListCounter = 0;

    for (int i = 0; i < 500; i++) {
        // Rooms numbered 0 to 399 are basic, and the ones from 400 all the way to 499 are deluxe
        if (i < 400) {
            hotel->roomList[hotel->roomListCounter] = new_Room(i, 0);
            hotel->roomList[i]->price = hotel->basicRoomPrice;
        } else {
            hotel->roomList[hotel->roomListCounter] = new_Room(i, 1);
            hotel->roomList[i]->price = hotel->deluxeRoomPrice;
        }
        hotel->roomList[i]->isOccupied = 0;
        hotel->roomListCounter++;
    }

    return hotel;
}

void setHotelName(Hotel* hotel, char* name) {
    hotel->name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(hotel->name, name);
}

Reservation* bookBasicRoom(Client* client, Hotel* hotel) {
    Reservation* reservation = NULL;
    for (int i = 0; i < 400; i++) {
        if (!hotel->roomList[i]->isOccupied) {
            accommodateClient(hotel->roomList[i], client);
            reservation = new_Reservation(client->surname, client->id, hotel->roomList[i]->number);
            break;
        }
        if (i == 399) printf("\nThere are no basic rooms available at the moment");
    }
    return reservation;
}

Reservation* bookDeluxeRoom(Client* client, Hotel* hotel) {
    Reservation* reservation =  NULL;
    for (int i = 400; i < sizeof(hotel->roomList) / sizeof(hotel->roomList[0]); i++) {
        if (!hotel->roomList[i]->isOccupied) {
            accommodateClient(hotel->roomList[i], client);
            reservation = new_Reservation(client->surname, client->id, hotel->roomList[i]->number);
            break;
        }
        if (i == sizeof(hotel->roomList) / sizeof(hotel->roomList[0]) - 1) printf("\nThere are no deluxe rooms available at the moment\n\n");
    }
    return reservation;
}

void freeHotel(Hotel* hotel) {
    free(hotel);
}
