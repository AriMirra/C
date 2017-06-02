#ifndef CFROMJAVA_RENTAL_H
#define CFROMJAVA_RENTAL_H

typedef struct rental Rental;
struct rental {
    char* movieName;
    int clientId;
    int rentalDays;
};

Rental* new_Rental(char* movieName, int clientId, int rentalDays);
void freeRental(Rental* rental);

#endif //CFROMJAVA_RENTAL_H
