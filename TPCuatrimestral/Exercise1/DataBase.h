#ifndef CFROMJAVA_CATALOGUE_H
#define CFROMJAVA_CATALOGUE_H

#include "Appliance.h"
#include "Manufacturer.h"
#include "Provider.h"

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
    int applianceIDGenerator;
}DataBase;

//functions
DataBase* createDataBase();
void growManufacturer(DataBase* database);
void growProvider(DataBase* database);
void growAppliance(DataBase* database);
void addManufacturer(DataBase* database, Manufacturer* manufacturer);
void addProvider(DataBase* database, Provider* provider);
void addAppliance(DataBase* database, Appliance* appliance, char* providerName, char* ManufacturerName);
int getNextApplianceId(DataBase* database);
Manufacturer* getManufacturer(char* name, DataBase* database);
Provider* getProvider(char* name, DataBase* database);
Appliance* getAppliance(char* name, DataBase* database);
void removeManufacturer(DataBase* database, char* manufacturerName);
void removeProvider(DataBase* database, char* providerName);
void removeAppliance(DataBase* database, char* applianceName);
void destroyDataBase(DataBase* dataBase);


#endif //CFROMJAVA_DataBase_H
