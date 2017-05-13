#include <stdlib.h>
#include "Parking.h"

void parkCar(Parking parking, Car car){
    if(parking.amountOfCars<parking.maxCapacity){
        parking.cars[parking.amountOfCars] = car;
        parking.amountOfCars++;
    }
}

Car removeCar(Parking parking, int spot){
    if(parking.amountOfCars > spot){
        Car result = parking.cars[spot];
        for (int i = 0; i<parking.amountOfCars - 1; i++){//creo que tendría que ser desde i=spot, sinó te cambia todos los autos al pedo
            parking.cars[i] = parking.cars[i+1];
        }
        return result;
    }
    exit(2);
}

int isCarParked(Parking parking, Car car){
    //todo terminar de implementar
    for (int i = 0; i<parking.amountOfCars - 1; i++){
        parking.cars[i] = parking.cars[i+1];
    }
}

int getCarSpot(Parking parking, Car car){
    for (int i = 0; i<parking.amountOfCars; i++){
        if(equals(parking.cars[i],car)!=0){
            return i;
        }
    }
    return -1;
}

int isEmpty(Parking parking){
    if (parking.amountOfCars == 0) return 1;
    return 0;
}

int getAmountOfCars(Parking parking){
    return parking.amountOfCars;
}


