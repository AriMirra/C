#ifndef CFROMJAVA_CAMERA_H
#define CFROMJAVA_CAMERA_H

/*
 * Description: Represents a camera
 */
typedef enum{DSLR, COMPACT} CameraType;

typedef struct Camera{
    char* name;
    int productID;
    int megaPixels;
    int zoom;
    int hasLCD;
    CameraType cameraType;
    StaticList* accessoryList;
}Camera;

Camera* newCamera(char* name, int megaPixels, int zoom, int hasLCD, CameraType cameraType);
void addCameraAccessory(Camera* camera, int accessoryID);
void removeCameraAccessory(Camera* camera, int accessoryID);
void destroyCamera(Camera* camera);

#endif //CFROMJAVA_CAMERA_H
