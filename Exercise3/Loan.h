#include "Person.h"

#ifndef EXERCISE3_LOAN_H
#define EXERCISE3_LOAN_H

typedef struct loan Loan;
struct loan {
    Material* material;
    char* code;
    char* id;
    char* departureDate;
    char* arrivalDate;
};

Loan* new_Loan(Material* material, char* code, char* id, char* departureDate, char* arrivalDate);
void freeLoan(Loan* loan);

void fee(Person* person);

#endif //EXERCISE3_LOAN_H
