#include "DataBase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Description: creates an empty DataBase
 * Return: the DataBase created
 */
DataBase* createDataBase(){
    DataBase* result = malloc(sizeof(DataBase));
    int initialSize = 10;
    result->manufacturers = malloc(sizeof(Manufacturer*) * initialSize);
    result->manufacturerMaxCapacity = initialSize;
    result->providers = malloc(sizeof(Provider*) * initialSize);
    result->providerMaxCapacity = initialSize;
    result->products = malloc(sizeof(Product*) * initialSize);
    result->productMaxCapacity = initialSize;
    result->amountOfManufacturers = 0;
    result->amountOfProviders = 0;
    result->amountOfProducts = 0;
    return result;
}

/*
 * Description: searches a Manufacturer on the DataBase and returns it if found
 * Return: Manufacturer pointer
 */
Manufacturer* getManufacturer(DataBase* database,char* name){
    for(int i = 0; i < database->amountOfManufacturers; i++){
        if(strcmp(name,database->manufacturers[i]->name) == 0)
            return database->manufacturers[i];
    }
    return NULL;
}

/*
 * Description: searches a Provider on the DataBase and returns it if found
 * Return: Provider pointer
 */
Provider* getProvider(DataBase* database,char* name){
    for(int i = 0; i < database->amountOfProviders; i++){
            if(strcmp(name,database->providers[i]->name) == 0)
                return database->providers[i];
    }
    return NULL;
}

/*
 * Description: searches a Appliance on the DataBase and returns it if found
 * Return: Product pointer
 */
Product* getProduct(DataBase *database, char *name){
    for(int i = 0; i < database->amountOfProducts; i++){
        if(strcmp(name,database->products[i]->name) == 0)
            return database->products[i];
    }
    return NULL;
}

/*
 * Description: expands the Manufacturer array inside the DataBase
 * Return: void
 */
void growManufacturer(DataBase* database){
    database->manufacturers = realloc(database->manufacturers, sizeof(Manufacturer*) * database->manufacturerMaxCapacity * 2);
    database->manufacturerMaxCapacity *= 2;
}

/*
 * Description: expands the Provider array inside the DataBase
 * Return: void
 */
void growProvider(DataBase* database){
    database->providers = realloc(database->providers, sizeof(Provider*) * database->providerMaxCapacity * 2);
    database->providerMaxCapacity *= 2;
}

/*
 * Description: expands the Appliance array inside the DataBase
 * Return: void
 */
void growProduct(DataBase* database){
    database->products = realloc(database->products, sizeof(Product*) * database->productMaxCapacity * 2);
    database->productMaxCapacity *= 2;
}

/*
 * Description: adds a Manufacturer to the DataBase
 * Return: void
 */
void addManufacturer(DataBase* database, Manufacturer* manufacturer){
    if(database->amountOfManufacturers != database->manufacturerMaxCapacity){
        database->manufacturers[database->amountOfManufacturers] = manufacturer;
        database->amountOfManufacturers++;
    }else{
        growManufacturer(database);
        addManufacturer(database,manufacturer);
    }
}

/*
 * Description: adds a Provider to the DataBase
 * Return: void
 */
void addProvider(DataBase* database, Provider* provider){
    if(database->amountOfProviders != database->providerMaxCapacity){
        database->providers[database->amountOfProviders] = provider;
        database->amountOfProviders++;
    }else{
        growProvider(database);
        addProvider(database,provider);
    }
}

/*
 * Description: adds an Appliance to the DataBase and sets it's manufacturer and provider
 * Return: void
 */
void addProduct(DataBase *database, Product *product, int manufacturerID, int providerID){
    if(database->amountOfProducts != database->productMaxCapacity){
        setManufacturerID(product,manufacturerID);
        setProviderID(product, providerID);
        database->products[database->amountOfProducts] = product;
        database->amountOfProducts++;
    }else{
        growProduct(database);
        //addProduct(database, appliance, manufacturerName, providerName);
    }
}

/*
 * Description: searches a Manufacturer on the DataBase and deletes it if found
 * Return: returns 1 if found and deleted, 0 if not found
 */
int removeManufacturer(DataBase* database,char* manufacturerName){
    for(int i = 0; i < database->amountOfManufacturers; i++){
        if(strcmp(database->manufacturers[i]->name, manufacturerName) == 0){
            Manufacturer* result = database->manufacturers[i];
            for (int j = i; j < database->amountOfManufacturers; j++){
                database->manufacturers[j] = database->manufacturers[j+1];
            }
            destroyManufacturer(result);
            database->amountOfManufacturers--;
            return 1;
        }
    }
    return 0;
}

/*
 * Description: searches a Provider on the DataBase and deletes it if found
 * Return: returns 1 if found and deleted, 0 if not found
 */
int removeProvider(DataBase* database,char* providerName){
    for(int i = 0; i < database->amountOfProviders; i++){
        if(strcmp(database->providers[i]->name, providerName) == 0){
            Provider* result = database->providers[i];
            for (int j = i; j < database->amountOfProviders; j++){
                database->providers[j] = database->providers[j+1];
            }
            destroyProvider(result);
            database->amountOfProviders--;
            return 1;
        }
    }
    return 0;
}

/*
 * Description: searches a product on the DataBase and deletes it if found
 * Return: returns 1 if found and deleted, 0 if not found
 */
int removeProduct(DataBase *database, char *productName){
    for(int i = 0; i < database->amountOfProducts; i++){
        if(strcmp(database->products[i]->name, productName) == 0){
            Product* result = database->products[i];
            for (int j = i; j < database->amountOfProducts; j++){
                database->products[j] = database->products[j+1];
            }
            destroyProduct(result);
            database->amountOfProducts--;
            return 1;
        }
    }
    return 0;
}

/*
 * Description: checks if a Manufacturer is in the DataBase
 * Return: 1 if it has been found in the DataBase, 0 if not
 */
int manufacturerExist(DataBase* database, char* manufacturerName){
    for(int i = 0; i < database->amountOfManufacturers; i++){
        if(strcmp(manufacturerName,database->manufacturers[i]->name) == 0){
            return 1;
        }
    }
    return 0;
}

/*
 * Description: checks if a Provider is in the DataBase
 * Return: 1 if it has been found in the DataBase, 0 if not
 */
int providerExist(DataBase* database, char* providerName){
    for(int i = 0; i < database->amountOfProviders; i++){
        if(strcmp(providerName,database->providers[i]->name) == 0){
            return 1;
        }
    }
    return 0;
}

/*
 * Description: checks if an Appliance is in the DataBase
 * Return: 1 if it has been found in the DataBase, 0 if not
 */
int productExist(DataBase *database, char *productName){
    for(int i = 0; i < database->amountOfProducts; i++){
        if(strcmp(productName,database->products[i]->name) == 0){
            return 1;
        }
    }
    return 0;
}

/*
 * Description: Deallocates memory assigned for a DataBase and all its components
 * Return: void
 */
void destroyDataBase(DataBase* dataBase){
    for (int i = 0; i < dataBase->amountOfManufacturers; i++)
        destroyManufacturer(dataBase->manufacturers[i]);
    for (int i = 0; i < dataBase->amountOfProviders; i++)
        destroyProvider(dataBase->providers[i]);
    for (int i = 0; i < dataBase->amountOfProducts; i++)
        destroyProduct(dataBase->products[i]);
    free(dataBase->manufacturers);
    free(dataBase->providers);
    free(dataBase->products);
    free(dataBase);
}
