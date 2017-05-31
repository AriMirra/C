#ifndef CFROMJAVA_CATALOGUE_H
#define CFROMJAVA_CATALOGUE_H
#include "Manufacturer.h"
#include "Provider.h"
#include "Product.h"
#include "Camera.h"
#include "Accessory.h"

/*
 * Description: The DataBase holds the information of the hole system,
 *              is where manufacturers, providers and appliances are added, consulted or deleted
 */
typedef struct DataBase{
    Manufacturer** manufacturers;
    int amountOfManufacturers;
    int manufacturerMaxCapacity;
    int manufacturerIDGenerator;

    Provider** providers;
    int amountOfProviders;
    int providerMaxCapacity;
    int providerIDGenerator;

    Product** products;
    int amountOfProducts;
    int productMaxCapacity;
    int productIDGenerator;

    Camera** cameras;
    int amountOfCameras;
    int cameraMaxCapacity;
    int cameraIDGenerator;

    Accessory** accessories;
    int amountOfaccessories;
    int accessoryMaxCapacity;
    int accessoryIDGenerator;

}DataBase;

//functions
DataBase* createDataBase();
void growManufacturer(DataBase* database);
void growProvider(DataBase* database);
void growProduct(DataBase* database);
void addManufacturer(DataBase* database, Manufacturer* manufacturer);
void addProvider(DataBase* database, Provider* provider);
void addProduct(DataBase *database, Product *appliance, int manufacturerID, int providerID);
Manufacturer* getManufacturer(DataBase* database, int manufacturerID);
Provider* getProvider(DataBase* database, int providerID);
Product* getProduct(DataBase *database, int productID);
int removeManufacturer(DataBase* database,int manufacturerID);
int removeProvider(DataBase* database, int providerID);
int removeProduct(DataBase *database, int productID);
int manufacturerExist(DataBase* database, int manufacturerID);
int providerExist(DataBase* database, int providerID);
int productExist(DataBase *database, int productID);
int nextManufacturerID(DataBase* dataBase);
int nextProviderID(DataBase* dataBase);
int nextProductID(DataBase* dataBase);
void destroyDataBase(DataBase* dataBase);
#endif //CFROMJAVA_DataBase_H