#include <stdio.h>
#include "Admin.h"
#include "../Util/ScanUtil.h"

int main() {

    Admin* admin = new_Admin();

    Hotel* hotel = new_Hotel();

    printf("To select an action, press de number on its left\n");

    int user;
    while (1) {
        int canGoToMainMenu = 0;
        printf("\nLog In");
        printf("\n0. Admin");
        printf("\n1. Receptionist");
        printf("\n2. Client");
        printf("\n3. Exit\n\n");
        user = scanInt();
        if (user == 0) {
            // Admin
            printf("\n0. Set hotel name");
            printf("\n1. Show receptionists list");
            printf("\n2. Show clients list");
            printf("\n3. Go back to main menu\n\n");
            int adminChoice;
            while (!canGoToMainMenu) {
                adminChoice = scanInt();
                if (adminChoice == 0) {
                    printf("\nEnter the new hotel name here: ");
                    char* hotelName = scanChar();
                    setHotelName(hotel, hotelName);
                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else if (adminChoice == 1) {
                    if (admin->receptionistsCounter == 0) {
                        printf("\nThere are not any receptionists registered\n");
                    } else {
                        showReceptionistsList(admin);
                        printf("\nOperation successful\n");
                    }
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else if (adminChoice == 2) {
                    if (admin->clientsCounter == 0) {
                        printf("\nThere are not any clients registered\n");
                    } else {
                        showClientsList(admin);
                        printf("\nOperation successful\n");
                    }
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else if (adminChoice == 3) canGoToMainMenu = 1;
                else printf("\nPlease enter a valid option\n");
            }
        } else if (user == 1) {
            // Receptionist
            printf("\n0. Sign Up");
            printf("\n1. Log In");
            printf("\n2. Go back to main menu\n\n");
            int enteringReceptionistAccount;
            while (!canGoToMainMenu) {
                enteringReceptionistAccount = scanInt();
                if (enteringReceptionistAccount == 0) {
                    printf("\nEnter the following information about you: \n");
                    printf("\nName: ");
                    char* receptionistName = scanChar();
                    printf("Surname: ");
                    char* receptionistSurname = scanChar();
                    printf("ID: ");
                    int receptionistId;
                    int hasChanged = 0;
                    while (1) {
                        receptionistId = scanInt();
                        for(int i = 0; i < admin->receptionistsCounter; i++) {
                            if (admin->receptionistsList[i]->id == receptionistId) {
                                printf("\nThat ID has already been used. Please, try again using another one.\n\n");
                                break;
                            } else if (i == admin->receptionistsCounter - 1) {
                                hasChanged = 1;
                            }
                        }
                        if (admin->receptionistsCounter == 0 || hasChanged) break;
                    }

                    Receptionist* receptionist = new_Receptionist(receptionistName, receptionistSurname, receptionistId);

                    addReceptionist(admin, receptionist);

                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    break;
                } else if (enteringReceptionistAccount == 1) {
                    printf("\nEnter your ID, or press '1' to return to the main menu\n\n");
                    int receptionistLocation = 0;
                    int changed = 0;
                    int receptionistId;
                    while (!canGoToMainMenu) {
                        receptionistId = scanInt();
                        if (receptionistId == 1) {
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                        } else {
                            for(int i = 0; i < admin->receptionistsCounter; i++) {
                                if (admin->receptionistsList[i]->id == receptionistId) {
                                    receptionistLocation = i;
                                    changed = 1;
                                    break;
                                }
                                if (i == admin->receptionistsCounter - 1) {
                                    printf("\nThe ID is not registered. Please, try again using another one.\n\n");
                                }
                            }
                            if (admin->receptionistsCounter == 0) {
                                printf("\nThe ID is not registered. Please, try again.\n\n");
                            }
                            if (changed) break;
                        }
                    }

                    if (canGoToMainMenu) break;

                    Receptionist* loggedReceptionist = admin->receptionistsList[receptionistLocation];

                    printf("\n0. Show reservations list");
                    printf("\n1. Go back to main menu\n\n");
                    int option;
                    while (!canGoToMainMenu) {
                        option = scanInt();
                        if (option == 0) {
                            showReservationsList(admin);
                            printf("\nOperation successful\n");
                        } else if (option == 1) {
                            // continue to main menu
                        } else printf("\nPlease enter a valid option\n\n");
                        printf("\nReturning to Main Menu\n");
                        canGoToMainMenu = 1;
                    }
                } else if (enteringReceptionistAccount == 2) canGoToMainMenu = 1;
                else printf("\nPlease enter a valid option\n\n");
            }
        } else if (user == 2) {
            // Client
            printf("\n0. Sign Up");
            printf("\n1. Log In");
            printf("\n2. Go back to main menu\n\n");
            int enteringClientAccount;
            while (!canGoToMainMenu) {
                enteringClientAccount = scanInt();
                if (enteringClientAccount == 0) {
                    printf("\nEnter the following information about you: \n");
                    printf("\nName: ");
                    char *clientName = scanChar();
                    printf("Surname: ");
                    char *clientSurname = scanChar();
                    printf("ID: ");
                    int clientId;
                    int hasChanged = 0;
                    while (1) {
                        clientId = scanInt();
                        for (int i = 0; i < admin->clientsCounter; i++) {
                            if (admin->clientsList[i]->id == clientId) {
                                printf("\nThat ID has already been used. Please, try again using another one.\n\n");
                                break;
                            } else if (i == admin->clientsCounter - 1) {
                                hasChanged = 1;
                            }
                        }
                        if (admin->clientsCounter == 0 || hasChanged) break;
                    }

                    Client *client = new_Client(clientName, clientSurname, clientId);

                    addClient(admin, client);

                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    break;
                } else if (enteringClientAccount == 1) {
                    printf("\nEnter your ID, or press '1' to return to the main menu\n\n");
                    int clientLocation = 0;
                    int changed = 0;
                    int clientId;
                    while (!canGoToMainMenu) {
                        clientId = scanInt();
                        if (clientId == 1) {
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                        } else {
                            for(int i = 0; i < admin->clientsCounter; i++) {
                                if (admin->clientsList[i]->id == clientId) {
                                    clientLocation = i;
                                    changed = 1;
                                    break;
                                }
                                if (i == admin->clientsCounter - 1) {
                                    printf("\nThe ID is not registered. Please, try again using another one.\n\n");
                                }
                            }
                            if (admin->clientsCounter == 0) {
                                printf("\nThe mail is not registered. Please, try again.\n\n");
                            }
                            if (changed) break;
                        }
                    }

                    if (canGoToMainMenu) break;

                    Client* loggedClient = admin->clientsList[clientLocation];

                    printf("\n0. Ask for information");
                    printf("\n1. Generate reservation");
                    printf("\n2. Show my debt\n\n");
                    int option;
                    while (!canGoToMainMenu) {
                        option = scanInt();
                        if (option == 0) {
                            askForInfo(hotel);
                            printf("\nOperation successful\n");
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                        } else if (option == 1) {
                            printf("\nSelect your choice of room");
                            printf("\n0. Basic Room");
                            printf("\n1. Deluxe Room\n\n");
                            int roomOption;
                            while (!canGoToMainMenu) {
                                roomOption = scanInt();
                                if (roomOption == 0) {
                                    addReservation(admin, bookBasicRoom(loggedClient, hotel));
                                    Invoice* invoice = new_Invoice(hotel->name, loggedClient->name, loggedClient->id, hotel->basicRoomPrice);
                                    addInvoice(admin, invoice);
                                    payForRoom(invoice, loggedClient);
                                    printf("\nDo you wish to print the invoice?");
                                    printf("\n0. Yes");
                                    printf("\n1. No\n\n");
                                    int wantInvoice;
                                    while (1) {
                                        wantInvoice = scanInt();
                                        if (wantInvoice == 0) {
                                            printInvoice(invoice);
                                            break;
                                        } else if (wantInvoice == 1) {
                                            break;
                                        } else printf("\nPlease, enter a valid option.\n\n");
                                    }
                                    printf("\nOperation successful\n");
                                    printf("\nReturning to Main Menu\n");
                                    canGoToMainMenu = 1;
                                } else if (roomOption == 1) {
                                    addReservation(admin, bookDeluxeRoom(loggedClient, hotel));
                                    Invoice* invoice = new_Invoice(hotel->name, loggedClient->name, loggedClient->id, hotel->deluxeRoomPrice);
                                    addInvoice(admin, invoice);
                                    payForRoom(invoice, loggedClient);
                                    printf("\nDo you wish to print the invoice?");
                                    printf("\n0. Yes");
                                    printf("\n1. No\n\n");
                                    int wantInvoice;
                                    while (1) {
                                        wantInvoice = scanInt();
                                        if (wantInvoice == 0) {
                                            printInvoice(invoice);
                                            break;
                                        } else if (wantInvoice == 1) {
                                            break;
                                        } else printf("\nPlease, enter a valid option.\n\n");
                                    }
                                    printf("\nOperation successful\n");
                                    printf("\nReturning to Main Menu\n");
                                    canGoToMainMenu = 1;
                                } else printf("\nPlease enter a valid option\n");
                            }
                        } else if (option == 2) {
                            printf("\nYour total debt is: %.2f\n\n", loggedClient->debt);
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                        } else printf("\nPlease enter a valid option\n");
                    }
                } else if (enteringClientAccount == 2) {
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else printf("\nPlease enter a valid option\n");
            }
        } else if (user == 3) {
            for (int i = 0; i < admin->receptionistsCounter; i++) {
                freeReceptionist(admin->receptionistsList[i]);
            }
            for (int i = 0; i < admin->clientsCounter; i++) {
                freeClient(admin->clientsList[i]);
            }
            for (int i = 0; i < admin->reservationCounter; i++) {
                freeReservation(admin->reservationsList[i]);
            }
            for (int i = 0; i < admin->invoiceCounter; i++) {
                freeInvoice(admin->invoicesList[i]);
            }
            freeAdmin(admin);
            for (int i = 0; i < sizeof(hotel->roomList) / sizeof(hotel->roomList[0]); i++) {
                freeRoom(hotel->roomList[i]);
            }
            freeHotel(hotel);
            printf("\nExit successful\n\n");
            break;
        } else printf("\nPlease enter a valid option\n");
    }

    return 0;
}
