#include <malloc.h>
#include <mem.h>
#include "Label.h"

Label* createLabel(char* name, char* id){
    Label* result = malloc(sizeof(Label));
    result->name = malloc(sizeof(char)*strlen(name)+1);
    result->id = malloc(sizeof(char)*strlen(id)+1);

    strcpy(result->name, name);
    strcpy(result->id, id);
    return result;
}