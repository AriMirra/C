#include <stdlib.h>
#include <string.h>
#include "InvoiceLine.h"

InvoiceLine* createInvoiceLine(ShoppingCartLine* cartLine){
    InvoiceLine* result = malloc(sizeof(InvoiceLine));
    result->applianceName = malloc(sizeof(char)*strlen(cartLine->appliance->name)+1);
    strcpy(result->applianceName, cartLine->appliance->name);
    result->units = cartLine->units;
    result->priceOfAppliance = cartLine->appliance->price;
    return result;
}

void destroyInvoiceLine(InvoiceLine* invoiceLine){
    free(invoiceLine->applianceName);
    free(invoiceLine);
}
