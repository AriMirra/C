
/*
    Description: C file that contains the functions related to the Parking ADT.
*/

#include "Parking.h"
#include <stdlib.h>
#include <stdio.h>

/*
    Function: createParking
    Description: allocates memory for a Car and all it's components.
    Returns: Parking pointer
*/

Parking* createParking(int initialCapacity){

    Parking* parking = malloc(sizeof(Parking)); // allocate memory for the Parking

    /*
        memory is allocated for each of the variables of Parking
    */
    parking->maxCapacity = initialCapacity;
    parking->amountOfCarsParked = 0;

    /*
        As cars si a POINTER ARRAY (Car**), sizeof will have (Car*) as argument
        and not (Car) as Car pointers will be stored in the array, not Cars.
        See parkCar for more info.
    */
    parking->cars = malloc(sizeof(Car*)*initialCapacity);

    parking->spacesTaken = malloc(sizeof(int)*initialCapacity);
    return parking;
}

/*
    Function: freeParking
    Description: deallocates the memory used by the Parking and all it's information.
    Returns: -
*/

void freeParking(Parking* parking){

    for(int i = 0;i < parking->maxCapacity;i++){
        if(parking->spacesTaken) destroyCar(parking->cars[i]);
    }

    free(parking->cars);
    free(parking->spacesTaken);
    free(parking);
}

/*
    Function: grow
    Description: used to resize the arrays "cars" and "spacesTaken"
    Returns: -
*/

static void grow(Parking* parking){
    parking->cars = realloc(parking->cars, sizeof(Car*)*parking->maxCapacity*2);
    parking->spacesTaken= realloc(parking->spacesTaken, sizeof(int)*parking->maxCapacity*2);
    parking->maxCapacity = parking->maxCapacity*2;
}

/*
    Function: amountOfCarsParked
    Description: returns the amount of Cars parked in the given Parking
    Returns: int represent the amount of Cars parked in the given Parking
*/

int amountOfCarsParked(Parking* parking){
    return parking->amountOfCarsParked;
}

/*
    Function: isEmpty
    Description: determines whether the Parking is empty or not.
    Returns: 1 if TRUE, 0 if FALSE
*/

int isEmpty(Parking* parking){
    if(parking->amountOfCarsParked == 0) return 1;
    return 0;
}

/*
    Function: parkCar
    Description: fills an entry of the array cars with a Car* that has already
    been initialized and correctly assigned.
        The user is responsible for having correctly initialized the Car with
    the createCar function.
        If the array is full, it resizes it, if not it inserts it in the first available
    spot signaled by the "spacesTaken" array.
    Returns: 1 if TRUE, 0 if FALSE
*/

void parkCar(Parking* parking, Car* car){
    if(amountOfCarsParked(parking) == parking->maxCapacity){
        grow(parking);
        parking->cars[parking->amountOfCarsParked] = car;
        parking->spacesTaken[parking->amountOfCarsParked] = 1;
    }else{
        for(int i = 0;i< parking->maxCapacity;i++){
            if(parking->spacesTaken[i] == 0){
                parking->cars[i] = car;
                parking->spacesTaken[i] = 1;
                break;
            }
        }
    }
    parking->amountOfCarsParked++;
}

/*
    Function: removeCar
    Description: removes a Car* from Car** cars. The user is responsible for
    deallocating the memory pointed by the Car* that is returned.

        THIS METHOD DOES NOT DEALLOCATE THE MEMORY OF THE CAR THAT IS RETURNED.

        The entry number of the Car removed (spot) is also used to change the state
    of spacesTakes[spot] to 0 a.k.a FALSE.
        The function signals the program to exit if the spot passed as parameter is
        not valid: the space doesn't have a car and spot is bigger than the array's
        max capacity.
    Returns: Car pointer (Car*)
*/

Car* removeCar(Parking* parking, int spot){
    if(parking->spacesTaken[spot] && spot < parking->maxCapacity){
        parking->spacesTaken[spot] = 0;
        Car* result = parking->cars[spot];
        parking->amountOfCarsParked--;
        return result;
    }
    exit(2);
}

/*
    Function: isCarParked
    Description: determines whether the Car is in the Parking. Checks if the Car*
    passed as parameter is located in the Car** array (cars).
        Uses the getCarSpot function to operate.
        See getCarSpot for more info.
    Returns: 1 if TRUE, 0 if FALSE
*/

int isCarParked(Parking* parking, Car* car){
    if(getCarSpot(parking,car) != -1) return 1;
    return 0;
}

/*
    Function: getCarSpot
    Description: returns the spot in which the Car* passed as parameter is located
    in the Car** cars.
    Returns: -1 if the Car* is not located in the array, an int representing the location
    of the Car pointer in the array if it is.
*/

int getCarSpot(Parking* parking, Car* car){
    for(int i = 0;i< parking->maxCapacity;i++){
        if(parking->spacesTaken[i] != 0 && equals(car, parking->cars[i])) return i;
    }
    return -1;
}

/*
    Function: printParking
    Description: outputs the Parking's information on the console
    Returns: -
*/

void printParking(Parking* parking){
    printf("Amount of cars parked: %d\n", parking->amountOfCarsParked);
    for(int i = 0;i < parking->maxCapacity; i++){
        if(parking->spacesTaken[i] == 1){
            printf("%d ", i);
            printCar(parking->cars[i]);
        }
    }
}
