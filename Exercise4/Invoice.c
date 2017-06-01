#include "Invoice.h"
#include <malloc.h>
#include <memory.h>

Invoice* new_Invoice(int invoiceNumber, char* hotelName, char* clientName, int clientId, double priceToPay) {

    Invoice* invoice = malloc(sizeof(Invoice));

    invoice->invoiceNumber = invoiceNumber;
    invoice->hotelName = malloc(sizeof(char) * (strlen(hotelName) + 1));
    invoice->clientName = malloc(sizeof(char) * (strlen(clientName) + 1));
    invoice->clientId = clientId;
    invoice->priceToPay = priceToPay;

    strcpy(invoice->hotelName, hotelName);
    strcpy(invoice->clientName, clientName);

    return invoice;
}

void payForRoom(Invoice* invoice) {

}

void freeInvoice(Invoice* invoice) {
    free(invoice->hotelName);
    free(invoice->clientName);
    free(invoice);
}
