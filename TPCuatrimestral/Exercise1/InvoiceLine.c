#include <stdlib.h>
#include <string.h>
#include "InvoiceLine.h"

InvoiceLine* createInvoiceLine(char* id, char* article, int* units){
    InvoiceLine* result = malloc(sizeof(InvoiceLine));
    result->id = malloc(sizeof(char)*strlen(id));
    result->article = malloc(sizeof(char)*strlen(article));

    result->id = id;
    result->article = article;
    result->units = units;
    return result;
}
