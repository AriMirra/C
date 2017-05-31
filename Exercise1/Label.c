#include <malloc.h>
#include <mem.h>
#include "Label.h"
/*
 * Description: Contains the functions related to the Label structure
 */

/*
 * Description: creates a Label
 * Returns: the Label created
 */
Label* createLabel(char* name, char* id){
    Label* result = malloc(sizeof(Label));
    result->name = malloc(sizeof(char)*strlen(name)+1);
    result->id = malloc(sizeof(char)*strlen(id)+1);

    strcpy(result->name, name);
    strcpy(result->id, id);
    return result;
}

/*
 * Description: Deallocates memory assigned for a Label and all its components
 * Return: void
 */
void destroyLabel(Label* label){
    free(label->name);
    free(label->id);
    free(label);
}