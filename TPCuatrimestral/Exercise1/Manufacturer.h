#ifndef CFROMJAVA_MANUFACTURER_H
#define CFROMJAVA_MANUFACTURER_H

typedef struct Manufacturer{
    char* name;
    char* description;
    char* address;
    char* city;
    char* telephoneNumber;
    char* web;
}Manufacturer;

//functions
Manufacturer* createManufacturer(char* name, char* description, char* address, char* city, char* telephoneNumber, char* web);


#endif //CFROMJAVA_MANUFACTURER_H
