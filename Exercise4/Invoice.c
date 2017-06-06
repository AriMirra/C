#include "Invoice.h"
#include <malloc.h>
#include <memory.h>
#include <time.h>
#include <stdio.h>

/*
 * Description: Contains the functions related to the Invoice structure
 */

/*
 * Description: Creates an Invoice
 * Returns: The Invoice created
 */
Invoice* new_Invoice(char* hotelName, char* clientName, int clientId, double priceToPay) {

    Invoice* invoice = malloc(sizeof(Invoice));

    srand((unsigned int) time(NULL));
    int invoiceNumber = (rand() % (1000000000 - 100000000)) + 100000000;     // Random number of 9 digits (between 100000000 and 999999999)

    invoice->invoiceNumber = invoiceNumber;
    invoice->hotelName = malloc(sizeof(char) * (strlen(hotelName) + 1));
    invoice->clientName = malloc(sizeof(char) * (strlen(clientName) + 1));
    invoice->clientId = clientId;
    invoice->priceToPay = priceToPay;

    strcpy(invoice->hotelName, hotelName);
    strcpy(invoice->clientName, clientName);

    return invoice;
}

/*
 * Description: Prints the invoice
 * Returns: Void
 */
void printInvoice(Invoice* invoice) {
    printf("\nInvoice number: %i", invoice->invoiceNumber);
    printf("\nHotel name: %s", invoice->hotelName);
    printf("\nClient name: %s", invoice->clientName);
    printf("\nClient ID: %i", invoice->clientId);
    printf("\nTotal to pay: $%.2f\n\n", invoice->priceToPay);
}

/*
 * Description: Frees the space of memory assigned for an invoice and all its components
 * Returns: Void
 */
void freeInvoice(Invoice* invoice) {
    free(invoice->hotelName);
    free(invoice->clientName);
    free(invoice);
}
