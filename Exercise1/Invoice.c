#include <afxres.h>
#include "Invoice.h"

Invoice* createInvoice(ShoppingCart* cart) {
    Invoice* result = malloc(sizeof(Invoice));
    result->toPay = total(cart);
    result->invoiceLines = malloc(sizeof(InvoiceLine) * cart->appliancesAmount);
    return result;
}

void destroyInvoice(Invoice* invoice){
    for(int i = 0; i < invoice->amountOfLines; i++){
        destroyInvoiceLine(invoice->invoiceLines[i]);
    }
    free(invoice);
}
