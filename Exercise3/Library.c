#include "Library.h"
#include <malloc.h>
#include <stdio.h>
#include <memory.h>

Library* new_Library() {

    Library* library = malloc(sizeof(Library));

    library->materialsCounter = 0;
    library->peopleCounter = 0;
    library->availableMaterials = 0;

    return library;
}

void loadMaterial(Library* library, Material* material) {
    if (library->materialsCounter < sizeof(library->materials) / sizeof(library->materials[0])) {
        library->materials[library->materialsCounter] = material;
        library->materialsCounter++;
    } else printf("Max capacity reached");
}

void printMaterialsList(Library* library, int index) {
    printf("\n%i.", index);
    printf("\nType: %s", library->materials[index]->materialType);
    if (strcmp(library->materials[index]->materialType, "Book") == 0) printf("\nEditorial: %s", library->materials[index]->editorial);
    printf("\nTitle: %s", library->materials[index]->title);
    printf("\nAuthor: %s", library->materials[index]->author);
    printf("\nYear: %i", library->materials[index]->year);
    printf("\nCode: %s", library->materials[index]->code);
    printf("\nCost per day: $%.2f", library->materials[index]->costPerDay);
    printf("\nStatus: %s\n", library->materials[index]->status);
}

void showAllMaterials(Library* library) {
    for (int i = 0; i < library->materialsCounter; i++) {
        printMaterialsList(library, i);
    }
}

void showAvailableMaterials(Library* library) {
    for (int i = 0; i < library->materialsCounter; i++) {
        if (library->materials[i]->isAvailable) printMaterialsList(library, i);
    }
}

void getAvailableMaterials(Library* library) {
    for (int i = 0; i < library->materialsCounter; i++) {
        if (library->materials[i]->isAvailable) library->availableMaterials++;
    }
}

void deleteMaterial(Library* library, int position) {
    library->materials[position] = 0;
    library->materialsCounter--;
    for (int i = position; i < library->materialsCounter; i++) {
        library->materials[i] = library->materials[i + 1];
    }
}

void loadPerson(Library* library, Person* person) {
    library->people[library->peopleCounter] = person;
    library->peopleCounter++;
}

void printPeopleList(Library* library) {
    for (int i = 0; i < library->peopleCounter; i++) {
        printf("\n%i.", i);
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

void freeLibrary(Library* library) {
    free(library->materials);
    free(library->people);
    free((void *) library->materialsCounter);
    free((void *) library->peopleCounter);
    free((void *) library->availableMaterials);
    free(library);
}
