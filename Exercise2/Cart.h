#ifndef CFROMJAVA_SHOPPINGCART_H
#define CFROMJAVA_SHOPPINGCART_H

#include "Product.h"
#include "CartLine.h"

typedef struct Cart{
    CartLine** products;
    char* id;
    int total;
    int productsAmount;
    int capacity;
}Cart;

//functions
Cart* createCart(char* id);
void addProductToCart(Cart* cart, Product* product, int amount);
void removeProductFromCart(Cart *cart, int productID);
int isFull(Cart* cart);
void grow(Cart* cart);
int total(Cart* cart);
void emptyCart(Cart* cart);
void destroyCart(Cart* cart);
#endif //CFROMJAVA_SHOPPINGCART_H