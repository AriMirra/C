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
        printf("%s\n" "Description: %s\n ID: %d\n\n",
               manufacturer->name,manufacturer->description, manufacturer->manufacturerID);
    }
}
/*
 * Description: lists the providers in the database
 * Returns: void
 */
void listProviders(DataBase* database) {
    for(int i = 0; i < database->amountOfProviders; i++){
        Provider* provider = database->providers[i];
        printf("%s\n" "Description: %s\n ID: %d\n\n", provider->name,provider->description, provider->providerID);
    }
}
/*
 * Description: lists the Products in the database
 * Returns: void
 */
void listProducts(DataBase* database) {
    for(int i = 0; i < database->amountOfProducts; i++){
        Product* product = database->products[i];
        if (product->productType == CAMERA) printf("camera: %s\n", product->name);
         else printf("accessory: %s\n", product->name);
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
    printf("\n");
    printf("Description:\n");
    char* description = scanChar();
    printf("\n");
    printf("Address:\n");
    char* address = scanChar();
    printf("\n");
    printf("City:\n");
    char* city = scanChar();
    printf("\n");
    printf("Country:\n");
    char* country = scanChar();
    printf("\n");
    printf("Phone:\n");
    char* phone = scanChar();
    printf("\n");
    Manufacturer* manufacturer = createManufacturer(name, description, address, city, phone, country);
    addManufacturer(database, manufacturer);
    free(name);
    free(description);
    free(address);
    free(city);
    free(country);
    free(phone);
}

/*
 * Description: removes a manufacturer from the database
 * Returns: void
 */
void removeManufacturerMenu(DataBase *database){
    printf("Manufacturers in the system: :");
    listManufacturers(database);
    printf("\n ID of the manufacturer to remove:\n");
    if(removeManufacturer(database,scanInt())) printf("Manufacturer removed successfully\n");
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
    printf("\n");
    printf("Description:\n");
    char* description = scanChar();
    printf("\n");
    printf("Address:\n");
    char* address = scanChar();
    printf("\n");
    printf("City:\n");
    char* city = scanChar();
    printf("\n");
    printf("Country:\n");
    char* country = scanChar();
    printf("\n");
    printf("Phone:\n");
    char* phone = scanChar();
    printf("\n");
    Provider* provider = createProvider(name, description, address, city, phone, country);
    addProvider(database, provider);
    free(name);
    free(description);
    free(address);
    free(city);
    free(country);
    free(phone);
}

void removeProviderMenu(DataBase* database){
    printf("Providers in the system: :");
    listProviders(database);
    printf("\n ID of the provider to remove:\n");
    if(removeProvider(database,scanInt())) printf("Provider removed successfully\n");
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
    //price
    printf("Price:\n");
    int price = scanInt();
    printf("\n");
    //type
    productTypeRequest:
    printf("Product Type: (1) for camera, (2) for accessory\n");
    int productTypeEntered = scanInt();
    ProductType productType;
    if (productTypeEntered == 1) {
        productType = CAMERA;
    }
    else if (productTypeEntered == 0) {
        productType = ACCESSORY;
    }
    else goto productTypeRequest;
    printf("\n");
    //list, check and save manufacturer
    listManufacturers(database);
    int manufacturer;
    while (1){
        printf("ID of the Manufacturer:\n");
        int manufacturerID = scanInt();
        if(manufacturerExist(database, manufacturerID)){
            manufacturer = manufacturerID;
            break;
        }
    }
    printf("\n");
    //list, check and save provider
    listProviders(database);
    int provider;
    while (1){
        printf("Name of the Provider:\n");
        int providerID = scanInt();
        if(providerExist(database, providerID)){
            provider = providerID;
            break;
        }
    }
    printf("\n");
    //create the product and add it to the database
    Product* product = createProduct(name,productType,manufacturer,provider,nextProductID(database),price);
    addProduct(database, product, manufacturer, provider);
    //free variables used
    free(name);
}

void removeProductMenu(DataBase* database) {
    printf("Products in the system: \n");
    listProducts(database);
    printf("ID of the product you want to remove:\n");
    if(removeProduct(database, scanInt())) printf("Product removed successfully\n");
    else printf("Product not found\n");
}

void productsMenu(DataBase* database){
    while(1) {
        printf("\n");
        printf("----------------------\n");
        printf("Products:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. List products\n");
        printf("-1. Exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                addProductMenu(database);
                break;
            case 2:
                removeProductMenu(database);
                break;
            case 3:
                listProducts(database);
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
        printf("3. Products\n");
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
                productsMenu(database);
                break;
            case -1:
                return;
            default:
                printf("Please enter a valid number\n");
        }
    }
}