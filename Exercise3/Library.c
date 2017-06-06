#include "Library.h"
#include <malloc.h>
#include <stdio.h>
#include <memory.h>

/*
 * Description: Contains the functions related to the Library structure
 */

/*
 * Description: Creates a Library
 * Returns: The Library created
 */
Library* new_Library() {

    Library* library = malloc(sizeof(Library));

    library->materialsCounter = 0;
    library->peopleCounter = 0;
    library->loanCounter = 0;
    library->availableMaterials = 0;
    library->auxIndex = 0;

    return library;
}

/*
 * Description: Loads materials to the library
 * Returns: Void
 */
void loadMaterial(Library* library, Material* material) {
    if (library->materialsCounter < sizeof(library->materials) / sizeof(library->materials[0])) {
        library->materials[library->materialsCounter] = material;
        library->materialsCounter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Prints the materials list of the library
 * Returns: Void
 */
void printMaterialsList(Library* library, int index) {
    printf("\n#%i", library->auxIndex);
    library->auxIndex++;
    printf("\nType: %s", library->materials[index]->materialType);
    if (strcmp(library->materials[index]->materialType, "Book") == 0) printf("\nEditorial: %s", library->materials[index]->editorial);
    printf("\nTitle: %s", library->materials[index]->title);
    printf("\nAuthor: %s", library->materials[index]->author);
    printf("\nYear: %i", library->materials[index]->year);
    printf("\nCode: %s", library->materials[index]->code);
    printf("\nCost per day: $%.2f", library->materials[index]->costPerDay);
    printf("\nStatus: %s\n", library->materials[index]->status);
}

/*
 * Description: Prints the list of all the materials
 * Returns: Void
 */
void showAllMaterials(Library* library) {
    library->auxIndex = 0;
    for (int i = 0; i < library->materialsCounter; i++) {
        printMaterialsList(library, i);
    }
}

/*
 * Description: Prints th list of only the available materials
 * Returns: Void
 */
void showAvailableMaterials(Library* library) {
    library->auxIndex = 0;
    for (int i = 0; i < library->materialsCounter; i++) {
        if (library->materials[i]->isAvailable) printMaterialsList(library, i);
    }
}

/*
 * Description: Calculates how many available materials are available
 * Returns: Void
 */
void getAvailableMaterials(Library* library) {
    library->availableMaterials = 0;
    for (int i = 0; i < library->materialsCounter; i++) {
        if (library->materials[i]->isAvailable) library->availableMaterials++;
    }
}

/*
 * Description: Deletes a material from the library
 * Returns: Void
 */
void deleteMaterial(Library* library, int position) {
    library->materials[position] = 0;
    library->materialsCounter--;
    for (int i = position; i < library->materialsCounter; i++) {
        library->materials[i] = library->materials[i + 1];
    }
}

/*
 * Description: Loads a person to the library
 * Returns: Void
 */
void loadPerson(Library* library, Person* person) {
    if (library->peopleCounter < sizeof(library->people) / sizeof(library->people[0])) {
        library->people[library->peopleCounter] = person;
        library->peopleCounter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Prints the people list of the library
 * Returns: Void
 */
void printPeopleList(Library* library) {
    for (int i = 0; i < library->peopleCounter; i++) {
        printf("\n#%i", i);
        printf("\nName: %s", library->people[i]->name);
        printf("\nSurname: %s", library->people[i]->surname);
        printf("\nProfession: %s", library->people[i]->personType);
        if (strcmp(library->people[i]->personType, "Student") == 0) printf("\nRegistration Number: %i", library->people[i]->registrationNumber);
        else printf("\nEmployee Number: %i", library->people[i]->employeeNumber);
        printf("\nMail: %s", library->people[i]->mail);
        printf("\nPhone Number: %i", library->people[i]->phoneNumber);
        printf("\nBooks in possession: %i", library->people[i]->materialsCounter);
        printf("\nDebt: $%.2f\n", library->people[i]->debt);
    }
}

/*
 * Description: Loads a loan to the Library
 * Returns: Void
 */
void loadLoan(Library* library, Loan* loan) {
    if (library->loanCounter < sizeof(library->loan) / sizeof(library->loan[0])) {
        library->loan[library->loanCounter] = loan;
        library->loanCounter++;
    } else printf("Max capacity reached");
}

/*
 * Description: Frees the space of memory assigned for a Library and all its components
 * Returns: Void
 */
void freeLibrary(Library* library) {
    free(library);
}
