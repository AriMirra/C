#ifndef EXERCISE3_MATERIAL_H
#define EXERCISE3_MATERIAL_H

/*
 * Description: The Material structure holds the information for a material, its type, code, author, title, year, status, its cost
 * per day, and, in case it is a book, its editorial
 */
typedef struct material Material;
struct material {
    char* materialType;
    char* code;
    char* author;
    char* title;
    int year;
    int isAvailable;
    char* status;
    char* editorial;
    double costPerDay;
};

// Functions
Material* new_Material(char* code, char* author, char* title, int year, int isBook, int isAvailable, double costPerDay);
void freeMaterial(Material* material);

void changeMaterialStatus(Material* material);

#endif //EXERCISE3_MATERIAL_H
