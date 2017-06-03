#include "Excess.h"
#include <malloc.h>
#include <stdio.h>

Excess* new_Excess() {

    Excess* excess = malloc(sizeof(Excess));

    excess->income = 0;
    excess->rentedMoviesCounter = 0;

    return excess;
}

void showRentedMoviesList(Excess* excess) {
    for (int i = 0; i < excess->rentedMoviesCounter; i++) {
        printf("\n#%s\n", excess->rentedMovies[i]);
    }
}

void showTotalIncome(Excess* excess) {
    printf("\n$%.2f\n", excess->income);
}

void freeExcess(Excess* excess) {
    free(excess);
}
