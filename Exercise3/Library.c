#include "Library.h"
#include <malloc.h>
#include <stdio.h>
#include <memory.h>

Library* new_Library() {

    Library* library = malloc(sizeof(Library));

    library->materialsCounter = 0;
    library->peopleCounter = 0;

    return library;
}

void loadMaterial(Library* library, Material* material) {
    if (library->materialsCounter < sizeof(library->materials) / sizeof(library->materials[0])) {
        library->materials[library->materialsCounter] = material;
        library->materialsCounter++;
    } else printf("Max capacity reached");
}

void printMaterialsList(Library* library) {
    for (int i = 0; i < library->materialsCounter; i++) {
        printf("\n%i.", i);
        printf("\nType: %s", library->materials[i]->materialType);
        if (strcmp(library->materials[i]->materialType, "Book")) printf("\nEditorial: %s", library->materials[i]->editorial);
        printf("\nTitle: %s", library->materials[i]->title);
        printf("\nAuthor: %s", library->materials[i]->author);
        printf("\nYear: %i", library->materials[i]->year);
        printf("\nCode: %s", library->materials[i]->code);
        printf("\nCost per day: %i", library->materials[i]->costPerDay);
        printf("\nStatus: %s\n", library->materials[i]->status);
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

    }
}

void freeLibrary(Library* library) {
    free(library->materials);
    free(library->people);
    free(library);
}
