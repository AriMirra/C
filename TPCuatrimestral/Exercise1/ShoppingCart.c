#include "ShoppingCart.h"

ShoppingCart* createShoppingCart(char* id){
    ShoppingCart* result = malloc(sizeof(ShoppingCart));
    result->id = malloc(sizeof(char)*strlen(id));
    result->capacity = 10;
    result->appliances = malloc(sizeof(Appliance*)*result->capacity);

    result->id = id;
    result->appliancesAmount = 0;
    return result;
}

Invoice* produceInvoice(ShoppingCart* cart, char* id, int* toPay){
    Invoice* result = createInvoice(cart);
    return result;
}

void addAppliance(ShoppingCart* cart, Appliance* appliance, int amount){
    if (isFull(cart)) grow(cart);
    cart->appliances[cart->appliancesAmount] = createShoppingCartLine(appliance,amount);
}

int isFull(ShoppingCart* cart) {
    if(cart->appliancesAmount == sizeof(cart->appliances)) return 1;
    return 0;
}

void grow(ShoppingCart* cart) {
    cart->capacity = cart->capacity*2;
    cart->appliances = realloc(cart->appliances, sizeof(Appliance*)*cart->capacity);
}

int total(ShoppingCart* cart){
    int result = 0;
    for(int i = 0;i< cart->appliancesAmount;i++){
        result += cart->appliances[i]->appliance->price;
    }
    return result;
}