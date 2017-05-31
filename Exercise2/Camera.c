#include "Camera.h"
#include <stdlib.h>
#include <string.h>
/*
 * Contains functions related to the camera structure
 */

/*
 * Function: createCamera
 * Description: creates a new Camera from the given data.
 * Returns: void
 */
Camera* createCamera(char *name, int megaPixels, int zoom, int ldcDisplay, CameraType cameraType, int price){
    Camera* result = malloc(sizeof(Camera));
    result->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(result->name, name);
    result->megaPixels = megaPixels;
    result->zoom = zoom;
    result->ldcDisplay = ldcDisplay;
    result->cameraType = cameraType;
    result->price = price;
    result->accessoryList = createStaticList(3);
    return result;
}

/*
 * Function: containsAccessory
 * Description: checks if a camera has the accessory passed
 * Returns: the index of the accessory in the accessory list on the camera, -1 if not found
 */
//deleted static
int containsAccessory(Camera* camera, int accessoryID){
    StaticList* list = camera->accessoryList;
    for(int i = 0; i < list->size; i++){
        goTo(list, 0);
        if(getActual(list) == accessoryID) {
            return i;
        }
    }
    return -1;
}

/*
 * Function: addCameraAccessory
 * Description: adds an accessory id to the camera's accessory list, if not added already
 * Returns: void
 */
void addCameraAccessory(Camera* camera, int accessoryID){
    if(containsAccessory(camera, accessoryID) == -1) {
        StaticList *list = camera->accessoryList;
        goLast(list);
        addNext(list, accessoryID);
    }
}

/*
 * Function: removeCameraAccessory
 * Description: removes an accessory id from the camera's accessory list.
 * Returns: void
 */
void removeCameraAccessory(Camera* camera, int accessoryID){
    int accessoryIndex = containsAccessory(camera, accessoryID);
    if(accessoryIndex != -1){
        StaticList* list = camera->accessoryList;
        goTo(list, accessoryIndex);
        removeS(list);
    }
}

/*
 * Function: destroyCamera
 * Description: deallocates all memory assigned to the camera and it's components.
 * Returns: void
 */
void destroyCamera(Camera* camera){
    free(camera->name);
    freeStaticList(camera->accessoryList);
    free(camera);
}
