#include "Accessory.h"
#include <stdlib.h>
#include <string.h>

/*
 * Function: createAccessory
 * Description: Creates a new accessory with the details passed.
 * Returns: Accessory pointer.
 */
Accessory* createAccessory(char* name, char* description, int price){
    Accessory* result = malloc(sizeof(Accessory));
    result->name = malloc(sizeof(char)*(strlen(name)+1));
    result->description = malloc(sizeof(char)*(strlen(description)+1));
    strcpy(result->name, name);
    strcpy(result->description, description);
    result->price = price;
    return result;
}

/*
 * Function: destroyAccessory
 * Description: Deallocates all memory assigned to the accessory.
 * Returns: void
 */
void destroyAccessory(Accessory* accessory){
    free(accessory->name);
    free(accessory->description);
    free(accessory);
}
