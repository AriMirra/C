//
// Created by arimi on 14-May-17.
//

#ifndef CFROMJAVA_SHOPPINGCART_H
#define CFROMJAVA_SHOPPINGCART_H

#include "Invoice.h"

typedef struct shoppingCart ShoppingCart;

struct shoppingCart{
    char* id;
    float* total;
};

//functions
ShoppingCart* createShoppingCart(char* id, float* total);
Invoice* produceInvoice(char* id, float* toPay);


#endif //CFROMJAVA_SHOPPINGCART_H
