#ifndef CFROMJAVA_HOTEL_H
#define CFROMJAVA_HOTEL_H

#include "Room.h"
#include "Reservation.h"

/*
 * Description:
 */
typedef struct Hotel {
    char* name;
    Room* roomList[500];            // The hotel has a total of 500 rooms for lodging
    int roomListCounter;
    double basicRoomPrice;
    double deluxeRoomPrice;
}Hotel;

Hotel* new_Hotel();
void freeHotel(Hotel* hotel);

void setHotelName(Hotel* hotel, char* name);
Reservation* bookBasicRoom(Client* client, Hotel* hotel);
Reservation* bookDeluxeRoom(Client* client, Hotel* hotel);

#endif //CFROMJAVA_HOTEL_H
