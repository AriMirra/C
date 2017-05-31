#include "Product.h"
#include <stdlib.h>
#include <string.h>
/*
 * Description: Contains the functions related to the Product structure
 */

/*
 * Function: createProduct
 * Description: Creates a new product with the details passed.
 * Returns: a Product pointer
 */
Product* createProduct(int productID, char *name, ProductType productType,
                       int manufacturerID, int providerID,int price){
    Product* result = malloc(sizeof(Product));
    result->price = price;
    result->productID = productID;
    result->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(result->name, name);
    result->productType = productType;
    result->manufacturerID = manufacturerID;
    result->providerID = providerID;
    return result;
}

void setManufacturerID(Product* product, int manufacturerID){
    product->manufacturerID = manufacturerID;
}

void setProviderID(Product* product, int providerID){
    product->providerID = providerID;
}

/*
 * Function: destroyProduct
 * Description: Deallocates all memory assigned to the product and all it's components.
 * Return: void
 */
void destroyProduct(Product* product){
    free(product->name);
    free(product);
}