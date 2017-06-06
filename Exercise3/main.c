#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "Library.h"
#include "../Util/ScanUtil.h"

/*
 * Description: Executes the simulation
 */
int main() {

    Library* library = new_Library();

    printf("To select an action, press de number on its left\n");

    int user;
    while (1) {
        int canGoToMainMenu = 0;
        printf("\nLog In");
        printf("\n0. Admin");
        printf("\n1. Customer");
        printf("\n2. Exit\n\n");
        user = scanInt();

        if (user == 0) {

            // Admin
            printf("\n0. Upload new material");
            printf("\n1. Modify an already existing one");
            printf("\n2. Show list of materials");
            printf("\n3. Show list of customers");
            printf("\n4. Go back to main menu\n\n");
            int adminChoice;
            while (!canGoToMainMenu) {
                adminChoice = scanInt();

                if (adminChoice == 0) {

                    // Upload a new material
                    printf("\nUpload");
                    printf("\n0. Magazine");
                    printf("\n1. Book\n\n");
                    int materialType;
                    char* editorial = 0;
                    while (1) {
                        materialType = scanInt();

                        if (materialType == 0) {

                            // Magazine
                            printf("\nFill in the next information about the magazine: \n\n");
                            break;

                        } else if (materialType == 1) {

                            // Book
                            printf("\nFill in the next information about the book: \n");
                            printf("\nEditorial: ");
                            editorial = scanChar();
                            break;
                        } else printf("\nPlease, enter a valid option.\n\n");
                    }
                    printf("Code: ");
                    char* materialCode = scanChar();
                    printf("Author: ");
                    char* materialAuthor = scanChar();
                    printf("Title: ");
                    char* materialTitle = scanChar();
                    printf("Year: ");
                    int materialYear = scanInt();
                    printf("\nHow much do you wish to charge for this material per day? $");
                    int materialCostPerDay;
                    while (1) {
                        materialCostPerDay = scanInt();
                        if (materialCostPerDay > 0 ) break;
                        else printf("\nPlease, enter a price greater than 0.\n\n");
                    }
                    printf("\nIs the material currently available? \n");
                    printf("\n0. No");
                    printf("\n1. Yes\n\n");
                    int materialStatus;
                    while (1) {
                        materialStatus = scanInt();
                        if (materialStatus == 0 || materialStatus == 1) break;
                        else printf("\nPlease, enter a valid option.\n\n");
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

                    // Modify an already existing material
                    if (library->materialsCounter == 0) {
                        printf("\nThere are not any materials registered.\n");
                    } else {
                        printf("\nWhich one of the following materials you want to modify? \n");
                        showAllMaterials(library);
                        printf("\n");
                        int materialOption;
                        while (1) {
                            materialOption = scanInt();
                            if (materialOption >= 0 && materialOption < library->materialsCounter) break;
                            else printf("\nPlease, enter a valid option.\n\n");
                        }
                        printf("\n0. Delete the material");
                        printf("\n1. Change its status");
                        printf("\n2. Change its rental cost");
                        printf("\n3. Go back to main menu\n\n");
                        int modifyOption;
                        while (!canGoToMainMenu) {
                            modifyOption = scanInt();

                            if (modifyOption == 0) {

                                // Delete the material
                                deleteMaterial(library, materialOption);

                            } else if (modifyOption == 1) {

                                // Change its status
                                changeMaterialStatus(library->materials[materialOption]);

                            } else if (modifyOption == 2) {

                                // Change its rental cost
                                printf("\nEnter the new price: $");
                                int newPrice;
                                while (1) {
                                    newPrice = scanInt();
                                    if (newPrice > 0) {
                                        library->materials[materialOption]->costPerDay = newPrice;
                                        break;
                                    }
                                    else printf("\nPlease, enter a price greater than 0.\n\n");
                                }
                            } else if (modifyOption == 3) {
                                // continue to main menu
                            } else printf("\nPlease, enter a valid option.\n\n");
                            printf("\nOperation successful\n");
                            canGoToMainMenu = 1;
                        }
                    }
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;

                } else if (adminChoice == 2) {

                    // Show list of materials
                    if (library->materialsCounter == 0) {
                        printf("\nThere are not any materials registered.\n");
                    } else {
                        showAllMaterials(library);
                        printf("\nOperation successful\n");
                    }
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;

                } else if (adminChoice == 3) {

                    // Show list of people
                    if (library->peopleCounter == 0) {
                        printf("\nThere are not any customers registered.\n");
                    } else {
                        printPeopleList(library);
                        printf("\nOperation successful\n");
                    }
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                    
                } else if (adminChoice == 4) canGoToMainMenu = 1;
                    
                    // Go back to main menu
                else printf("\nPlease, enter a valid option.\n\n");
            }
            
        } else if (user == 1) {
            
            // Customer
            printf("\n0. Sign Up");
            printf("\n1. Log In");
            printf("\n2. Go back to main menu\n\n");
            int enteringAccount;
            while (!canGoToMainMenu) {
                enteringAccount = scanInt();
                
                if (enteringAccount == 0) {
                    
                    // Sign Up
                    printf("\nEnter the following information about you: \n");
                    printf("\nName: ");
                    char* personName = scanChar();
                    printf("Surname: ");
                    char* personSurname = scanChar();
                    printf("Mail: ");
                    char* personMail;
                    int hasChanged = 0;
                    while (1) {
                        personMail = scanChar();
                        for(int i = 0; i < library->peopleCounter; i++) {
                            if (strcmp(library->people[i]->mail, personMail) == 0) {
                                printf("\nThe mail address has already been used. Please, try again using another one.\n\n");
                                break;
                            } else if (i == library->peopleCounter - 1) {
                                hasChanged = 1;
                            }
                        }
                        if (library->peopleCounter == 0 || hasChanged) break;
                    }
                    printf("Phone number: ");
                    int personPhoneNumber = scanInt();
                    printf("\nSelect your profession");
                    printf("\n0. Teacher");
                    printf("\n1. Student\n\n");
                    int personType;
                    int registrationNumber = 0;
                    int employeeNumber = 0;
                    while (1) {
                        personType = scanInt();
                        if (personType == 0) {
                            printf("\nEnter your employee number: ");
                            employeeNumber = scanInt();
                            break;
                        } else if (personType == 1) {
                            printf("\nEnter your registration number: ");
                            registrationNumber = scanInt();
                            break;
                        } else printf("\nPlease, enter a valid option.\n\n");
                    }

                    Person* person = new_Person(personName, personSurname, personMail, personPhoneNumber, personType);

                    if (registrationNumber != 0) {
                        person->registrationNumber = registrationNumber;
                    } else {
                        person->employeeNumber = employeeNumber;
                    }

                    loadPerson(library, person);

                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    break;
                    
                } else if (enteringAccount == 1) {
                    
                    // Log In
                    printf("\nEnter your mail, or press '1' to go back to the main menu\n\n");
                    int personLocation = 0;
                    int changed = 0;
                    char* personMail;
                    while (!canGoToMainMenu) {
                        personMail = scanChar();
                        if (strcmp(personMail, "1") == 0) {
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                        } else {
                            for(int i = 0; i < library->peopleCounter; i++) {
                                if (strcmp(library->people[i]->mail, personMail) == 0) {
                                    personLocation = i;
                                    changed = 1;
                                    break;
                                }
                                if (i == library->peopleCounter - 1) {
                                    printf("\nThe mail is not registered. Please, try again using another one.\n\n");
                                }
                            }
                            if (library->peopleCounter == 0) {
                                printf("\nThe mail is not registered. Please, try again.\n\n");
                            }
                            if (changed) break;
                        }
                    }

                    if (canGoToMainMenu) break;

                    Person* loggedPerson = library->people[personLocation];

                    printf("\n0. Take new material");
                    printf("\n1. Show my materials");
                    printf("\n2. Show my total debt\n\n");
                    int option;
                    while (!canGoToMainMenu) {
                        option = scanInt();
                        
                        if (option == 0) {
                            
                            // Take new material
                            if (library->materialsCounter == 0) {
                                printf("\nThere are not any materials available for you to take at the moment.\n");
                            } else {
                                printf("\nChoose one of the following:\n");
                                showAvailableMaterials(library);
                                printf("\n");
                                int materialOption;
                                getAvailableMaterials(library);
                                while (1) {
                                    materialOption = scanInt();
                                    if (materialOption >= 0 && materialOption < library->availableMaterials) {
                                        takeMaterial(loggedPerson, library->materials[materialOption]);
                                        printf("\nHow many days would you like to rent it for? ");
                                        int days;
                                        while (1) {
                                            days = scanInt();
                                            if (days > 0 && days <= 30) {
                                                Loan* loan = new_Loan(loggedPerson, library->materials[materialOption], days);
                                                loadLoan(library, loan);
                                                fee(loan);
                                                printf("\nDo you wish to print the invoice?");
                                                printf("\n0. Yes");
                                                printf("\n1. No\n\n");
                                                int wantInvoice;
                                                while (1) {
                                                    wantInvoice = scanInt();
                                                    if (wantInvoice == 0) {
                                                        showInvoice(loan);
                                                        break;
                                                    } else if (wantInvoice == 1) {
                                                        break;
                                                    } else printf("\nPlease, enter a valid option.\n\n");
                                                }
                                                break;
                                            } else {
                                                printf("\nThe minimum of days is 1, and de maximum is 30\n");
                                                printf("\nEnter a valid option\n\n");
                                            }
                                        }
                                        printf("\nOperation successful\n");
                                        break;
                                    }
                                    else printf("\nPlease, enter a valid option.\n\n");
                                }
                            }
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                            
                        } else if (option == 1) {
                            
                            // Show my materials
                            if (loggedPerson->materialsCounter == 0) {
                                printf("\nYou do not have any material at the moment.\n");
                                printf("\nReturning to Main Menu\n");
                            } else {
                                showMyMaterials(loggedPerson);
                                printf("\nOperation successful\n");
                                printf("\nReturning to Main Menu\n");
                            }
                            canGoToMainMenu = 1;
                            
                        } else if (option == 2) {
                            
                            // Show my total debt
                            printf("\n$%.2f\n", loggedPerson->debt);
                            printf("\nOperation successful\n");
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                        }
                        else printf("\nPlease, enter a valid option.\n\n");
                    }
                    
                } else if (enteringAccount == 2) {
                    
                    // Go back to main menu
                    canGoToMainMenu = 1;
                }
                else printf("\nPlease, enter a valid option.\n\n");
            }
            
        } else if (user == 2) {
            
            // Exit
            for (int i = 0; i < library->materialsCounter; i++) {
                freeMaterial(library->materials[i]);
            }
            for (int i = 0; i < library->peopleCounter; i++) {
                freePerson(library->people[i]);
            }
            for (int i = 0; i < library->loanCounter; i++) {
                freeLoan(library->loan[i]);
            }
            freeLibrary(library);
            printf("\nExit successful\n\n");
            break;
        } else printf("\nPlease enter a valid option\n");
    }

    return 0;
}
