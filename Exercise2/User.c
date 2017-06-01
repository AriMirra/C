#include "User.h"
#include <stdlib.h>
#include <string.h>
/*
 * Description: creates a User
 * Returns: a pointer to the User created
 */
User* createUser(char* name,char* dni,char* address,char* telephone,
                 char* city,char* province,char* country,char* postalCode){

    User* result = malloc(sizeof(User));
    result->name = malloc(sizeof(char)*strlen(name)+1);
    result->dni = malloc(sizeof(char)*strlen(dni)+1);
    result->address = malloc(sizeof(char)*strlen(address)+1);
    result->telephone = malloc(sizeof(char)*strlen(telephone)+1);
    result->city = malloc(sizeof(char)*strlen(city)+1);
    result->province = malloc(sizeof(char)*strlen(province)+1);
    result->country = malloc(sizeof(char)*strlen(country)+1);
    result->postalCode = malloc(sizeof(char)*strlen(postalCode)+1);

    strcpy(result->name,name);
    strcpy(result->dni,dni);
    strcpy(result->address,address);
    strcpy(result->telephone,telephone);
    strcpy(result->city,city);
    strcpy(result->province,province);
    strcpy(result->country,country);
    strcpy(result->postalCode,postalCode);

    return result;
}