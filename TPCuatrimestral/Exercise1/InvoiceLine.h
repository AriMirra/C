#ifndef CFROMJAVA_INVOICELINE_H
#define CFROMJAVA_INVOICELINE_H

typedef struct InvoiceLine{
    char* id;
    char* article;
    int* units;
}InvoiceLine;


//functions
InvoiceLine* createInvoiceLine(char* id, char* article, int* units);


#endif //CFROMJAVA_INVOICELINE_H
