#ifndef CFROMJAVA_EXCESS_H
#define CFROMJAVA_EXCESS_H

typedef struct excess Excess;
struct excess {
    char* rentedMovies[500];                    // A total of 500 movies can be rented per day due to logistic limitations
    double income;
};

Excess* new_Excess();
void freeExcess(Excess* excess);

#endif //CFROMJAVA_EXCESS_H
