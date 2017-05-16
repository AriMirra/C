#ifndef CFROMJAVA_APPLIANCE_H
#define CFROMJAVA_APPLIANCE_H

#include <afxres.h>
#include "Label.h"

typedef struct Appliance{
    Label* label;
    char* name;
    char* description;
    int price;
}Appliance;

// functions
Appliance* createAppliance(char* name, char* description, int price, Label* label);



#endif //CFROMJAVA_APPLIANCE_H
