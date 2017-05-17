#ifndef CFROMJAVA_SHOPPINGCARTLINE_H
#define CFROMJAVA_SHOPPINGCARTLINE_H

#include "Appliance.h"

typedef struct ShoppingCartLine{
    Appliance* appliance;
    int units;
}ShoppingCartLine;

//functions
ShoppingCartLine* createShoppingCartLine(Appliance* appliance, int units);

#endif //CFROMJAVA_SHOPPINGCARTLINE_H
