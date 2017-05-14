//
// Created by arimi on 14-May-17.
//

#ifndef CFROMJAVA_CATALOGUE_H
#define CFROMJAVA_CATALOGUE_H

#include "Appliance.h"

typedef struct catalogue Catalogue;

struct catalogue{
    Appliance** appliances;
    char* name;
    char* id;
    int* discount;
};

//functions
Catalogue* createCatalogue(char* name, char* id, int* discount);


#endif //CFROMJAVA_CATALOGUE_H
