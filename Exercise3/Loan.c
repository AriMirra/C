#include "Loan.h"
#include <malloc.h>
#include <memory.h>

Loan* new_Loan(Material* material, char* code, char* id, char* departureDate, char* arrivalDate) {

    Loan* loan = malloc(sizeof(Loan));

    loan->code = malloc(sizeof(char) * (strlen(code) + 1));
    loan->id = malloc(sizeof(char) * (strlen(id) + 1));
    loan->departureDate = malloc(sizeof(char) * (strlen(departureDate) + 1));
    loan->arrivalDate = malloc(sizeof(char) * (strlen(arrivalDate) + 1));

    strcpy(loan->code, code);
    strcpy(loan->id, id);
    strcpy(loan->departureDate, departureDate);
    strcpy(loan->arrivalDate, arrivalDate);

    return loan;
}

void fee(Person* person) {
    person->debt += 10;   // $10 per loan
}

void freeLoan(Loan* loan) {
    free(loan->code);
    free(loan->id);
    free(loan->departureDate);
    free(loan->arrivalDate);
    free(loan);
}
