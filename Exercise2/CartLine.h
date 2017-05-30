#ifndef CFROMJAVA_SHOPPINGCARTLINE_H
#define CFROMJAVA_SHOPPINGCARTLINE_H
#include "Appliance.h"

typedef struct CartLine{
    Appliance* appliance;
    int units;
}CartLine;

//functions
CartLine* createShoppingCartLine(Appliance* appliance, int units);
void destroyShoppingCartLine(ShoppingCartLine* shoppingCartLine);
#endif //CFROMJAVA_SHOPPINGCARTLINE_H