#include "License.h"
#include <malloc.h>

/*
 * Description: Contains the functions related to the License struct
 */

/*
 * Description: Creates a License
 * Returns: The License created
 */
License* new_License(int id) {

    License* license = malloc(sizeof(License));

    license->id = id;

    return license;
}

/*
 * Description: Frees the space of memory assigned for a license and all its components
 * Returns: Void
 */
void freeLicense(License* license) {
    free(license);
}
