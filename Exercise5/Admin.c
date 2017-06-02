#include "Admin.h"
#include <malloc.h>
#include <memory.h>

Admin* new_Admin(char* name, char* surname, int id) {

    Admin* admin = malloc(sizeof(Admin));

    admin->name = malloc(sizeof(char) * (strlen(name) + 1));
    admin->surname = malloc(sizeof(char) * (strlen(surname) + 1));
    admin->id = id;

    strcpy(admin->name, name);
    strcpy(admin->surname, surname);

    return admin;
}

void freeAdmin(Admin* admin) {
    free(admin->name);
    free(admin->surname);
    free(admin);
}
