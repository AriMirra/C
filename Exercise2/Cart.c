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
    result->products = malloc(sizeof(Product*)*result->capacity);

    result->id = id;
    result->productsAmount = 0;
    return result;
}

/*
 * Description: adds an Appliance to the cart
 * Returns: void
 */
    void addProductToCart(Cart *cart, Product *product, int amount){
    if (isFull(cart)) grow(cart);
    cart->products[cart->productsAmount] = createCartLine(product,amount);
    cart->productsAmount++;
}

/*
 * Description: removes a product from the cart
 * Returns: void
 */
void removeProductFromCart(Cart *cart, int productID){
    int applianceFoundAndRemoved = 0;
    for (int i = 0; i < cart->productsAmount; i++){
        if(cart->products[i]->product->productID == productID){
            CartLine* result = cart->products[i];
            for (int j = i; j < cart->productsAmount; j++){
                cart->products[j] = cart->products[j+1];
            }
            applianceFoundAndRemoved = 1;
            break;
        }
    }
    if (applianceFoundAndRemoved) cart->productsAmount--;
}

/*
 * Description: checks if a cart is full
 * Returns: 1 if the cart is full, 0 if it's not
 */
int isFull(Cart* cart){
    if(cart->productsAmount == sizeof(cart->products)) return 1;
    return 0;
}

/*
 * Description: expands the cart capacity
 * Returns: void
 */
void grow(Cart* cart) {
    cart->capacity = cart->capacity*2;
    cart->products = realloc(cart->products, sizeof(Product*)*cart->capacity);
}

/*
 * Description: sums the amount of money of every appliance inside the cart
 * Returns: the total amount of money from the appliances in the cart
 */
int total(Cart* cart){
    int result = 0;
    for(int i = 0;i< cart->productsAmount;i++){
        result += ((cart->products[i]->product->price)*cart->products[i]->units);
    }
    return result;
}

/*
 * Description: empties the cart, deletes all CartLines inside
 * Returns: void
 */
void emptyCart(Cart* cart) {
    int j = cart->productsAmount;
    for (int i = 0; i < j; i++) {
        destroyCartLine(cart->products[i]);
        cart->productsAmount--;
    }
}

/*
 * Description: Deallocates memory assigned for a Cart and all its components
 * Return: void
 */
void destroyCart(Cart* cart){
    emptyCart(cart);
    free(cart->id);
}