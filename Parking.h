#ifndef CFROMJAVA_PARKING_H
#define CFROMJAVA_PARKING_H

#include "Car.h"

typedef struct parking Parking;

struct parking{
    Car cars[10];
    int maxCapacity;
    int amountOfCars;
};

// Car *p = malloc(sizeof(Car) *initialCapacity

void parkCar(Parking parking, Car car);
Car removeCar(Parking parking, int spot);
int isCarParked(Parking parking, Car car);
int getCarSpot(Parking parking, Car car);
int isEmpty(Parking parking);
int getAmountOfCars(Parking parking);


#endif //CFROMJAVA_PARKING_H
