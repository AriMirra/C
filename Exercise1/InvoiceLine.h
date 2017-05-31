#ifndef CFROMJAVA_INVOICELINE_H
#define CFROMJAVA_INVOICELINE_H

#include "ShoppingCartLine.h"

/*
 * Description: The InvoiceLine structure holds the information of a single type of appliance purchased and the amount purchased, an Invoice contains multiple InvoiceLines.
 */
typedef struct InvoiceLine{
    char* applianceName;
    int priceOfAppliance;
    int units;
}InvoiceLine;

//functions
InvoiceLine* createInvoiceLine(ShoppingCartLine* cartLine);
void destroyInvoiceLine(InvoiceLine* invoiceLine);
#endif //CFROMJAVA_INVOICELINE_H