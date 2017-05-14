//
// Created by arimi on 14-May-17.
//

#ifndef CFROMJAVA_INVOICE_H
#define CFROMJAVA_INVOICE_H

typedef struct invoice Invoice;

struct Invoice{
    char* id;
    float* toPay;
};

//functions
Invoice* createInvoice(char* id, float* toPay);

#endif //CFROMJAVA_INVOICE_H
