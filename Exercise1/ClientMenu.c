#include <stdlib.h>
#include <stdio.h>
#include "Database.h"
#include "ShoppingCart.h"
#include "Invoice.h"
#include "../Util/ScanUtil.h"

void addApplianceToCartMenu(DataBase *database, ShoppingCart *cart) {
    printf("Items available: \n");

}

void clientMenu(DataBase* database){
    ShoppingCart* cart = createShoppingCart("cart n1");
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
                ManageCartMenu(database, cart);
                break;
            case 3:
                checkout(database, cart);
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}
