#ifndef CFROMJAVA_SHOPPINGCART_H
#define CFROMJAVA_SHOPPINGCART_H
#include "Appliance.h"
#include "ShoppingCartLine.h"

/*
 * Description: The ShoppingCart structure has the information of a shopping cart and it's details.
 */
typedef struct ShoppingCart{
    ShoppingCartLine** appliances;
    char* id;
    int total;
    int appliancesAmount;
    int capacity;
}ShoppingCart;

//functions
ShoppingCart* createShoppingCart(char* id);
void addApplianceToCart(ShoppingCart* cart, Appliance* appliance, int amount);
void removeApplianceFromCart(ShoppingCart* cart, char* applianceName);
int isFull(ShoppingCart *pCart);
void grow(ShoppingCart *cart);
int total(ShoppingCart* cart);
void emptyShoppingCart(ShoppingCart* cart);
void destroyShoppingCart(ShoppingCart* shoppingCart);
#endif //CFROMJAVA_SHOPPINGCART_H