#include "Loan.h"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <time.h>

Loan* new_Loan(Person* person, Material* material, int rentDays) {

    Loan* loan = malloc(sizeof(Loan));

    srand((unsigned int) time(NULL));
    int code = (rand() % (1000000000 - 100000000)) + 100000000;     // Random number of 9 digits (between 100000000 and 999999999)

    loan->person = person;
    loan->material = material;
    loan->code = code;
    loan->rentDays = rentDays;

    return loan;
}

void fee(Loan* loan) {
    loan->person->debt += loan->material->costPerDay * loan->rentDays;
}

void showInvoice(Loan* loan) {
    printf("\n/Loan/");
    printf("\nCode of transaction: %i", loan->code);
    printf("\n/Customer information/");
    printf("\nName : %s", loan->person->name);
    printf("\nSurname : %s", loan->person->surname);
    printf("\nProfession: %s", loan->person->personType);
    if (strcmp(loan->person->personType, "Student") == 0) printf("\nRegistration Number: %i", loan->person->registrationNumber);
    else printf("\nEmployee Number: %i", loan->person->employeeNumber);
    printf("\nMail: %s", loan->person->mail);
    printf("\nPhone number: %i", loan->person->phoneNumber);
    printf("\nThis debt: $%.2f", loan->material->costPerDay * loan->rentDays);
    printf("\n/Rented material information/");
    printf("\nType: %s", loan->material->materialType);
    if (strcmp(loan->material->materialType, "Book") == 0) printf("\nEditorial: %s", loan->material->editorial);
    printf("\nTitle: %s", loan->material->title);
    printf("\nAuthor: %s", loan->material->author);
    printf("\nYear: %i", loan->material->year);
    printf("\nCode: %s", loan->material->code);
    printf("\nCost per day: $%.2f", loan->material->costPerDay);
    printf("\nDays rented: %i\n", loan->rentDays);
}

void freeLoan(Loan* loan) {
    free(loan);
}
