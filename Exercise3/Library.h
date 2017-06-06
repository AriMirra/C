#ifndef EXERCISE3_LIBRARY_H
#define EXERCISE3_LIBRARY_H

#include "Material.h"
#include "Person.h"
#include "Loan.h"

/*
 * Description: The Library structure holds the information for a Library, the lists for its materials, people and loans
 */
typedef struct library Library;
struct library {
    Material* materials[100];   // The library can contain 100 materials at a time
    Person* people[100];        // The library is opened to 100 people at a time
    Loan* loan[500];            // The library can make a maximum of 500 loans per day
    int materialsCounter;
    int peopleCounter;
    int loanCounter;
    int availableMaterials;
    int auxIndex;
};

// Functions
Library* new_Library();
void freeLibrary(Library* library);

void loadMaterial(Library* library, Material* material);
void loadPerson(Library* library, Person* person);
void loadLoan(Library* library, Loan* loan);
void printMaterialsList(Library* library, int index);
void showAllMaterials(Library* library);
void showAvailableMaterials(Library* library);
void getAvailableMaterials(Library* library);
void printPeopleList(Library* library);
void deleteMaterial(Library* library, int position);

#endif //EXERCISE3_LIBRARY_H
