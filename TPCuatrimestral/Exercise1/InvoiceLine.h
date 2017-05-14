//
// Created by arimi on 14-May-17.
//

#ifndef CFROMJAVA_INVOICELINE_H
#define CFROMJAVA_INVOICELINE_H

typedef struct invoiceLine InvoiceLine;

struct invoiceLine{
    char* id;
    char* article;
    int* units;
};


//functions
InvoiceLine* createInvoiceLine(char* id, char* article, int* units);


#endif //CFROMJAVA_INVOICELINE_H
