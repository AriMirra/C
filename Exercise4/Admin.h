#ifndef CFROMJAVA_ADMIN_H
#define CFROMJAVA_ADMIN_H

#include "Receptionist.h"
#include "Client.h"
#include "Reservation.h"
/*
 * Description:
 */
typedef struct Admin{
    Receptionist* receptionistsList[50];     // There can be a maximum of 50 receptionist at a time
    Client* clientsList[500];                // There can be a maximum of 500 clients in the hotel at a time
    Reservation* reservationsList[500];      // 500 reservations can be generated in total
    Invoice* invoicesList[500];              // 500 invoices created
    int receptionistsCounter;
    int clientsCounter;
    int reservationCounter;
    int invoiceCounter;
}Admin;

Admin* new_Admin();
void freeAdmin(Admin* admin);

void addReceptionist(Admin* admin, Receptionist* receptionist);
void addClient(Admin* admin, Client* client);
void addReservation(Admin* admin, Reservation* reservation);
void addInvoice(Admin* admin, Invoice* invoice);
void showReceptionistsList(Admin* admin);
void showClientsList(Admin* admin);
void showReservationList(Admin* admin);

#endif //CFROMJAVA_ADMIN_H
