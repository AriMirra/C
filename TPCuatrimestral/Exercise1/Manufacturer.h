//
// Created by arimi on 14-May-17.
//

#ifndef CFROMJAVA_MANUFACTURER_H
#define CFROMJAVA_MANUFACTURER_H

typedef struct manufacturer Manufacturer;

struct manufacturer{
    char* name;
    char* description;
    char* address;
    char* city;
    char* telephoneNumber;
    char* web;
};

//functions
Manufacturer* createManufacturer(char* name, char* description, char* address, char* city, char* telephoneNumber, char* web);


#endif //CFROMJAVA_MANUFACTURER_H
