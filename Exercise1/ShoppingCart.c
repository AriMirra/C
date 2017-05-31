#include "ShoppingCart.h"
/*
 * Description: Contains the functions related to the ShoppingCart structure
 */

/*
 * Description: creates a ShoppingCart
 * Returns: the ShoppingCart created
 */
ShoppingCart* createShoppingCart(char* id){
    ShoppingCart* result = malloc(sizeof(ShoppingCart));
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
void addApplianceToCart(ShoppingCart *cart, Appliance *appliance, int amount){
    if (isFull(cart)) grow(cart);
    cart->appliances[cart->appliancesAmount] = createShoppingCartLine(appliance,amount);
    cart->appliancesAmount++;
}

/*
 * Description: removes an Appliance from the cart
 * Returns: void
 */
void removeApplianceFromCart(ShoppingCart *cart, char* applianceName){
    int applianceFoundAndRemoved = 0;
    for (int i = 0; i < cart->appliancesAmount; i++){
        if(strcmp(cart->appliances[i]->appliance->name, applianceName) == 0){
            ShoppingCartLine* result = cart->appliances[i];
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
int isFull(ShoppingCart* cart){
    if(cart->appliancesAmount == sizeof(cart->appliances)) return 1;
    return 0;
}

/*
 * Description: expands the ShoppingCart capacity
 * Returns: void
 */
void grow(ShoppingCart* cart) {
    cart->capacity = cart->capacity*2;
    cart->appliances = realloc(cart->appliances, sizeof(Appliance*)*cart->capacity);
}

/*
 * Description: sums the amount of money of every appliance inside the cart
 * Returns: the total amount of money from the appliances in the cart
 */
int total(ShoppingCart* cart){
    int result = 0;
    for(int i = 0;i< cart->appliancesAmount;i++){
        result += ((cart->appliances[i]->appliance->price)*cart->appliances[i]->units);
    }
    return result;
}

/*
 * Description: empties the cart, deletes all ShoppingCartLine inside
 * Returns: void
 */
void emptyShoppingCart(ShoppingCart* cart) {
    int j = cart->appliancesAmount;
    for (int i = 0; i < j; i++) {
        destroyShoppingCartLine(cart->appliances[i]);
        cart->appliancesAmount--;
    }
}

/*
 * Description: Deallocates memory assigned for a ShoppingCart and all its components
 * Return: void
 */
void destroyShoppingCart(ShoppingCart* shoppingCart){
    emptyShoppingCart(shoppingCart);
    free(shoppingCart->id);
}