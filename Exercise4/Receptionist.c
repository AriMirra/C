#include "Receptionist.h"
#include <malloc.h>
#include <memory.h>

Receptionist* new_Receptionist(char* name, char* surname, int id) {

    Receptionist* receptionist = malloc(sizeof(Receptionist));

    receptionist->name = malloc(sizeof(char) * (strlen(name) + 1));
    receptionist->surname = malloc(sizeof(char) * (strlen(surname) + 1));
    receptionist->id = id;

    strcpy(receptionist->name, name);
    strcpy(receptionist->surname, surname);

    return receptionist;
}

void giveInfo(Receptionist* receptionist) {

}

void freeReceptionist(Receptionist* receptionist) {
    free(receptionist->name);
    free(receptionist->surname);
    free(receptionist);
}
