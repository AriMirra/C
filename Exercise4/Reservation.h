#ifndef CFROMJAVA_RESERVATION_H
#define CFROMJAVA_RESERVATION_H

/*
 * Description: The Reservation structure contains information about the reservation, specifically, the surname of the client, 
 * his ID, and the booked room number
 */
typedef struct Reservation{
    char* clientSurname;
    int clientId;
    int roomNumber;
}Reservation;

// Functions
Reservation* new_Reservation(char* clientSurname, int clientId, int roomNumber);
void freeReservation(Reservation* reservation);

#endif //CFROMJAVA_RESERVATION_H
