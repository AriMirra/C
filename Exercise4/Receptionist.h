#ifndef CFROMJAVA_RECEPTIONIST_H
#define CFROMJAVA_RECEPTIONIST_H

#include "Hotel.h"
#include "Admin.h"
/*
 * Description:
 */
typedef struct Receptionist {
    char* name;
    char* surname;
    int id;
}Receptionist;

Receptionist* new_Receptionist(char* name, char* surname, int id);
void freeReceptionist(Receptionist* receptionist);

void giveInfo(Hotel* hotel);
void showReservationsList(Admin* admin);

#endif //CFROMJAVA_RECEPTIONIST_H
