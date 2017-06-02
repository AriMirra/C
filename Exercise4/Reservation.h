#ifndef CFROMJAVA_RESERVATION_H
#define CFROMJAVA_RESERVATION_H

typedef struct reservation Reservation;
struct reservation {
    char* clientSurname;
    int clientId;
    int roomNumber;
};

Reservation* new_Reservation(char* clientSurname, int clientId, int roomNumber);
void freeReservation(Reservation* reservation);

#endif //CFROMJAVA_RESERVATION_H
