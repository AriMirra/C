#ifndef CFROMJAVA_SHOPPINGCART_H
#define CFROMJAVA_SHOPPINGCART_H

#include "Invoice.h"
#include "Appliance.h"
#include "ShoppingCartLine.h"

typedef struct ShoppingCart{
    ShoppingCartLine** appliances;
    char* id;
    int total;
    int appliancesAmount;
    int capacity;
}ShoppingCart;

//functions
ShoppingCart* createShoppingCart(char* id);
Invoice* produceInvoice(ShoppingCart* cart, char* id, int* toPay);
void addApplianceToCart(ShoppingCart* cart, Appliance* appliance, int amount);
void removeApplianceFromCart(ShoppingCart* cart, char* applianceName);
int isFull(ShoppingCart *pCart);
void grow(ShoppingCart *cart);
int total(ShoppingCart* cart);
void destroyShoppingCart(ShoppingCart* shoppingCart);

#endif //CFROMJAVA_SHOPPINGCART_H
