#include <stdio.h>
#include <malloc.h>
#include "Database.h"

void addApplianceMenu(DataBase* database, int*** applianceIdArray, int* providerIdArray, int* manufacturerIdArray){
    printf("Add appliance:\n");
    printf("Name:\n");
    char* name = malloc(sizeof(char) * 20);
    //save the string
    printf("Price:\n");
    //save price
    printf("Manufacturer:\n");
    //list, check and save manufacturer
    printf("Provider:\n");
    //list, check and save provider
    //create appliance with data
    //addAppliance(database, appliance, manufacturer, provider);
    free(name);
}
