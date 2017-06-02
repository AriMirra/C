#ifndef CFROMJAVA_LICENSE_H
#define CFROMJAVA_LICENSE_H

typedef struct license License;
struct license {
    int id;
};

License* new_License(int id);
void freeLicense(License* license);

#endif //CFROMJAVA_LICENSE_H
