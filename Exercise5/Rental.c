#include "Rental.h"
#include <malloc.h>
#include <memory.h>

Rental* new_Rental(char* movieName, int clientId, int rentalDays) {

    Rental* rental = malloc(sizeof(Rental));

    rental->movieName = malloc(sizeof(char) * (strlen(movieName) + 1));
    rental->clientId = clientId;
    rental->rentalDays = rentalDays;

    strcpy(rental->movieName, movieName);

    return rental;
}

void freeRental(Rental* rental) {
    free(rental->movieName);
    free(rental);
}
