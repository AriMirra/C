#include "Admin.h"
#include <malloc.h>
#include <stdio.h>

/*
 * Description: Contains the functions related to the Admin struct
 */

/*
 * Description: Creates an Admin
 * Returns: The Admin Created
 */
Admin* new_Admin() {

    Admin* admin = malloc(sizeof(Admin));

    admin->receptionistsCounter = 0;
    admin->clientsCounter = 0;
    admin->reservationCounter = 0;
    admin->invoiceCounter = 0;

    return admin;
}

/*
 * Description: Adds a receptionist
 * Returns: Void
 */
void addReceptionist(Admin* admin, Receptionist* receptionist) {
    if (admin->receptionistsCounter < sizeof(admin->receptionistsList) / sizeof(admin->receptionistsList[0])) {
        admin->receptionistsList[admin->receptionistsCounter] = receptionist;
        admin->receptionistsCounter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Prints the list of receptionists
 * Returns: Void
 */
void showReceptionistsList(Admin* admin) {
    for (int i = 0; i < admin->receptionistsCounter; i++) {
        printf("\n#%i", i);
        printf("\nName: %s", admin->receptionistsList[i]->name);
        printf("\nSurname: %s", admin->receptionistsList[i]->surname);
        printf("\nID: %i\n", admin->receptionistsList[i]->id);
    }
}

/*
 * Description: Adds a client to the system
 * Returns: Void
 */
void addClient(Admin* admin, Client* client) {
    if (admin->clientsCounter < sizeof(admin->clientsList) / sizeof(admin->clientsList[0])) {
        admin->clientsList[admin->clientsCounter] = client;
        admin->clientsCounter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Shows the list of clients
 * Returns: Void
 */
void showClientsList(Admin* admin) {
    for (int i = 0; i < admin->clientsCounter; i++) {
        printf("\n#%i", i);
        printf("\nName: %s", admin->clientsList[i]->name);
        printf("\nSurname: %s", admin->clientsList[i]->surname);
        printf("\nID: %i\n", admin->clientsList[i]->id);

    }
}

/*
 * Description: Adds a reservation to a list
 * Returns: Void
 */
void addReservation(Admin* admin, Reservation* reservation) {
    if (admin->reservationCounter < sizeof(admin->reservationsList) / sizeof(admin->reservationsList[0])) {
        admin->reservationsList[admin->reservationCounter] = reservation;
        admin->reservationCounter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Prints the reservations list
 * Returns: Void
 */
void showReservationList(Admin* admin) {
    for (int i = 0; i < admin->reservationCounter; i++) {
        printf("\n#%i", i);
        printf("\nClient surname: %s", admin->reservationsList[i]->clientSurname);
        printf("\nClient ID: %i", admin->reservationsList[i]->clientId);
        printf("\nRoom number: %i\n", admin->reservationsList[i]->roomNumber);

    }
}

/*
 * Description: Adds an invoice to a list
 * Returns: Void
 */
void addInvoice(Admin* admin, Invoice* invoice) {
    if (admin->invoiceCounter < sizeof(admin->invoicesList) / sizeof(admin->invoicesList[0])) {
        admin->invoicesList[admin->invoiceCounter] = invoice;
        admin->invoiceCounter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Frees the space of memory assigned to an admin and all its components
 * Returns: Void
 */
void freeAdmin(Admin* admin) {
    free(admin);
}
