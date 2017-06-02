#ifndef CFROMJAVA_INVOICE_H
#define CFROMJAVA_INVOICE_H

#include "Client.h"

typedef struct invoice Invoice;
struct invoice {
    int invoiceNumber;
    char* hotelName;
    char* clientName;
    int clientId;
    double priceToPay;
};

Invoice* new_Invoice(char* hotelName, char* clientName, int clientId, double priceToPay);
void freeInvoice(Invoice* invoice);

void payForRoom(Invoice* invoice, Client* client);
void printInvoice(Invoice* invoice);

#endif //CFROMJAVA_INVOICE_H
