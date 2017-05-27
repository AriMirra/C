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
    result->applianceIDGenerator = 1;
    return result;
}

Manufacturer* getManufacturer(DataBase* database,char* name){
    for(int i = 0; i < database->amountOfManufacturers; i++){
        if(strcmp(name,database->manufacturers[i]->name))
            return database->manufacturers[i];
    }
    return NULL;
}

Provider* getProvider(DataBase* database,char* name){
    for(int i = 0; i < database->amountOfProviders; i++){
            if(strcmp(name,database->providers[i]->name))
                return database->providers[i];
    }
    return NULL;
}

Appliance* getAppliance(DataBase* database,char* name){
    for(int i = 0; i < database->amountOfAppliances; i++){
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

void addAppliance(DataBase* database, Appliance* appliance, char* manufacturerName, char* providerName){
    if(database->amountOfAppliances != database->applianceMaxCapacity){
        setManufacturer(appliance,manufacturerName);
        setProvider(appliance,providerName);
        database->appliances[database->amountOfAppliances] = appliance;
        database->amountOfAppliances++;
    }else{
        growAppliance(database);
    }
}

int getNextApplianceId(DataBase* database){
    int result = database->applianceIDGenerator;
    database->applianceIDGenerator += 1;
    return result;
}

int removeManufacturer(DataBase* database,char* manufacturerName){
    for(int i = 0; i < database->amountOfManufacturers; i++){
        if(strcmp(database->manufacturers[i]->name, manufacturerName)){
            Manufacturer* result = database->manufacturers[i];
            for (int j = i; j < database->amountOfManufacturers; j++){
                database->manufacturers[j] = database->manufacturers[j+1];
            }
            destroyManufacturer(result);
            return 1;
        }
    }
    return 0;
}

int removeProvider(DataBase* database,char* providerName){
    for(int i = 0; i < database->amountOfProviders; i++){
        if(strcmp(database->providers[i]->name, providerName)){
            Provider* result = database->providers[i];
            for (int j = i; j < database->amountOfProviders; j++){
                database->providers[j] = database->providers[j+1];
            }
            destroyProvider(result);
            return 1;
        }
    }
    return 0;
}

int removeAppliance(DataBase* database,char* applianceName){
    for(int i = 0; i < database->amountOfAppliances; i++){
        if(strcmp(database->appliances[i]->name, applianceName)){
            Appliance* result = database->appliances[i];
            for (int j = i; j < database->amountOfAppliances; j++){
                database->appliances[j] = database->appliances[j+1];
            }
            destroyAppliance(result);
            return 1;
        }
    }
    return 0;
}

void destroyDataBase(DataBase* dataBase){
    for (int i = 0; i < dataBase->amountOfManufacturers; i++)
        destroyManufacturer(dataBase->manufacturers[i]);
    for (int i = 0; i < dataBase->amountOfProviders; i++)
        destroyProvider(dataBase->providers[i]);
    for (int i = 0; i < dataBase->amountOfAppliances; i++)
        destroyAppliance(dataBase->appliances[i]);
    free(dataBase->manufacturers);
    free(dataBase->providers);
    free(dataBase->appliances);
    free(dataBase);
}