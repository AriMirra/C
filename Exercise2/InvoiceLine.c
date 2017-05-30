#include <stdlib.h>
#include <string.h>
#include "InvoiceLine.h"
/*
 * Description: creates an InvoiceLine
 * Returns: the InvoiceLine created
 */
InvoiceLine* createInvoiceLine(ShoppingCartLine* cartLine){
    InvoiceLine* result = malloc(sizeof(InvoiceLine));
    result->applianceName = malloc(sizeof(char)*strlen(cartLine->appliance->name)+1);
    strcpy(result->applianceName, cartLine->appliance->name);
    result->units = cartLine->units;
    result->priceOfAppliance = cartLine->appliance->price;
    return result;
}

/*
 * Description: Deallocates memory assigned for an InvoiceLine and all its components
 * Return: void
 */
void destroyInvoiceLine(InvoiceLine* invoiceLine){
    free(invoiceLine->applianceName);
    free(invoiceLine);
}