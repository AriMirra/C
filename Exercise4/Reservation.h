#ifndef CFROMJAVA_RESERVATION_H
#define CFROMJAVA_RESERVATION_H

typedef struct reservation Reservation;
struct reservation {
    int clientNumber;
    char* clientSurname;
    int clientId;
    int roomNumber;
};

Reservation* new_Reservation(int clientNumber, char* clientSurname, int clientId, int roomNumber);
void freeReservation(Reservation* reservation);

void bookReservation(Reservation* reservation);

#endif //CFROMJAVA_RESERVATION_H
