#include "Catalogue.h"

Catalogue* createCatalogue(char* name, char* id, int* discount){
    Catalogue* result = malloc(sizeof(Catalogue));
    result->name = malloc(sizeof(char)*strlen(name));
    result->id = malloc(sizeof(char)*strlen(id));

    strcpy(result->name, name);
    strcpy(result->id, id);
    result->discount = discount;
    return result;
}