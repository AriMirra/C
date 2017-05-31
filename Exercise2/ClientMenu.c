#include <stdio.h>
#include "Database.h"
#include "Cart.h"
#include "Invoice.h"
#include "../Util/ScanUtil.h"
DataBase* setup();
void addApplianceToCartMenu(DataBase* database, Cart* cart) {
    printf("Items available: \n");
    for (int i = 0; i < database->amountOfProducts; i++){
        Product* product = database->products[i];
        printf("%s\nPrice: %d \n",product->name, product->price);
        printf("ID: %d\n\n", product->productID);
    }
    printf("Which one do you want to buy? Enter the ID: \n");
    IDofAppliance:
    {
        int productID = scanInt();
        if (productExist(database, productID)) {
            printf("How many %s would you like to buy?: \n", getProduct(database,productID)->name);
            int amount = scanInt();
            addApplianceToCart(cart, getProduct(database, productID), amount);
        } else {
            printf("Please enter a valid ID: \n");
            goto IDofAppliance;
        }
    }
}

void checkout(Cart *cart) {
    if (cart->productsAmount > 0) {
        Invoice *invoice = createInvoice(cart);
        printf("Appliance name   price    amount\n");
        for (int i = 0; i < invoice->amountOfLines; i++) {
            printf("%s    %d    %d\n", invoice->invoiceLines[i]->applianceName,
                   invoice->invoiceLines[i]->priceOfAppliance, invoice->invoiceLines[i]->units);
        }
        printf("******************\n");
        printf("Total: $%d\n", invoice->toPay);
        printf("thank you for using our system\n\n");
        emptyCart(cart);
        return;
    }else printf("You have no items in the cart");
}

void ManageCartMenu(Cart *cart) {
    if (cart->productsAmount > 0) {
        printf("You have currently the following items in your cart:\n");
        for (int i = 0; i < cart->productsAmount; i++) {
            printf("%d %s(s),  ID:%d \n", cart->products[i]->units,
                   cart->products[i]->product->name,cart->products[i]->product->productID);
        }
        printf("Would you like to remove any appliance? type 1 if you do, 0 if you don't\n");
        int option = scanInt();
        if (option == 1) {
            printf("Enter the ID of the appliance you want to remove:\n");
            removeApplianceFromCart(cart, scanInt());
            printf("\n");
        } else return;
    }else printf("You have no items in your cart");
}

void clientMenu(DataBase* database){
    Cart* cart = createCart("Cart");
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
                destroyCart(cart);
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}