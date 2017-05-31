#ifndef CFROMJAVA_PRODUCT_H
#define CFROMJAVA_PRODUCT_H
/*
 * Description: Represents a generic product from the CameraShop system. A product can be a
 * camera or an accessory.
 */

typedef enum{CAMERA, ACCESSORY}ProductType;

typedef struct Product{
    char* name;
    ProductType productType;
    int price;
    int manufacturerID;
    int providerID;
    int productID;
}Product;

Product* createProduct(int productID, char *name, ProductType productType,
                       int manufacturerID, int providerID, int price);
void setManufacturerID(Product* product, int manufacturerID);
void setProviderID(Product* product, int providerID);
void destroyProduct(Product* product);
#endif //CFROMJAVA_PRODUCT_H
