#ifndef CFROMJAVA_ADMIN_H
#define CFROMJAVA_ADMIN_H

typedef struct admin Admin;
struct admin {
    char* name;
    char* surname;
    int id;
};

Admin* new_Admin(char* name, char* surname, int id);
void freeAdmin(Admin* admin);

#endif //CFROMJAVA_ADMIN_H
