#ifndef CFROMJAVA_PROVIDER_H
#define CFROMJAVA_PROVIDER_H

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