#ifndef CFROMJAVA_HOTEL_H
#define CFROMJAVA_HOTEL_H

#include "Room.h"
#include "Client.h"

typedef struct hotel Hotel;
struct hotel {
    char* name;
    Room* roomList[500];            // The hotel has a total of 500 rooms for lodging
    double basicRoomPrice;
    double deluxeRoomPrice;
};

Hotel* new_Hotel();
void freeHotel(Hotel* hotel);

void setHotelName(Hotel* hotel, char* name);

#endif //CFROMJAVA_HOTEL_H
