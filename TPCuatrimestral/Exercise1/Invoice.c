#include <afxres.h>
#include "Invoice.h"

Invoice *createInvoice(char* id, int* toPay) {
    Invoice* result = malloc(sizeof(Invoice));
    result->id = malloc(sizeof(char)*strlen(id));

    strcpy(result->id, id);
    result->toPay = toPay;
    return result;
}

