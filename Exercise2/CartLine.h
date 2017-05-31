#ifndef CFROMJAVA_SHOPPINGCARTLINE_H
#define CFROMJAVA_SHOPPINGCARTLINE_H
#include "Product.h"

typedef struct CartLine{
    Product* product;
    int units;
}CartLine;

//functions
CartLine* createCartLine(Product* product, int units);
void destroyCartLine(CartLine* cartLine);
#endif //CFROMJAVA_SHOPPINGCARTLINE_H