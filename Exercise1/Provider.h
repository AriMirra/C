#ifndef CFROMJAVA_PROVIDER_H
#define CFROMJAVA_PROVIDER_H

/*
 * Description: The Provider structure has the information of a provider and it's details.
 */
typedef struct Provider{
    char* name;
    char* description;
    char* address;
    char* city;
    char* telephoneNumber;
    char* web;
}Provider;

//functions
Provider* createProvider(char* name, char* description, char* address, char* city, char* telephoneNumber, char* web);
void destroyProvider(Provider* provider);
#endif //CFROMJAVA_PROVIDER_H