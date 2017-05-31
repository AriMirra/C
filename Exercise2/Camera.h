#ifndef CFROMJAVA_CAMERA_H
#define CFROMJAVA_CAMERA_H

#include "../Util/StaticList.h"

/*
 * Description: Represents a camera
 */
typedef enum{DSLR, COMPACT} CameraType;

typedef struct Camera{
    char* name;
    int productID;
    int megaPixels;
    int zoom;
    int ldcDisplay;
    CameraType cameraType;
    StaticList* accessoryList;
}Camera;

Camera* createCamera(char *name, int megaPixels, int zoom, int ldcDisplay, CameraType cameraType);
void addCameraAccessory(Camera* camera, int accessoryID);
void removeCameraAccessory(Camera* camera, int accessoryID);
void destroyCamera(Camera* camera);

#endif //CFROMJAVA_CAMERA_H
