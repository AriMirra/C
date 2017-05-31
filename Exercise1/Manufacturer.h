#ifndef CFROMJAVA_MANUFACTURER_H
#define CFROMJAVA_MANUFACTURER_H

/*
 * Description: The Manufacturer structure has the information of a manufacturer and it's details.
 */
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
void destroyManufacturer(Manufacturer* manufacturer);
#endif //CFROMJAVA_MANUFACTURER_H