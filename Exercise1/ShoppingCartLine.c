#include "ShoppingCartLine.h"
/*
 * Description: creates a ShoppingCartLine
 * Returns: the ShoppingCartLine created
 */
ShoppingCartLine* createShoppingCartLine(Appliance* appliance, int units){
    ShoppingCartLine* result = malloc(sizeof(ShoppingCartLine));
    result->appliance = malloc(sizeof(Appliance));

    result->appliance = appliance;
    result->units = units;
    return result;
}

/*
 * Description: Deallocates memory assigned for a ShoppingCartLine and all its components
 * Return: void
 */
void destroyShoppingCartLine(ShoppingCartLine* shoppingCartLine){
    destroyAppliance(shoppingCartLine->appliance);
    free(shoppingCartLine);
}