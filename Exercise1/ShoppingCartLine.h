#ifndef CFROMJAVA_SHOPPINGCARTLINE_H
#define CFROMJAVA_SHOPPINGCARTLINE_H
#include "Appliance.h"

/*
 * Description: The ShoppingCartLine structure holds the information of a single appliance in a ShoppingCart,
 *              it has the appliance, and the amount of that appliance in the cart.
 */
typedef struct ShoppingCartLine{
    Appliance* appliance;
    int units;
}ShoppingCartLine;

//functions
ShoppingCartLine* createShoppingCartLine(Appliance* appliance, int units);
void destroyShoppingCartLine(ShoppingCartLine* shoppingCartLine);
#endif //CFROMJAVA_SHOPPINGCARTLINE_H