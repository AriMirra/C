#include <stdio.h>
#include <malloc.h>
#include "Database.h"
#include "../Util/ScanUtil.h"
/*
 * Description: lists the manufacturers in the database
 * Returns: void
 */
void listManufacturers(DataBase* database) {
    for(int i = 0; i < database->amountOfManufacturers; i++){
        Manufacturer* manufacturer = database->manufacturers[i];
        printf("%s\n" "Description: %s\n", manufacturer->name,manufacturer->description);
    }
}
/*
 * Description: lists the providers in the database
 * Returns: void
 */
void listProviders(DataBase* database) {
    for(int i = 0; i < database->amountOfProviders; i++){
        Provider* provider = database->providers[i];
        printf("%s\n" "Description: %s\n", provider->name,provider->description);
    }
}
/*
 * Description: lists the cameras in the database
 * Returns: void
 */
void listAppliances(DataBase* database) {
    for(int i = 0; i < database->amountOfProducts; i++){
        Product* product = database->products[i];
        printf("%s\n", product->name);
    }
}
/*
 * Description: asks for the details of a manufacturer, creates one and adds them to the database
 * Returns: void
 */
void addManufacturerMenu(DataBase* database){
    printf("Add Manufacturer:\n");
    printf("Name:\n");
    char* name = scanChar();
    printf("Description:\n");
    char* description = scanChar();
    printf("Address:\n");
    char* address = scanChar();
    printf("City:\n");
    char* city = scanChar();
    printf("Web:\n");
    char* web = scanChar();
    printf("Phone:\n");
    char* phone = scanChar();
    Manufacturer* manufacturer = createManufacturer(name, description, address, city, phone, web);
    addManufacturer(database, manufacturer);
    free(name);
    free(description);
    free(address);
    free(city);
    free(web);
    free(phone);
}

/*
 * Description: removes a manufacturer from the database
 * Returns: void
 */
void removeManufacturerMenu(DataBase *database){
    printf("Name of the manufacturer to remove:\n");
    if(removeManufacturer(database,scanChar())) printf("Manufacturer removed successfully\n");
    else printf("Manufacturer not found\n");
}
/*
 * Description: asks the user what he wants to do and calls a method accordingly
 * Returns: void
 */
void manufacturersMenu(DataBase *database){
    while(1) {
        printf("\n");
        printf("----------------------\n");
        printf("Manufacturers\n");
        printf("1. Add manufacturer\n");
        printf("2. Remove manufacturer\n");
        printf("3. List manufacturers\n");
        printf("-1. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                addManufacturerMenu(database);
                break;
            case 2:
                removeManufacturerMenu(database);
                break;
            case 3:
                listManufacturers(database);
                break;
            case -1:
                return;
            default:
                printf("Please enter a valid number\n");
        }
    }
}

/*
 * Description: asks the user what he wants to do and calls a method accordingly
 * Returns: void
 */
void addProviderMenu(DataBase *database){
    printf("Add provider:\n");
    printf("Name:\n");
    char* name = scanChar();
    printf("Description:\n");
    char* description = scanChar();
    printf("Address:\n");
    char* address = scanChar();
    printf("City:\n");
    char* city = scanChar();
    printf("Web:\n");
    char* web = scanChar();
    printf("Phone:\n");
    char* phone = scanChar();
    Provider* provider = createProvider(name, description, address, city, phone, web);
    addProvider(database, provider);
    free(name);
    free(description);
    free(address);
    free(city);
    free(web);
    free(phone);
}

void removeProviderMenu(DataBase* database){
    printf("Name of the provider to remove:\n");
    if(removeProvider(database,scanChar())) printf("Provider removed successfully\n");
    else printf("Provider not found\n");
}

void providersMenu(DataBase *database){
    while(1) {
        printf("\n");
        printf("----------------------\n");
        printf("Providers\n");
        printf("1. Add provider\n");
        printf("2. Remove provider\n");
        printf("3. List providers\n");
        printf("-1. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                addProviderMenu(database);
                break;
            case 2:
                removeProviderMenu(database);
                break;
            case 3:
                listProviders(database);
                break;
            case -1:
                return;
            default:
                printf("Please enter a valid number\n");
        }
    }
}

void addProductMenu(DataBase* database){
    printf("Add product:\n");
    //name
    printf("Name:\n");
    char* name = scanChar();
    printf("\n");
    //model
    printf("Product Type: (1) for camera, (2) for accessory\n");
    int productType = scanInt();
    printf("\n");
    //price
    printf("Price:\n");
    int price = scanInt();
    printf("\n");
    //id
    printf("id:\n");
    char* id = scanChar();
    printf("\n");
    //list, check and save manufacturer
    listManufacturers(database);
    char* manufacturer;
    while (1){
        printf("Name of the Manufacturer:\n");
        char* manufacturerName = scanChar();
        if(manufacturerExist(database, manufacturerName)){
            manufacturer = manufacturerName;
            break;
        }
    }
    printf("\n");
    //list, check and save provider
    listProviders(database);
    char* provider;
    while (1){
        printf("Name of the Provider:\n");
        char* providerName = scanChar();
        if(providerExist(database, providerName)){
            provider = providerName;
            break;
        }
    }
    printf("\n");
    //create appliance and add it to the database
    //Product* appliance = createProduct(name,model,price,id);
    //addProduct(database, appliance, manufacturer, provider);
    //free variables used
    free(name);
    //free(model);
    free(id);
    free(manufacturer);
    free(provider);
}

void removeApplianceMenu(DataBase* database) {
    printf("Name of the appliance to remove:\n");
    if(removeProduct(database, scanChar())) printf("Appliance removed successfully\n");
    else printf("Appliance not found\n");
}

void appliancesMenu(DataBase* database){
    while(1) {
        printf("\n");
        printf("----------------------\n");
        printf("Appliances:\n");
        printf("1. Add appliance\n");
        printf("2. Remove appliance\n");
        printf("3. List appliances\n");
        printf("-1. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                addProductMenu(database);
                break;
            case 2:
                removeApplianceMenu(database);
                break;
            case 3:
                listAppliances(database);
                break;
            case -1:
                return;
            default:
                printf("Please enter a valid number\n");
        }
    }
}

void adminMenu(DataBase* database){
    while(1) {
        printf("\n");
        printf("********************\n");
        printf("Admin Menu\n");
        printf("1. Manufacturers\n");
        printf("2. Providers\n");
        printf("3. Appliances\n");
        printf("-1. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                manufacturersMenu(database);
                break;
            case 2:
                providersMenu(database);
                break;
            case 3:
                appliancesMenu(database);
                break;
            case -1:
                return;
            default:
                printf("Please enter a valid number\n");
        }
    }
}