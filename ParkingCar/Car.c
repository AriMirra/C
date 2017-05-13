#include "Car.h"

int equals(Car car1, Car car2){
    for (int i = 0; i<10; i++){
        if(car1.licensePlate[i] != car2.licensePlate[i]) return 0;
    }
    return 1;
}