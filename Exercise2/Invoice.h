#ifndef CFROMJAVA_INVOICE_H
#define CFROMJAVA_INVOICE_H

#include "InvoiceLine.h"
#include "Cart.h"

typedef struct Invoice{
    InvoiceLine** invoiceLines;
    int amountOfLines;
    int toPay;
}Invoice;

//functions
Invoice* createInvoice(Cart* cart);
void destroyInvoice(Invoice* invoice);
#endif //CFROMJAVA_INVOICE_H