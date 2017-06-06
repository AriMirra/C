#include "Excess.h"
#include <malloc.h>
#include <stdio.h>

/*
 * Description: Contains the functions of the Excess struct
 */

/*
 * Description: Creates a new Excess
 * Returns: The Excess created
 */
Excess* new_Excess() {

    Excess* excess = malloc(sizeof(Excess));

    excess->income = 0;
    excess->rentedMoviesCounter = 0;

    return excess;
}

/*
 * Description: Prints a list of the rented movies
 * Returns: Void
 */
void showRentedMoviesList(Excess* excess) {
    for (int i = 0; i < excess->rentedMoviesCounter; i++) {
        printf("\n#%s\n", excess->rentedMovies[i]);
    }
}

/*
 * Description: Shows the total income
 * Returns: Void
 */
void showTotalIncome(Excess* excess) {
    printf("\n$%.2f\n", excess->income);
}

/*
 * Description: Frees the space of memory assigned for an excess and all its components
 * Returns: Void
 */
void freeExcess(Excess* excess) {
    free(excess);
}
