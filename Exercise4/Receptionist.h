#ifndef CFROMJAVA_RECEPTIONIST_H
#define CFROMJAVA_RECEPTIONIST_H

#include "Hotel.h"
#include "Admin.h"

typedef struct receptionist Receptionist;
struct receptionist {
    char* name;
    char* surname;
    int id;
};

Receptionist* new_Receptionist(char* name, char* surname, int id);
void freeReceptionist(Receptionist* receptionist);

void giveInfo(Hotel* hotel);
void showReservationsList(Admin* admin);

#endif //CFROMJAVA_RECEPTIONIST_H
