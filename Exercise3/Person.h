#ifndef EXERCISE3_PERSON_H
#define EXERCISE3_PERSON_H

#include "Material.h"

/*
 * Description: The Person structure holds information about a person, such as its profession, name, surname, mail, phone number,
 * debt, a list of materials in his possession, and, in case he is a student, its registration number, but if he is a teacher,
 * its employee number
 */
typedef struct person Person;
struct person {
    char* personType;
    char* name;
    char* surname;
    char* mail;
    int phoneNumber;
    double debt;
    int registrationNumber;
    int employeeNumber;
    Material* materials[20];         // A person can have as much as 20 materials at a time
    int materialsCounter;
};

// Functions
Person* new_Person(char* name, char* surname, char* mail, int phoneNumber, int isStudent);
void freePerson(Person* person);

void takeMaterial(Person* person, Material* material);
void showMyMaterials(Person* person);

#endif //EXERCISE3_PERSON_H
