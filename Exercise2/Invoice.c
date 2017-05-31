#include <afxres.h>
#include "Invoice.h"
/*
 * Description: creates an Invoice with the components on the cart
 * Returns: the pointer to Invoice created
 */
Invoice* createInvoice(Cart* cart) {
    Invoice* result = malloc(sizeof(Invoice));
    result->toPay = total(cart);
    result->invoiceLines = malloc(sizeof(InvoiceLine) * cart->productsAmount);
    for(int i = 0; i < cart->productsAmount; i++){
        result->invoiceLines[i] = createInvoiceLine(cart->products[i]);
    }
    result->amountOfLines = cart->productsAmount;
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