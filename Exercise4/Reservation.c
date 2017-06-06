#include "Reservation.h"
#include <malloc.h>
#include <memory.h>

/*
 * Description: Contains the functions related to the Reservation structure
 */

/*
 * Description: Creates a Reservation
 * Returns: The Reservation created
 */
Reservation* new_Reservation(char* clientSurname, int clientId, int roomNumber) {

    Reservation* reservation = malloc(sizeof(Reservation));

    reservation->clientSurname = malloc(sizeof(char) * (strlen(clientSurname) + 1));
    reservation->clientId = clientId;
    reservation->roomNumber = roomNumber;

    strcpy(reservation->clientSurname, clientSurname);

    return reservation;
}

/*
 * Description: Frees the space of memory assigned to a reservation and all its components
 * Returns: Void
 */
void freeReservation(Reservation* reservation) {
    free(reservation->clientSurname);
    free(reservation);
}
