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


#endif //CFROMJAVA_DataBase_H
