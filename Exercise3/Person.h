#include "Material.h"

#ifndef EXERCISE3_PERSON_H
#define EXERCISE3_PERSON_H

typedef struct person Person;
struct person {
    char* personType;
    char* name;
    char* surname;
    char* mail;
    int phoneNumber;
    int booksQuantity;
    double debt;
    int registrationNumber;
    int employeeNumber;
    Material* materials[20];         // A person can have as much as 20 materials at a time
    int materialsCounter;
};

Person* new_Person(char* name, char* surname, char* mail, int phoneNumber, int isStudent);
void freePerson(Person* person);

void takeMaterial(Person* person, Material* material);
void leaveMaterial(Person* person, int position);
void showMyMaterials(Person* person);

#endif //EXERCISE3_PERSON_H
