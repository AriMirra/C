#ifndef CFROMJAVA_CATALOGUE_H
#define CFROMJAVA_CATALOGUE_H

#include "Appliance.h"
#include "Manufacturer.h"
#include "Provider.h"

typedef struct DataBase{
    Manufacturer** manufacturers;
    int amountOfManufacturers;

    Provider** providers;
    int amountOfProviders;

    Appliance** appliances;
    int amountOfAppliances;

}DataBase;

//functions
DataBase* createDataBase();
int providersAmount(Provider** providers);
int manufacturersAmount(Manufacturer** manufacturers);
int appliancesAmount(Appliance** appliances);
Provider* getProvider(char* name, DataBase* database);
Manufacturer* getManufacturer(char* name, DataBase* database);
Appliance* getAppliance(char* name, DataBase* database);
void addProvider(Provider* provider);
void addManufacturer(Manufacturer* manufacturer);
void addAppliance(Appliance* appliance, char* providerName, char* ManufacturerName);
//en el addAppliance le seteas a la appliance su id

#endif //CFROMJAVA_DataBase_H
