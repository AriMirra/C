#ifndef CFROMJAVA_APPLIANCE_H
#define CFROMJAVA_APPLIANCE_H

#include <afxres.h>
#include "Label.h"

typedef struct Appliance{
    Label* label;
    char* name;
    char* model;
    char* manufacturerName;
    char* providerName;
    int price;
}Appliance;

// functions
Appliance* createAppliance(char* name, char* model, int price, char* id);
void setManufacturer(Appliance* appliance, char* manufacturerName);
void setProvider(Appliance* appliance, char* providerName);
void destroyAppliance(Appliance* appliance);
#endif //CFROMJAVA_APPLIANCE_H