#ifndef CFROMJAVA_INVOICELINE_H
#define CFROMJAVA_INVOICELINE_H

#include "CartLine.h"

typedef struct InvoiceLine{
    char* applianceName;
    int priceOfAppliance;
    int units;
}InvoiceLine;

//functions
InvoiceLine* createInvoiceLine(CartLine* cartLine);
void destroyInvoiceLine(InvoiceLine* invoiceLine);
#endif //CFROMJAVA_INVOICELINE_H