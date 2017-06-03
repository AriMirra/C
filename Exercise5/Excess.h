#ifndef CFROMJAVA_EXCESS_H
#define CFROMJAVA_EXCESS_H

typedef struct excess Excess;
struct excess {
    char* rentedMovies[2000];                    // A total of 2000 movies can be rented per day due to logistic limitations
    int rentedMoviesCounter;
    double income;
};

Excess* new_Excess();
void freeExcess(Excess* excess);

void showRentedMoviesList(Excess* excess);
void showTotalIncome(Excess* excess);

#endif //CFROMJAVA_EXCESS_H
