#include <malloc.h>
#include <mem.h>
#include "Label.h"

Label* createLabel(char* name, char* id){
    Label* result = malloc(sizeof(Label));
    result->name = malloc(sizeof(char)*strlen(name));
    result->id = malloc(sizeof(char)*strlen(id));

    result->name = name;
    result->id = id;
    return result;
}