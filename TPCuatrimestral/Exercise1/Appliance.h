//
// Created by arimi on 14-May-17.
//

#ifndef CFROMJAVA_APPLIANCE_H
#define CFROMJAVA_APPLIANCE_H

#include "Label.h"

typedef struct appliance Appliance;

struct appliance{
    Label* label;
    char* name;
    char* description;
    float* price;
};

// functions
Appliance* createAppliance(char* name, char* description, float* price, Label* label);



#endif //CFROMJAVA_APPLIANCE_H
