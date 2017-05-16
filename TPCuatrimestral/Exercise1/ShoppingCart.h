#ifndef CFROMJAVA_SHOPPINGCART_H
#define CFROMJAVA_SHOPPINGCART_H

#include "Invoice.h"
#include "Appliance.h"

typedef struct ShoppingCart{
    Appliance** appliances;
    char* id;
    int* total;
    int appliancesAmount;
    int capacity;
}ShoppingCart;

//functions
ShoppingCart* createShoppingCart(ShoppingCart* cart, char* id);
Invoice* produceInvoice(ShoppingCart* cart, char* id, int* toPay);
void addAppliance(ShoppingCart* cart, Appliance* appliance);
int isFull(ShoppingCart *pCart);
void grow(ShoppingCart *cart);
int total(ShoppingCart* cart);

#endif //CFROMJAVA_SHOPPINGCART_H
