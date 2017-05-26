#ifndef CFROMJAVA_INVOICELINE_H
#define CFROMJAVA_INVOICELINE_H

#include "ShoppingCartLine.h"

typedef struct InvoiceLine{
    char* applianceId;
    int units;
}InvoiceLine;

//functions
InvoiceLine* createInvoiceLine(ShoppingCartLine* cartLine);
void destroyInvoiceLine(InvoiceLine* invoiceLine);
#endif //CFROMJAVA_INVOICELINE_H
