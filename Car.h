#ifndef CFROMJAVA_CAR_H
#define CFROMJAVA_CAR_H

typedef struct car Car;

struct car{
    char licensePlate[10];
    char model[10];
    char color[10];
};

int equals(Car car1, Car car2);


#endif //CFROMJAVA_CAR_H
