#ifndef EXERCISE3_LOAN_H
#define EXERCISE3_LOAN_H

#include "Person.h"

/*
 * Description: The Loan structure holds the information for a loan, the customer, the rented material, a random code, and the
 * days it was rented
 */
typedef struct loan Loan;
struct loan {
    Person* person;
    Material* material;
    int code;
    int rentDays;
};

// Functions
Loan* new_Loan(Person* person, Material* material, int rentDays);
void freeLoan(Loan* loan);

void fee(Loan* loan);
void showInvoice(Loan* loan);

#endif //EXERCISE3_LOAN_H
