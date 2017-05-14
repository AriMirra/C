
/*
    Description: Header file that describes the Car ADT.
*/

#ifndef CAR_H
#define CAR_H

// ~~~~~ Structs ~~~~~

typedef struct car Car;

struct car{

    char* licensePlate; // represents the Car's license plate
    char* model; // represents the Car's model
    char* color; // representes the Car's color
};

// ~~~~~ Function Prototypes ~~~~~

Car* createCar(char* licensePlate, char* model, char* color);
void destroyCar(Car* car);
int equals(Car* car1, Car* car2);
void printCar(Car* car); // only used for debugging

#endif /* CAR_H */
