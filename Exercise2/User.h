#ifndef CFROMJAVA_USER_H
#define CFROMJAVA_USER_H

typedef struct User{
    char* name;
    char* dni;
    char* address;
    char* telephone;
    char* city;
    char* province;
    char* country;
    char* postalCode;

}User;

//functions
User* createUser(char* name,char* dni,char* address,char* telephone,
                 char* city,char* province,char* country,char* postalCode);
void destroyUser(User* user);

#endif //CFROMJAVA_USER_H
