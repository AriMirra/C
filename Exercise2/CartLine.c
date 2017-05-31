#include "CartLine.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * Description: creates a CartLine
 * Returns: CartLine pointer
 */
CartLine* createCartLine(Product* product, int units){
    CartLine* result = malloc(sizeof(CartLine));
    result->product = malloc(sizeof(Product));

    result->product = product;
    result->units = units;
    return result;
}

/*
 * Description: Deallocates memory assigned for a CartLine and all its components
 * Return: void
 */
void destroyCartLine(CartLine* cartLine){
    destroyProduct(cartLine->product);
    free(cartLine);
}