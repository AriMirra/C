#include "Person.h"

#ifndef EXERCISE3_LOAN_H
#define EXERCISE3_LOAN_H

typedef struct loan Loan;
struct loan {
    Person* person;
    Material* material;
    int code;
    int rentDays;
};

Loan* new_Loan(Person* person, Material* material, int rentDays);
void freeLoan(Loan* loan);

void fee(Loan* loan);
void showInvoice(Loan* loan);

#endif //EXERCISE3_LOAN_H
