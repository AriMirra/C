#include <malloc.h>
#include <mem.h>
#include "Provider.h"
/*
 * Description: creates a Provider
 * Returns: the Provider created
 */
Provider* createProvider(char* name, char* description, char* address, char* city, char* telephoneNumber, char* web){
    Provider* result = malloc(sizeof(Provider));
    result->name = malloc(sizeof(char)*strlen(name)+1);
    result->description = malloc(sizeof(char)*strlen(description)+1);
    result->address = malloc(sizeof(char)*strlen(address)+1);
    result->city = malloc(sizeof(char)*strlen(city)+1);
    result->telephoneNumber = malloc(sizeof(char)*strlen(telephoneNumber)+1);
    result->web = malloc(sizeof(char)*strlen(web)+1);

    strcpy(result->name, name);
    strcpy(result->description, description);
    strcpy(result->address, address);
    strcpy(result->city, city);
    strcpy(result->telephoneNumber, telephoneNumber);
    strcpy(result->web, web);
    return result;
}

/*
 * Description: Deallocates memory assigned for a Provider and all its components
 * Return: void
 */
void destroyProvider(Provider* provider){
    free(provider->address);
    free(provider->web);
    free(provider->city);
    free(provider->description);
    free(provider->name);
    free(provider);
}
