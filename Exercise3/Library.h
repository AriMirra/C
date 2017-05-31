#include "Material.h"
#include "Person.h"

#ifndef EXERCISE3_LIBRARY_H
#define EXERCISE3_LIBRARY_H

typedef struct library Library;
struct library {
    Material* materials[100];   // The library can contain 100 materials at a time
    Person* people[100];        // The library is opened to 100 people at a time
    int materialsCounter;
    int peopleCounter;
    int availableMaterials;
};

Library* new_Library();
void freeLibrary(Library* library);

void loadMaterial(Library* library, Material* material);
void loadPerson(Library* library, Person* person);
void printMaterialsList(Library* library, int index);
void showAllMaterials(Library* library);
void showAvailableMaterials(Library* library);
void getAvailableMaterials(Library* library);
void printPeopleList(Library* library);
void deleteMaterial(Library* library, int position);

#endif //EXERCISE3_LIBRARY_H
