#ifndef CFROMJAVA_RESERVATION_H
#define CFROMJAVA_RESERVATION_H
/*
 * Description:
 */
typedef struct Reservation{
    char* clientSurname;
    int clientId;
    int roomNumber;
}Reservation;

Reservation* new_Reservation(char* clientSurname, int clientId, int roomNumber);
void freeReservation(Reservation* reservation);

#endif //CFROMJAVA_RESERVATION_H
