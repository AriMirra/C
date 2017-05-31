#include "DataBase.h"
/*
 * Description: Contains the functions related to the DataBase structure
 */

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
    result->appliances = malloc(sizeof(Appliance*) * initialSize);
    result->applianceMaxCapacity = initialSize;
    result->amountOfAppliances = 0;
    result->amountOfProviders = 0;
    result->amountOfManufacturers = 0;
    return result;
}

/*
 * Description: searches a Manufacturer on the DataBase and returns it if found
 * Return: Manufacturer
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
 * Return: Provider
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
 * Return: Appliance
 */
Appliance* getAppliance(DataBase* database,char* name){
    for(int i = 0; i < database->amountOfAppliances; i++){
        if(strcmp(name,database->appliances[i]->name) == 0)
            return database->appliances[i];
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
void growAppliance(DataBase* database){
    database->appliances = realloc(database->appliances, sizeof(Appliance*) * database->applianceMaxCapacity * 2);
    database->applianceMaxCapacity *= 2;
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
void addAppliance(DataBase* database, Appliance* appliance, char* manufacturerName, char* providerName){
    if(database->amountOfAppliances != database->applianceMaxCapacity){
        setManufacturer(appliance,manufacturerName);
        setProvider(appliance,providerName);
        database->appliances[database->amountOfAppliances] = appliance;
        database->amountOfAppliances++;
    }else{
        growAppliance(database);
        addAppliance(database,appliance,manufacturerName,providerName);
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
 * Description: searches an Appliance on the DataBase and deletes it if found
 * Return: returns 1 if found and deleted, 0 if not found
 */
int removeAppliance(DataBase* database,char* applianceName){
    for(int i = 0; i < database->amountOfAppliances; i++){
        if(strcmp(database->appliances[i]->name, applianceName) == 0){
            Appliance* result = database->appliances[i];
            for (int j = i; j < database->amountOfAppliances; j++){
                database->appliances[j] = database->appliances[j+1];
            }
            destroyAppliance(result);
            database->amountOfAppliances--;
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
int applianceExist(DataBase* database, char* applianceName){
    for(int i = 0; i < database->amountOfAppliances; i++){
        if(strcmp(applianceName,database->appliances[i]->name) == 0){
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
    for (int i = 0; i < dataBase->amountOfAppliances; i++)
        destroyAppliance(dataBase->appliances[i]);
    free(dataBase->manufacturers);
    free(dataBase->providers);
    free(dataBase->appliances);
    free(dataBase);
}