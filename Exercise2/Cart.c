#include "Cart.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Description: creates a cart
 * Returns: the cart created
 */
Cart* createCart(char* id){
    Cart* result = malloc(sizeof(Cart));
    result->id = malloc(sizeof(char)*strlen(id)+1);
    result->capacity = 10;
    result->appliances = malloc(sizeof(Appliance*)*result->capacity);

    result->id = id;
    result->appliancesAmount = 0;
    return result;
}

/*
 * Description: adds an Appliance to the cart
 * Returns: void
 */
void addApplianceToCart(Cart *cart, Appliance *appliance, int amount){
    if (isFull(cart)) grow(cart);
    cart->appliances[cart->appliancesAmount] = createCartLine(appliance,amount);
    cart->appliancesAmount++;
}

/*
 * Description: removes an Appliance from the cart
 * Returns: void
 */
void removeApplianceFromCart(Cart *cart, char* applianceName){
    int applianceFoundAndRemoved = 0;
    for (int i = 0; i < cart->appliancesAmount; i++){
        if(strcmp(cart->appliances[i]->appliance->name, applianceName) == 0){
            CartLine* result = cart->appliances[i];
            for (int j = i; j < cart->appliancesAmount; j++){
                cart->appliances[j] = cart->appliances[j+1];
            }
            applianceFoundAndRemoved = 1;
            break;
        }
    }
    if (applianceFoundAndRemoved) cart->appliancesAmount--;
}

/*
 * Description: checks if a cart is full
 * Returns: 1 if the cart is full, 0 if it's not
 */
int isFull(Cart* cart){
    if(cart->appliancesAmount == sizeof(cart->appliances)) return 1;
    return 0;
}

/*
 * Description: expands the cart capacity
 * Returns: void
 */
void grow(Cart* cart) {
    cart->capacity = cart->capacity*2;
    cart->appliances = realloc(cart->appliances, sizeof(Appliance*)*cart->capacity);
}

/*
 * Description: sums the amount of money of every appliance inside the cart
 * Returns: the total amount of money from the appliances in the cart
 */
int total(Cart* cart){
    int result = 0;
    for(int i = 0;i< cart->appliancesAmount;i++){
        result += ((cart->appliances[i]->appliance->price)*cart->appliances[i]->units);
    }
    return result;
}

/*
 * Description: empties the cart, deletes all CartLines inside
 * Returns: void
 */
void emptyCart(Cart* cart) {
    int j = cart->appliancesAmount;
    for (int i = 0; i < j; i++) {
        destroyCartLine(cart->appliances[i]);
        cart->appliancesAmount--;
    }
}

/*
 * Description: Deallocates memory assigned for a Cart and all its components
 * Return: void
 */
void destroyCart(Cart* cart){
    emptyCart(shoppingCart);
    free(shoppingCart->id);
}