#ifndef CFROMJAVA_RECEPTIONIST_H
#define CFROMJAVA_RECEPTIONIST_H

#include "Hotel.h"

/*
 * Description: The Receptionist structure contains the information about the receptionist, such as his name, surname, and ID
 */
typedef struct Receptionist {
    char* name;
    char* surname;
    int id;
}Receptionist;

// Functions
Receptionist* new_Receptionist(char* name, char* surname, int id);
void freeReceptionist(Receptionist* receptionist);

void giveInfo(Hotel* hotel);

#endif //CFROMJAVA_RECEPTIONIST_H
