#ifndef CFROMJAVA_INVOICE_H
#define CFROMJAVA_INVOICE_H

#include "InvoiceLine.h"
#include "ShoppingCart.h"

/*
 * Description: The Invoice structure holds the information of a purchase, all the appliances purchased, their price, and the total amount to pay.
 */
typedef struct Invoice{
    InvoiceLine** invoiceLines;
    int amountOfLines;
    int toPay;
}Invoice;

//functions
Invoice* createInvoice(ShoppingCart* cart);
void destroyInvoice(Invoice* invoice);
#endif //CFROMJAVA_INVOICE_H