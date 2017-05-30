#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "Library.h"
#include "Loan.h"
#include "ScanUtil.h"

int main() {

    Library* library = new_Library();

    int user;
    while (1) {
        int canGoToMainMenu = 0;
        printf("Press '0' if you want to log in as an admin, '1' to log in as a student, or '2' to exit the program ");
        user = scanInt();
        if (user == 0) {
            // Admin
            printf("If you want to upload a new material, press '0'. If you want to modify an already existing one, press '1'");
            int adminChoice;
            while (!canGoToMainMenu) {
                adminChoice = scanInt();
                if (adminChoice == 0) {
                    printf("\n\nPress '0' if you want to upload a magazine, or '1' to upload a book: ");
                    int materialType;
                    char* editorial = 0;
                    while (1) {
                        materialType = scanInt();
                        if (materialType == 0) {
                            printf("\nFill in the next information about the magazine: \n");
                            break;
                        } else if (materialType == 1) {
                            printf("\nFill in the next information about the book: ");
                            printf("\nEditorial: ");
                            editorial = scanChar();
                            break;
                        } else printf("Please, enter a valid option\n");
                    }
                    printf("Code: ");
                    char* materialCode = scanChar();
                    printf("Author: ");
                    char* materialAuthor = scanChar();
                    printf("Title: ");
                    char* materialTitle = scanChar();
                    printf("Year: ");
                    int materialYear = scanInt();
                    printf("Press '0' if the material is currently unavailable, or '1' otherwise: ");
                    int materialStatus;
                    while (1) {
                        materialStatus = scanInt();
                        if (materialStatus == 0 || materialStatus == 1) break;
                        else printf("Please, enter a valid option\n");
                    }
                    printf("How much do you wish to charge for this material per day? $");
                    int materialCostPerDay;
                    while (1) {
                        materialCostPerDay = scanInt();
                        if (materialCostPerDay > 0 ) break;
                        else printf("Please, enter a price greater than 0\n");
                    }

                    Material* material = new_Material(materialCode, materialAuthor, materialTitle, materialYear, materialType, materialStatus, materialCostPerDay);

                    if (editorial != 0) {
                        material->editorial = malloc(sizeof(char) * (strlen(editorial) + 1));
                        strcpy(material->editorial, editorial);
                    }

                    loadMaterial(library, material);

                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else if (adminChoice == 1) {
                    printf("Which one of the following materials you want to modify?");
                    printMaterialsList(library);
                    int materialOption;
                    while (1) {
                        materialOption = scanInt();
                        if (materialOption >= 0 || materialOption < library->materialsCounter) break;
                        else printf("Please, enter a valid option\n");
                    }
                    printf("Press '0' if you want to delete the material, '1' to change its status, or '2' to change its rental cost per day ");
                    int modifyOption;
                    while (1) {
                        modifyOption = scanInt();
                        if (modifyOption == 0) {
                            deleteMaterial(library, materialOption);
                            break;
                        } else if (modifyOption == 1) {
                            changeMaterialStatus(library->materials[materialOption]);
                            break;
                        } else if (modifyOption == 2) {
                            printf("Enter the new price: $");
                            int newPrice;
                            while (1) {
                                newPrice = scanInt();
                                if (newPrice > 0) {
                                    library->materials[materialOption]->costPerDay = newPrice;
                                    break;
                                }
                                else printf("Please, enter a price greater than 0");
                            }
                        } else printf("Please, enter a valid option\n");
                    }

                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else printf("Please, enter a valid option\n");
            }
        } else if (user == 1) {
            // Customer
            printf("Enter the following information about you: ");
            printf("\nName: ");
            char* personName = scanChar();
            printf("Surname: ");
            char* personSurname = scanChar();
            printf("Mail: ");
            char* personMail = scanChar();
            printf("Phone number: ");
            int personPhoneNumber = scanInt();
            printf("Press '0' if you are a teacher, or '1' if you are a student: ");
            int personType;
            int registrationNumber = 0;
            int employeeNumber = 0;
            while (1) {
                personType = scanInt();
                if (personType == 0) {
                    printf("Enter your employee number: ");
                    employeeNumber = scanInt();
                    break;
                } else if (personType == 1) {
                    printf("Enter your registration number: ");
                    registrationNumber = scanInt();
                    break;
                } else printf("Please, enter a valid option\n");
            }

            Person* person = new_Person(personName, personSurname, personMail, personPhoneNumber, personType);

            if (registrationNumber != 0) {
                person->registrationNumber = registrationNumber;
            } else {
                person->employeeNumber = employeeNumber;
            }

            loadPerson(library, person);

            printf("\n\nPress '0' if you wish to take a new material, or '1' to return one: ");
            int option;
            while (!canGoToMainMenu) {
                option = scanInt();
                if (option == 0) {
                    printf("Choose one of the following:\n");
                    printMaterialsList(library);
                    int materialOption;
                    while (1) {
                        materialOption = scanInt();
                        if (materialOption >= 0 || materialOption < library->materialsCounter) {
                            if (library->materials[materialOption]->isAvailable) {
                                takeMaterial(person, library->materials[materialOption]);
                                break;
                            }
                            else {
                                printf("The chosen material is not available at the time. Please, select another one\n");
                                continue;
                            }
                        }
                        else printf("Please, enter a valid option\n");
                    }
                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                }
                else if (option == 1) {
                    printf("These are your current materials you are in possession of: \n");
                    showMyMaterials(person);
                    printf("\nSelect one of the above to delete: ");
                    int choice;
                    while (1) {
                        choice = scanInt();
                        if (choice >= 0 || choice < library->materialsCounter) {
                            leaveMaterial(person, choice);
                            break;
                        } else printf("Please, enter a valid option\n");
                    }
                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                }
                else printf("Please, enter a valid option\n");
            }
        } else if (user == 2) {
            // Exit
            /*
            freeLibrary(library);
            freePerson(person);
            freeMaterial(material);
            freeLoan(loan);
             */
            break;
        } else printf("Please enter a valid option\n");
    }

    return 0;
}
