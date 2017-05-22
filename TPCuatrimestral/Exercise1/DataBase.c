#include "DataBase.h"
DataBase* newDatabase(){
    DataBase* result = malloc(sizeof(DataBase));
    int initialSize = 10;
    result->providers = malloc(sizeof(Provider*) * initialSize);
    //result->booleanArrayProvider = malloc(sizeof(int) * initialSize);
    //result->providerMaxCapacity = initialSize;
    result->appliances = malloc(sizeof(Appliance*) * initialSize);
    //result->booleanArrayAppliance = malloc(sizeof(int) * initialSize);
    //result->applianceMaxCapacity = initialSize;
    result->manufacturers = malloc(sizeof(Manufacturer*) * initialSize);
    //result->booleanArrayManufacturer = malloc(sizeof(int) * initialSize);
    //result->manufacturerMaxCapacity = initialSize;
    //result->idProviderGenerator = 1;
    //result->idApplianceGenerator = 1;
    //result->idManufacturerGenerator = 1;
    result->amountOfAppliances = 0;
    result->amountOfProviders = 0;
    result->amountOfManufacturers = 0;
    return result;
}

int providersAmount(Provider** providers){
    return sizeof(providers)/sizeof(providers[0]);
}

int manufacturersAmount(Manufacturer** manufacturers){
    return sizeof(manufacturers)/sizeof(manufacturers[0]);
}

int appliancesAmount(Appliance** appliances){
    return sizeof(appliances)/sizeof(appliances[0]);
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

Manufacturer* getAppliance(char* name, DataBase* database){
    for(int i = 0; i < manufacturersAmount(database->manufacturers); i++){
        if(strcmp(name,database->manufacturers[i]->name))
            return database->manufacturers[i];
    }
    return NULL;
}
