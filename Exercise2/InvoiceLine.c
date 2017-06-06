#include <stdlib.h>
#include <string.h>
#include "InvoiceLine.h"
/*
 * Description: creates an InvoiceLine
 * Returns: a pointer to the InvoiceLine created
 */
InvoiceLine* createInvoiceLine(CartLine* cartLine){
    InvoiceLine* result = malloc(sizeof(InvoiceLine));
    result->productName = malloc(sizeof(char)*strlen(cartLine->product->name)+1);
    strcpy(result->productName, cartLine->product->name);
    result->units = cartLine->units;
    result->priceOfProduct= cartLine->product->price;
    return result;
}

/*
 * Description: Deallocates memory assigned for an InvoiceLine and all its components
 * Return: void
 */
void destroyInvoiceLine(InvoiceLine* invoiceLine){
    free(invoiceLine->productName);
    free(invoiceLine);
}