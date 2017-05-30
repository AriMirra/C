#ifndef CFROMJAVA_CATALOGUE_H
#define CFROMJAVA_CATALOGUE_H

#include "Appliance.h"
#include "Manufacturer.h"
#include "Provider.h"
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

    Appliance** appliances;
    int amountOfAppliances;
    int applianceMaxCapacity;
}DataBase;

//functions
DataBase* createDataBase();
void growManufacturer(DataBase* database);
void growProvider(DataBase* database);
void growAppliance(DataBase* database);
void addManufacturer(DataBase* database, Manufacturer* manufacturer);
void addProvider(DataBase* database, Provider* provider);
void addAppliance(DataBase* database, Appliance* appliance, char* manufacturerName, char* providerName);
Manufacturer* getManufacturer(DataBase* database,char* name);
Provider* getProvider(DataBase* database,char* name);
Appliance* getAppliance(DataBase* database,char* name);
int removeManufacturer(DataBase* database,char* manufacturerName);
int removeProvider(DataBase* database,char* providerName);
int removeAppliance(DataBase* database,char* applianceName);
int manufacturerExist(DataBase* database, char* manufacturerName);
int providerExist(DataBase* database, char* providerName);
int applianceExist(DataBase* database, char* applianceName);
void destroyDataBase(DataBase* dataBase);
#endif //CFROMJAVA_DataBase_H
