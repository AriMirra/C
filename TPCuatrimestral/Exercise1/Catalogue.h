#ifndef CFROMJAVA_CATALOGUE_H
#define CFROMJAVA_CATALOGUE_H

#include "Appliance.h"

typedef struct catalogue{
    Appliance** appliances;
    char* name;
    char* id;
    int* discount;
}Catalogue;

//functions
Catalogue* createCatalogue(char* name, char* id, int* discount);


#endif //CFROMJAVA_CATALOGUE_H
