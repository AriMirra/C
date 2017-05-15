#include "Appliance.h"

Appliance *createAppliance(char* name, char* description, int* price, Label* label) {
    Appliance* result = malloc(sizeof(Appliance));
    result->name = malloc(sizeof(char)*strlen(name));
    result->description = malloc(sizeof(char)*strlen(description));
    result->label = malloc(sizeof(Label));

    strcpy(result->name, name);
    strcpy(result->description, description);
    result->price = price;
    result->label = label;
    return result;
}
