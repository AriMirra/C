#ifndef CFROMJAVA_SHOPPINGCART_H
#define CFROMJAVA_SHOPPINGCART_H

#include "Invoice.h"

typedef struct ShoppingCart{
    char* id;
    float* total;
}ShoppingCart;

//functions
ShoppingCart* createShoppingCart(char* id, float* total);
Invoice* produceInvoice(char* id, float* toPay);


#endif //CFROMJAVA_SHOPPINGCART_H
