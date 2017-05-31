#ifndef CFROMJAVA_SHOPPINGCART_H
#define CFROMJAVA_SHOPPINGCART_H

#include "Appliance.h"
#include "CartLine.h"

typedef struct Cart{
    CartLine** appliances;
    char* id;
    int total;
    int appliancesAmount;
    int capacity;
}Cart;

//functions
Cart* createCart(char* id);
void addApplianceToCart(Cart* cart, Appliance* appliance, int amount);
void removeApplianceFromCart(Cart* cart, char* applianceName);
int isFull(Cart* cart);
void grow(Cart* cart);
int total(Cart* cart);
void emptyCart(Cart* cart);
void destroyCart(Cart* cart);
#endif //CFROMJAVA_SHOPPINGCART_H