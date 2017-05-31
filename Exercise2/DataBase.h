#ifndef CFROMJAVA_CATALOGUE_H
#define CFROMJAVA_CATALOGUE_H
#include "Manufacturer.h"
#include "Provider.h"
#include "Product.h"

/*
 * Description: The DataBase holds the information of the hole system,
 *              is where manufacturers, providers and appliances are added, consulted or deleted
 */
typedef struct DataBase{
    Manufacturer** manufacturers;
    int amountOfManufacturers;
    int manufacturerMaxCapacity;

    Provider** providers;
    int amountOfProviders;
    int providerMaxCapacity;

    Product** products;
    int amountOfProducts;
    int productMaxCapacity;
}DataBase;

//functions
DataBase* createDataBase();
void growManufacturer(DataBase* database);
void growProvider(DataBase* database);
void growAppliance(DataBase* database);
void addManufacturer(DataBase* database, Manufacturer* manufacturer);
void addProvider(DataBase* database, Provider* provider);
void addProduct(DataBase *database, Product *appliance, char *manufacturerName, char *providerName);
Manufacturer* getManufacturer(DataBase* database,char* name);
Provider* getProvider(DataBase* database,char* name);
Product* getProduct(DataBase *database, char *name);
int removeManufacturer(DataBase* database,char* manufacturerName);
int removeProvider(DataBase* database,char* providerName);
int removeProduct(DataBase *database, char *productName);
int manufacturerExist(DataBase* database, char* manufacturerName);
int providerExist(DataBase* database, char* providerName);
int productExist(DataBase *database, char *productName);
void destroyDataBase(DataBase* dataBase);
#endif //CFROMJAVA_DataBase_H