#include <stdio.h>
#include "Database.h"
#include "ShoppingCart.h"
#include "Invoice.h"
#include "../Util/ScanUtil.h"
DataBase* setup();
void addApplianceToCartMenu(DataBase* database, ShoppingCart* cart) {
    printf("Items available: \n");
    for (int i = 0; i < database->amountOfAppliances; i++){
        Appliance* appliance = database->appliances[i];
        printf("%s\nPrice: %d \n",appliance->name, appliance->price);
        printf("Manufacturer: %s\n\n", appliance->manufacturerName);
    }
    printf("Which one do you want to buy? Enter the name: \n");
    nameOfAppliance:
    {
        char *applianceName = scanChar();
        if (applianceExist(database, applianceName)) {
            printf("How many %s would you like to buy?: \n", applianceName);
            int amount = scanInt();
            addApplianceToCart(cart, getAppliance(database, applianceName), amount);
        } else {
            printf("Please enter a valid name: \n");
            goto nameOfAppliance;
        }
    }
}

void checkout(ShoppingCart *cart) {
    if (cart->appliancesAmount > 0) {
        Invoice *invoice = createInvoice(cart);
        printf("Appliance name   price    amount\n");
        for (int i = 0; i < invoice->amountOfLines; i++) {
            printf("%s    %d    %d\n", invoice->invoiceLines[i]->applianceName,
                   invoice->invoiceLines[i]->priceOfAppliance, invoice->invoiceLines[i]->units);
        }
        printf("******************\n");
        printf("Total: $%d\n", invoice->toPay);
        printf("thank you for using our system\n\n");
        emptyShoppingCart(cart);
        return;
    }else printf("You have no items in the cart");
}

void ManageCartMenu(ShoppingCart *cart) {
    if (cart->appliancesAmount > 0) {
        printf("You have currently the following items in your cart:\n");
        for (int i = 0; i < cart->appliancesAmount; i++) {
            printf("%d %s(s)\n", cart->appliances[i]->units, cart->appliances[i]->appliance->name);
        }
        printf("Would you like to remove any appliance? type 1 if you do, 0 if you don't\n");
        int option = scanInt();
        if (option == 1) {
            printf("Enter the name of the appliance you want to remove:\n");
            removeApplianceFromCart(cart, scanChar());
            printf("\n");
        } else return;
    }else printf("You have no items in your cart");
}

void clientMenu(DataBase* database){
    ShoppingCart* cart = createShoppingCart("Cart");
    while(1) {
        printf("\n");
        printf("********************\n");
        printf("Client Menu\n");
        printf("1. Buy Appliances\n");
        printf("2. Manage cart\n");
        printf("3. Checkout\n");
        printf("-1. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                addApplianceToCartMenu(database, cart);
                break;
            case 2:
                ManageCartMenu(cart);
                break;
            case 3:
                checkout(cart);
                break;
            case -1:
                destroyShoppingCart(cart);
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}
