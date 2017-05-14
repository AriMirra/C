//
// Created by arimi on 14-May-17.
//

#ifndef CFROMJAVA_SHOPPINGCARTLINE_H
#define CFROMJAVA_SHOPPINGCARTLINE_H

typedef struct shoppingCartLine ShoppingCartLine;

struct shoppingCartLine{
    char* id;
    char* article;
    int* units;
};

//functions
ShoppingCartLine* createShoppingCartLine(char* id, char* article, int* units);

#endif //CFROMJAVA_SHOPPINGCARTLINE_H
