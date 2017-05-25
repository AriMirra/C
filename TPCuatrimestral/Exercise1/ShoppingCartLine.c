#include "ShoppingCartLine.h"

ShoppingCartLine* createShoppingCartLine(Appliance* appliance, int units){
    ShoppingCartLine* result = malloc(sizeof(ShoppingCartLine));
    result->appliance = malloc(sizeof(Appliance));

    result->appliance = appliance;
    result->units = units;
    return result;
}

void destroyShoppingCartLine(ShoppingCartLine* shoppingCartLine){
    destroyAppliance(shoppingCartLine->appliance);
    free(shoppingCartLine);
}
