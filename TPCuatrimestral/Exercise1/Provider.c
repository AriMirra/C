#include <malloc.h>
#include <mem.h>
#include "Provider.h"

Provider* createProvider(char* name, char* description, char* address, char* city, char* telephoneNumber, char* web){
    Provider* result = malloc(sizeof(Provider));
    result->name = malloc(sizeof(char)*strlen(name));
    result->description = malloc(sizeof(char)*strlen(description));
    result->address = malloc(sizeof(char)*strlen(address));
    result->city = malloc(sizeof(char)*strlen(city));
    result->telephoneNumber = malloc(sizeof(char)*strlen(telephoneNumber));
    result->web = malloc(sizeof(char)*strlen(web));

    strcpy(result->name, name);
    strcpy(result->description, description);
    strcpy(result->address, address);
    strcpy(result->city, city);
    strcpy(result->telephoneNumber, telephoneNumber);
    strcpy(result->web, web);
    return result;
}
