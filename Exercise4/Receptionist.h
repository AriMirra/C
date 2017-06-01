#ifndef CFROMJAVA_RECEPTIONIST_H
#define CFROMJAVA_RECEPTIONIST_H

typedef struct receptionist Receptionist;
struct receptionist {
    char* name;
    char* surname;
    int id;
};

Receptionist* new_Receptionist(char* name, char* surname, int id);
void freeReceptionist(Receptionist* receptionist);

void giveInfo(Receptionist* receptionist);

#endif //CFROMJAVA_RECEPTIONIST_H
