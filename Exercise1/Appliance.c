#include "Appliance.h"
/*
 * Description: Contains the functions related to the Appliance structure
 */

/*
 * Description: creates an Appliance
 * Returns: the Appliance created
 */
Appliance* createAppliance(char* name, char* model, int price, char* id) {
    Appliance* result = malloc(sizeof(Appliance));
    result->name = malloc(sizeof(char)*strlen(name)+1);
    result->model = malloc(sizeof(char)*strlen(model)+1);
    result->label = malloc(sizeof(Label));

    strcpy(result->name, name);
    strcpy(result->model, model);
    result->price = price;
    result->label = createLabel(name, id);
    return result;
}

/*
 * Description: sets the Manufacturer of an Appliance
 * Returns: void
 */
void setManufacturer(Appliance* appliance, char* manufacturerName){
    appliance->manufacturerName = manufacturerName;
}

/*
 * Description: sets the Provider of an Appliance
 * Returns: void
 */
void setProvider(Appliance* appliance, char* providerName){
    appliance->providerName = providerName;
}

/*
 * Description: Deallocates memory assigned for an Appliance and all its components
 * Return: void
 */
void destroyAppliance(Appliance* appliance) {
    free(appliance->name);
    free(appliance->model);
    free(appliance->manufacturerName);
    free(appliance->providerName);
    destroyLabel(appliance->label);
    free(appliance);
}