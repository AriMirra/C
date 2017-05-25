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
int getNextProviderId(DataBase* database);
int getNextApplianceId(DataBase* database);
int getNextManufacturerId(DataBase* database);
Manufacturer* getManufacturer(char* name, DataBase* database);
Provider* getProvider(char* name, DataBase* database);
Appliance* getAppliance(char* name, DataBase* database);
void removeManufacturer(int idManufacturer, DataBase* database);
void removeProvider(int idProvider, DataBase* database);
void removeAppliance(int idAppliance, DataBase* database);
int providersAmount(Provider** providers);
int manufacturersAmount(Manufacturer** manufacturers);
int appliancesAmount(Appliance** appliances);


#endif //CFROMJAVA_DataBase_H
