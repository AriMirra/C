#ifndef CFROMJAVA_INVOICE_H
#define CFROMJAVA_INVOICE_H

#include "InvoiceLine.h"
#include "ShoppingCart.h"

typedef struct Invoice{
    InvoiceLine** invoiceLines;
    int amountOfLines;
    int toPay;
}Invoice;

//functions
Invoice* createInvoice(ShoppingCart* cart);
void destroyInvoice(Invoice* invoice);
#endif //CFROMJAVA_INVOICE_H