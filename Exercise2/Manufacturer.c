#include <malloc.h>
#include <mem.h>
#include "Manufacturer.h"
/*
 * Description: creates a Manufacturer
 * Returns: the Manufacturer created
 */
Manufacturer* createManufacturer(char* name, char* description, char* address, char* city, char* telephoneNumber, char* country){
    Manufacturer* result = malloc(sizeof(Manufacturer));
    result->name = malloc(sizeof(char)*strlen(name)+1);
    result->description = malloc(sizeof(char)*strlen(description+1));
    result->address = malloc(sizeof(char)*strlen(address)+1);
    result->city = malloc(sizeof(char)*strlen(city)+1);
    result->telephoneNumber = malloc(sizeof(char)*strlen(telephoneNumber)+1);
    result->country = malloc(sizeof(char)*strlen(country)+1);

    strcpy(result->name, name);
    strcpy(result->description, description);
    strcpy(result->address, address);
    strcpy(result->city, city);
    strcpy(result->telephoneNumber, telephoneNumber);
    strcpy(result->country, country);
    return result;
}

/*
 * Description: Deallocates memory assigned for a Manufacturer and all its components
 * Return: void
 */
void destroyManufacturer(Manufacturer* manufacturer){
    free(manufacturer->name);
    free(manufacturer->address);
    free(manufacturer->city);
    free(manufacturer->description);
    free(manufacturer->country);
    free(manufacturer);
}