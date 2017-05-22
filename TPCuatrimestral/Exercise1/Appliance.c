#include "Appliance.h"

Appliance* createAppliance(char* name, char* model, int price, char* id) {
    Appliance* result = malloc(sizeof(Appliance));
    result->name = malloc(sizeof(char)*strlen(name));
    result->model = malloc(sizeof(char)*strlen(model));
    result->label = malloc(sizeof(Label));

    strcpy(result->name, name);
    strcpy(result->model, model);
    result->price = price;
    result->label = createLabel(name, id);
    return result;
}

void destroyAppliance(Appliance* appliance) {
    free(appliance->name);
    free(appliance);
}
