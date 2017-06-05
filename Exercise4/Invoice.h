#ifndef CFROMJAVA_INVOICE_H
#define CFROMJAVA_INVOICE_H

/*
 * Description:
 */
typedef struct Invoice {
    int invoiceNumber;
    char* hotelName;
    char* clientName;
    int clientId;
    double priceToPay;
}Invoice;

Invoice* new_Invoice(char* hotelName, char* clientName, int clientId, double priceToPay);
void freeInvoice(Invoice* invoice);

void printInvoice(Invoice* invoice);

#endif //CFROMJAVA_INVOICE_H
