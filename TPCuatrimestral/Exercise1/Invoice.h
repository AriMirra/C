#ifndef CFROMJAVA_INVOICE_H
#define CFROMJAVA_INVOICE_H


typedef struct Invoice{
    char* id;
    int toPay;
}Invoice;

//functions
Invoice* createInvoice(char* id, int toPay);

#endif //CFROMJAVA_INVOICE_H
