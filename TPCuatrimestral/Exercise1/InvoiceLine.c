#include <stdlib.h>
#include <string.h>
#include "InvoiceLine.h"

InvoiceLine* createInvoiceLine(ShoppingCartLine* cartLine){
    InvoiceLine* result = malloc(sizeof(InvoiceLine));
    result->applianceId = malloc(sizeof(char)*strlen(cartLine->appliance->label->id)+1);
    strcpy(result->applianceId, cartLine->appliance->label->id);
    result->units = cartLine->units;
}

void destroyInvoiceLine(InvoiceLine* invoiceLine){
    free(invoiceLine);
}
