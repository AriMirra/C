#include "License.h"
#include <malloc.h>

License* new_License(int id) {

    License* license = malloc(sizeof(License));

    license->id = id;

    return license;
}

void freeLicense(License* license) {
    free(license);
}
