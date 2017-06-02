#include "Reservation.h"
#include <malloc.h>
#include <memory.h>

Reservation* new_Reservation(char* clientSurname, int clientId, int roomNumber) {

    Reservation* reservation = malloc(sizeof(Reservation));

    reservation->clientSurname = malloc(sizeof(char) * (strlen(clientSurname) + 1));
    reservation->clientId = clientId;
    reservation->roomNumber = roomNumber;

    strcpy(reservation->clientSurname, clientSurname);

    return reservation;
}

void freeReservation(Reservation* reservation) {
    free(reservation->clientSurname);
    free(reservation);
}
