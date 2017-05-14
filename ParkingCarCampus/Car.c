
/*
    Description: C file that contains the functions related to the Car ADT.
    Car manages all it's memory.
*/

#include "Car.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
    Function: createCar
    Description: allocates memory for a Car and all it's components.
    Returns: Car pointer
*/

Car* createCar(char* licensePlate, char* model, char* color){

    Car* result = malloc(sizeof(Car)); // allocate memory for the Car

    /*
        memory is allocated for each of the variables in Car.

        The strlen(char* a) function returns the length of the
        sequence of characters of a. This function is located in
        string.h
    */
    result->licensePlate = malloc(sizeof(char)*strlen(licensePlate));
    result->model = malloc(sizeof(char)*strlen(model));
    result->color = malloc(sizeof(char)*strlen(color));

    /*
        The strings passed as parameters are copied into the memory spaces
        pointed by the pointers of Car.

        The function strcpy(char* destination, char* origin) copies the string
        from origin into destination.
    */
    strcpy(result->licensePlate, licensePlate);
    strcpy(result->model, model);
    strcpy(result->color, color);

    return result;

}

/*
    Function: equals
    Description: determines whether the 2 Cars are equal or not. Used the
    strcmp function to compare the licensePlate strings of each of the cars.

        The strcmp function is located in string.h and return 0 if the 2 strings
    are equal, -1 if the first is smaller than the second and 1 if the first is
    bigger than the second.

    Returns: 1 if TRUE, 0 if FALSE.
*/

int equals(Car* car1, Car* car2){
    if(strcmp(car1->licensePlate, car2->licensePlate) == 0) return 1;
    return 0;
}

/*
    Function: destroyCar
    Description: frees all allocated memory related to Car.
    Returns: -
*/

void destroyCar(Car* car){
    free(car->licensePlate);
    free(car->model);
    free(car->color);
    free(car); // Car* car must always be freed last. If not, the previous free's will not be possible.
}

/*
    Function: printCar
    Description: outputs the Car's information on the console
    Returns: -
*/

void printCar(Car* car){
    printf("%s", car->licensePlate);
    printf("%s", car->model);
    printf("%s\n", car->color);
}
