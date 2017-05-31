#include <afxres.h>
#include "Invoice.h"
/*
 * Description: Contains the functions related to the Invoice structure
 */

/*
 * Description: creates an Invoice with the components on the ShoppingCart
 * Returns: the Invoice created
 */
Invoice* createInvoice(ShoppingCart* cart) {
    Invoice* result = malloc(sizeof(Invoice));
    result->toPay = total(cart);
    result->invoiceLines = malloc(sizeof(InvoiceLine) * cart->appliancesAmount);
    for(int i = 0; i < cart->appliancesAmount; i++){
        result->invoiceLines[i] = createInvoiceLine(cart->appliances[i]);
    }
    result->amountOfLines = cart->appliancesAmount;
    return result;
}

/*
 * Description: Deallocates memory assigned for an Invoice and all its components
 * Return: void
 */
void destroyInvoice(Invoice* invoice){
    for(int i = 0; i < invoice->amountOfLines; i++){
        destroyInvoiceLine(invoice->invoiceLines[i]);
    }
    free(invoice);
}