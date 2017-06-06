#ifndef CFROMJAVA_LICENSE_H
#define CFROMJAVA_LICENSE_H

/*
 * Description: The License struct contains an ID
 */
typedef struct license License;
struct license {
    int id;
};

// Functions
License* new_License(int id);
void freeLicense(License* license);

#endif //CFROMJAVA_LICENSE_H
