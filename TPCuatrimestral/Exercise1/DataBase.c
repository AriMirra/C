#include "DataBase.h"
DataBase* newDatabase(){
    DataBase* result = malloc(sizeof(DataBase));
    int initialSize = 10;
    result->manufacturers = malloc(sizeof(Manufacturer*) * initialSize);
    result->manufacturerMaxCapacity = initialSize;
    result->providers = malloc(sizeof(Provider*) * initialSize);
    result->providerMaxCapacity = initialSize;
    result->appliances = malloc(sizeof(Appliance*) * initialSize);
    result->applianceMaxCapacity = initialSize;
    result->amountOfAppliances = 0;
    result->amountOfProviders = 0;
    result->amountOfManufacturers = 0;
    return result;
}

Provider* getProvider(char* name, DataBase* database){
    for(int i = 0; i < providersAmount(database->providers); i++){
            if(strcmp(name,database->providers[i]->name))
                return database->providers[i];
    }
    return NULL;
}

Manufacturer* getManufacturer(char* name, DataBase* database){
    for(int i = 0; i < manufacturersAmount(database->manufacturers); i++){
        if(strcmp(name,database->manufacturers[i]->name))
            return database->manufacturers[i];
    }
    return NULL;
}

Appliance* getAppliance(char* name, DataBase* database){
    for(int i = 0; i < appliancesAmount(database->appliances); i++){
        if(strcmp(name,database->appliances[i]->name))
            return database->appliances[i];
    }
    return NULL;
}

void growManufacturer(DataBase* database){
    database->manufacturers = realloc(database->manufacturers, sizeof(Manufacturer*) * database->manufacturerMaxCapacity * 2);
    database->manufacturerMaxCapacity *= 2;
}
void growProvider(DataBase* database){
    database->providers = realloc(database->providers, sizeof(Provider*) * database->providerMaxCapacity * 2);
    database->providerMaxCapacity *= 2;
}
void growAppliance(DataBase* database){
    database->appliances = realloc(database->appliances, sizeof(Appliance*) * database->applianceMaxCapacity * 2);
    database->applianceMaxCapacity *= 2;
}

void addManufacturer(DataBase* database, Manufacturer* manufacturer){
    if(database->amountOfManufacturers != database->manufacturerMaxCapacity){
        database->manufacturers[database->amountOfManufacturers] = manufacturer;
        database->amountOfManufacturers++;
    }else{
        growManufacturer(database);
        addManufacturer(database,manufacturer);
    }
}

void addProvider(DataBase* database, Provider* provider){
    if(database->amountOfProviders != database->applianceMaxCapacity){
        database->providers[database->amountOfProviders] = provider;
        database->amountOfProviders++;
    }else{
        growProvider(database);
        addProvider(database,provider);
    }
}

void addAppliance(DataBase* database, Appliance* appliance, char* providerName, char* ManufacturerName){
    if(database->amountOfAppliances != database->applianceMaxCapacity){
        database->appliances[database->amountOfAppliances] = appliance;
        database->amountOfAppliances++;
    }else{
        growAppliance(database);
    }
}