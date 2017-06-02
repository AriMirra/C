#include "Admin.h"
#include <malloc.h>
#include <stdio.h>
/*
 * Description: creates an Admin
 * Returns: Admin pointer
 */
Admin* new_Admin() {

    Admin* admin = malloc(sizeof(Admin));

    admin->receptionistsCounter = 0;
    admin->clientsCounter = 0;
    admin->reservationCounter = 0;
    admin->invoiceCounter = 0;

    return admin;
}

void addReceptionist(Admin* admin, Receptionist* receptionist) {
    if (admin->receptionistsCounter < sizeof(admin->receptionistsList) / sizeof(admin->receptionistsList[0])) {
        admin->receptionistsList[admin->receptionistsCounter] = receptionist;
        admin->receptionistsCounter++;
    } else printf("Max capacity reached");
}

void showReceptionistsList(Admin* admin) {
    for (int i = 0; i < admin->receptionistsCounter; i++) {
        printf("\n#%i", i);
        printf("\nName: %s", admin->receptionistsList[i]->name);
        printf("\nSurname: %s", admin->receptionistsList[i]->surname);
        printf("\nID: %i\n", admin->receptionistsList[i]->id);
    }
}

void addClient(Admin* admin, Client* client) {
    if (admin->clientsCounter < sizeof(admin->clientsList) / sizeof(admin->clientsList[0])) {
        admin->clientsList[admin->clientsCounter] = client;
        admin->clientsCounter++;
    } else printf("Max capacity reached");
}

void showClientsList(Admin* admin) {
    for (int i = 0; i < admin->clientsCounter; i++) {
        printf("\n#%i", i);
        printf("\nName: %s", admin->clientsList[i]->name);
        printf("\nSurname: %s", admin->clientsList[i]->surname);
        printf("\nID: %i\n", admin->clientsList[i]->id);

    }
}

void addReservation(Admin* admin, Reservation* reservation) {
    if (admin->reservationCounter < sizeof(admin->reservationsList) / sizeof(admin->reservationsList[0])) {
        admin->reservationsList[admin->reservationCounter] = reservation;
        admin->reservationCounter++;
    } else printf("Max capacity reached");
}

void showReservationList(Admin* admin) {
    for (int i = 0; i < admin->reservationCounter; i++) {
        printf("\n#%i", i);
        printf("\nClient surname: %s", admin->reservationsList[i]->clientSurname);
        printf("\nClient ID: %i", admin->reservationsList[i]->clientId);
        printf("\nRoom number: %i\n", admin->reservationsList[i]->roomNumber);

    }
}

void addInvoice(Admin* admin, Invoice* invoice) {
    if (admin->invoiceCounter < sizeof(admin->invoicesList) / sizeof(admin->invoicesList[0])) {
        admin->invoicesList[admin->invoiceCounter] = invoice;
        admin->invoiceCounter++;
    } else printf("Max capacity reached");
}

void freeAdmin(Admin* admin) {
    free(admin);
}
