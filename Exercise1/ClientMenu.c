#include <stdlib.h>
#include <stdio.h>
#include "Database.h"
#include "ShoppingCart.h"
#include "Invoice.h"
#include "../Util/ScanUtil.h"

void addApplianceToCartMenu(DataBase* database, ShoppingCart* cart) {
    printf("Items available: \n");
    for (int i = 0; i < database->amountOfAppliances; i++){
        Appliance* appliance = database->appliances[i];
        printf("%s\nPrice: %d \n",appliance->name, appliance->price);
        printf("Manufacturer: %s\n\n", appliance->manufacturerName);
    }
    printf("Which one do you want to buy? Enter the name: \n");
    char* applianceName = scanChar();
    if (applianceExist(database,applianceName)){
        printf("how many %s would you like to buy?: \n", applianceName);
        int amount = scanInt();
        addApplianceToCart(cart,getAppliance(database,applianceName),amount);
    }
}

void checkout(ShoppingCart *cart) {
    Invoice* invoice = createInvoice(cart);
    printf("Appliance name:   amount");
    for(int i = 0; i < invoice->amountOfLines; i++){
        printf("%s:   %d\n",invoice->invoiceLines[i]->applianceName,invoice->invoiceLines[i]->priceOfAppliance);
    }
    printf("******************\n");
    printf("Total: $%d\n",invoice->toPay);
}

void ManageCartMenu(ShoppingCart *cart) {
    printf("You have currently the following items in your cart:\n");
    for (int i = 0; i < cart->appliancesAmount; i++){
        printf("%d %s(s)\n", cart->appliances[i]->units, cart->appliances[i]->appliance->name);
    }
    printf("Would you like to remove any appliance? type 1 if you do, 0 to checkout\n");
    int option = scanInt();
    if (option){
        printf("Enter the name of the appliance you want to remove:\n");
        removeApplianceFromCart(cart,scanChar());
    }else{
        checkout(cart);
    }
}

void clientMenu(DataBase* database){
    ShoppingCart* cart = createShoppingCart("cart n1");
    while(1) {
        printf("\n");
        printf("********************\n");
        printf("Client Menu\n");
        printf("1. Buy Appliances\n");
        printf("2. Manage cart and checkout\n");;
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
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}
