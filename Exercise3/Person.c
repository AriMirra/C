#include "Person.h"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>

Person* new_Person(char* name, char* surname, char* mail, int phoneNumber, int isStudent) {

    Person* person = malloc(sizeof(Person));

    char* personType;
    personType = malloc(sizeof(char) * 8);
    if (isStudent) strcpy(personType, "Student");
    else strcpy(personType, "Teacher");

    person->personType = personType;
    person->name = malloc(sizeof(char) * (strlen(name) + 1));
    person->surname = malloc(sizeof(char) * (strlen(surname) + 1));
    person->mail = malloc(sizeof(char) * (strlen(mail) + 1));
    person->phoneNumber = phoneNumber;
    person->debt = 0;
    person->materialsCounter = 0;

    strcpy(person->name, name);
    strcpy(person->surname, surname);
    strcpy(person->mail, mail);

    return person;
}

void takeMaterial(Person* person, Material* material) {
    if (person->materialsCounter < sizeof(person->materials) / sizeof(person->materials[0])) {
        person->materials[person->materialsCounter] = material;
        person->materialsCounter++;
    } else printf("Max capacity reached");
}

void showMyMaterials(Person* person) {
    for (int i = 0; i < person->materialsCounter; i++) {
        printf("\n#%i", i);
        printf("\nType: %s", person->materials[i]->materialType);
        if (strcmp(person->materials[i]->materialType, "Book")) printf("\nEditorial: %s",person->materials[i]->editorial);
        printf("\nTitle: %s", person->materials[i]->title);
        printf("\nAuthor: %s", person->materials[i]->author);
        printf("\nYear: %i", person->materials[i]->year);
        printf("\nCode: %s", person->materials[i]->code);
        printf("\nCost per day: $%.2f\n", person->materials[i]->costPerDay);
    }
}

void freePerson(Person* person) {
    free(person->personType);
    free(person->name);
    free(person->surname);
    free(person->mail);
    free(person);
}
