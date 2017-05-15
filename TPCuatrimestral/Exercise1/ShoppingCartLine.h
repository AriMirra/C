#ifndef CFROMJAVA_SHOPPINGCARTLINE_H
#define CFROMJAVA_SHOPPINGCARTLINE_H

typedef struct ShoppingCartLine{
    char* id;
    char* article;
    int* units;
}ShoppingCartLine;

//functions
ShoppingCartLine* createShoppingCartLine(char* id, char* article, int* units);

#endif //CFROMJAVA_SHOPPINGCARTLINE_H
