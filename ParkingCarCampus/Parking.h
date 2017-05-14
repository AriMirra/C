
/*
    Description: Header file that describes the Parking ADT.
*/

#ifndef PARKING_H
#define PARKING_H

#include "Car.h"

// ~~~~~ Structs ~~~~~

typedef struct parking Parking;

struct parking{

    Car** cars; // Array of pointers to Cars
    int amountOfCarsParked; // represents the size of the parking
    int maxCapacity; // auxiliary variable to handle the Car** size.
    int* spacesTaken; // boolean array to avoid shifting in removeCar()
};

// ~~~~~ Function Prototypes ~~~~~

Parking* createParking(int initialCapacity);
void freeParking(Parking* parking);
int amountOfCarsParked(Parking* parking);
int isEmpty(Parking* parking);
void parkCar(Parking* parking, Car* car);
Car* removeCar(Parking* parking, int spot);
int isCarParked(Parking* parking, Car* car);
int getCarSpot(Parking* parking, Car* car);
void printParking(Parking* parking);


#endif /* PARKING_H */
