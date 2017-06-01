#include "Reservation.h"
#include <malloc.h>
#include <memory.h>

Reservation* new_Reservation(int clientNumber, char* clientSurname, int clientId, int roomNumber) {

    Reservation* reservation = malloc(sizeof(Reservation));

    reservation->clientNumber = clientNumber;
    reservation->clientSurname = malloc(sizeof(char) * (strlen(clientSurname) + 1));
    reservation->clientId = clientId;
    reservation->roomNumber = roomNumber;

    strcpy(reservation->clientSurname, clientSurname);

    return reservation;
}

void bookReservation(Reservation* reservation) {

}

void freeReservation(Reservation* reservation) {
    free(reservation->clientSurname);
    free(reservation);
}
