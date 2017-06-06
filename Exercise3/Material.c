#include "Material.h"
#include <malloc.h>
#include <memory.h>

/*
 * Description: Contains the functions related to the Material structure
 */

/*
 * Description: Creates a Material
 * Returns: The Material Created
 */
Material* new_Material(char* code, char* author, char* title, int year, int isBook, int isAvailable, double costPerDay) {

    Material* material = malloc(sizeof(Material));

    char* materialType;
    if (isBook) {
        materialType = malloc(sizeof(char) * 5);
        strcpy(materialType, "Book");
    } else {
        materialType = malloc(sizeof(char) * 9);
        strcpy(materialType, "Magazine");
    }

    char* status;
    if (isAvailable) {
        status = malloc(sizeof(char) * 10);
        strcpy(status, "Available");
    } else {
        status = malloc(sizeof(char) * 14);
        strcpy(status, "Not available");
    }

    material->materialType = materialType;
    material->code = malloc(sizeof(char) * (strlen(code) + 1));
    material->author = malloc(sizeof(char) * (strlen(author) + 1));
    material->title = malloc(sizeof(char) * (strlen(title) + 1));
    material->year = year;
    material->isAvailable = isAvailable;
    material->status =  malloc(sizeof(char) * (strlen(status) + 1));
    material->costPerDay = costPerDay;

    strcpy(material->code, code);
    strcpy(material->author, author);
    strcpy(material->title, title);
    strcpy(material->status, status);

    return material;
}

/*
 * Description: Changes the material availability status
 * Returns: Void
 */
void changeMaterialStatus(Material* material) {
    if (material->isAvailable) {
        material->isAvailable = 0;
        material->status = "Not available";
    }
    else if (!material->isAvailable) {
        material->isAvailable = 1;
        material->status = "Available";
    }
}

/*
 * Description: Frees the space of memory related to a material and all its components
 * Returns: Void
 */
void freeMaterial(Material* material) {
    free(material->materialType);
    free(material->code);
    free(material->author);
    free(material->title);
    free(material->status);
    free(material->editorial);
    free(material);
}
