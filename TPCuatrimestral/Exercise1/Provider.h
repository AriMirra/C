#ifndef CFROMJAVA_PROVIDER_H
#define CFROMJAVA_PROVIDER_H


typedef struct provider Provider;

struct provider{
    char* name;
    char* description;
    char* address;
    char* city;
    char* telephoneNumber;
    char* web;
};

//functions
Provider* createProvider(char* name, char* description, char* address, char* city, char* telephoneNumber, char* web);

#endif //CFROMJAVA_PROVIDER_H