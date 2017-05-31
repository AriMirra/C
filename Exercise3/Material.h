#ifndef EXERCISE3_MATERIAL_H
#define EXERCISE3_MATERIAL_H

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

Material* new_Material(char* code, char* author, char* title, int year, int isBook, int isAvailable, double costPerDay);
void freeMaterial(Material* material);

void changeMaterialStatus(Material* material);

#endif //EXERCISE3_MATERIAL_H
