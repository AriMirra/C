#include "CartLine.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * Description: creates a ShoppingCartLine
 * Returns: the ShoppingCartLine created
 */
CartLine* createCartLine(Appliance* appliance, int units){
    CartLine* result = malloc(sizeof(CartLine));
    result->appliance = malloc(sizeof(Appliance));

    result->appliance = appliance;
    result->units = units;
    return result;
}

/*
 * Description: Deallocates memory assigned for a CartLine and all its components
 * Return: void
 */
void destroyCartLine(CartLine* cartLine){
    destroyAppliance(cartLine->appliance);
    free(cartLine);
}