#include <stdio.h>
#include <malloc.h>
#include "Database.h"
#include "../Util/ScanUtil.h"

void listManufacturers(DataBase* database) {
    for(int i = 0; i < database->amountOfManufacturers; i++){
        Manufacturer* manufacturer = database->manufacturers[i];
        printf("%s\n" "Description: %s\n", manufacturer->name,manufacturer->description);
    }
}

void listProviders(DataBase* database) {
    for(int i = 0; i < database->amountOfProviders; i++){
        Provider* provider = database->providers[i];
        printf("%s\n" "Description: %s\n", provider->name,provider->description);
    }
}

void listAppliances(DataBase* database) {
    for(int i = 0; i < database->amountOfAppliances; i++){
        Appliance* appliance = database->appliances[i];
        printf("%s\n", appliance->name);
    }
}

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


void removeManufacturerMenu(DataBase *database){
    printf("Name of the manufacturer to remove:\n");
    if(removeManufacturer(database,scanChar())) printf("Manufacturer removed successfully\n");
    else printf("Manufacturer not found\n");
}

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

void addApplianceMenu(DataBase* database){
    printf("Add appliance:\n");
    //name
    printf("Name:\n");
    char* name = scanChar();
    printf("\n");
    //model
    printf("Model:\n");
    char* model = scanChar();
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
    int invalidManufacturer = 1;
    char* manufacturer;
    while (invalidManufacturer){
        printf("Manufacturer:\n");
        char* manufacturerName = scanChar();
        for(int i = 0; i < database->amountOfManufacturers; i++){
            if(strcmp(manufacturerName,database->manufacturers[i]->name)){
                invalidManufacturer = 0;
                manufacturer = manufacturerName;
                break;
            }
        }
    }
    printf("\n");
    //list, check and save provider
    listProviders(database);
    int invalidProvider = 1;
    char* provider;
    while (invalidProvider){
        printf("Provider:\n");
        char* providerName = scanChar();
        for(int i = 0; i < database->amountOfProviders; i++){
            if(strcmp(providerName,database->providers[i]->name)){
                invalidProvider = 0;
                provider = providerName;
                break;
            }
        }
    }
    printf("\n");
    //create appliance and add it to the database
    Appliance* appliance = createAppliance(name,model,price,id);
    addAppliance(database, appliance,manufacturer,provider);
    //free variables used
    free(name);
    free(model);
    free(id);
    free(manufacturer);
    free(provider);
}

void removeApplianceMenu(DataBase* database) {
    printf("Name of the appliance to remove:\n");
    if(removeAppliance(database,scanChar())) printf("Appliance removed successfully\n");
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
                addApplianceMenu(database);
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