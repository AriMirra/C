#ifndef CFROMJAVA_INVOICE_H
#define CFROMJAVA_INVOICE_H

/*
 * Description: The Invoice structure contains information about the invoice, like its number, the name of the hotel, the 
 * name of the client, his ID, and the price to pay
 */
typedef struct Invoice {
    int invoiceNumber;
    char* hotelName;
    char* clientName;
    int clientId;
    double priceToPay;
}Invoice;

// Functions
Invoice* new_Invoice(char* hotelName, char* clientName, int clientId, double priceToPay);
void freeInvoice(Invoice* invoice);

void printInvoice(Invoice* invoice);

#endif //CFROMJAVA_INVOICE_H
