#include <stdio.h>
#include <malloc.h>
#include "Database.h"
#include "../Util/ScanUtil.h"
/*
 * Description: asks for the details of a User, creates one and adds them to the database
 * Returns: void
 */
void userMenu(DataBase* database){
    printf("Register a User:\n");
    printf("Name:\n");
    char* name = scanChar();
    printf("\n");
    printf("DNI:\n");
    char* dni= scanChar();
    printf("\n");
    printf("Address:\n");
    char* address = scanChar();
    printf("\n");
    printf("Phone:\n");
    char* phone = scanChar();
    printf("\n");
    printf("City:\n");
    char* city = scanChar();
    printf("\n");
    printf("Province:\n");
    char* province = scanChar();
    printf("\n");
    printf("Country:\n");
    char* country = scanChar();
    printf("\n");
    printf("Postal code:\n");
    char* postalCode = scanChar();
    printf("\n");
    User* user = createUser(name,dni,address,phone,city,province,country,postalCode);
    addUser(database,user);
    printf("Your account has been created successfully, welcome %s\n\n", user->name);
    free(name);
    free(dni);
    free(address);
    free(phone);
    free(city);
    free(province);
    free(country);
    free(postalCode);
}
