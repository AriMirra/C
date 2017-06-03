#include <stdio.h>
#include "Admin.h"
#include "../Util/ScanUtil.h"

int main() {

    ClientsDatabase* clientsDatabase = new_ClientsDatabase();

    MoviesDatabase* moviesDatabase = new_MoviesDatabase();

    Excess* excess = new_Excess();

    printf("To select an action, press de number on its left\n");

    int adminAlreadyLoggedIn = 0;       // There is only one admin
    int user;
    while (1) {
        int canGoToMainMenu = 0;
        printf("\nLog In");
        printf("\n0. Admin");
        printf("\n1. Client");
        printf("\n2. Exit\n\n");
        user = scanInt();
        if (user == 0) {
            // Admin
            Admin *admin = NULL;
            if (!adminAlreadyLoggedIn) {
                printf("\nEnter the following information about you: \n");
                printf("\nName: ");
                char* adminName = scanChar();
                printf("Surname: ");
                char* adminSurname = scanChar();
                printf("ID: ");
                int adminId = scanInt();

                admin = new_Admin(adminName, adminSurname, adminId);

                printf("\nSign up successful\n");

                adminAlreadyLoggedIn = 1;
            }
            printf("\n0. Register client");
            printf("\n1. Register movie");
            printf("\n2. Show clients list");
            printf("\n3. Show available movies list");
            printf("\n4. Show rented movies list");
            printf("\n5. Show total income");
            printf("\n6. Go back to main menu\n\n");
            int adminAction;
            while (!canGoToMainMenu) {
                adminAction = scanInt();
                if (adminAction == 0) {
                    printf("\nEnter the next information about the client to register: \n");
                    printf("\nName: ");
                    char* clientName = scanChar();
                    printf("Surname: ");
                    char* clientSurname = scanChar();
                    printf("ID: ");
                    int clientId;
                    int hasChanged = 0;
                    while (1) {
                        clientId = scanInt();
                        for(int i = 0; i < clientsDatabase->counter; i++) {
                            if (clientsDatabase->clientsList[i]->id == clientId) {
                                printf("\nThat ID has already been used. Please, try again using another one.\n\n");
                                break;
                            } else if (i == clientsDatabase->counter - 1) {
                                hasChanged = 1;
                            }
                        }
                        if (clientsDatabase->counter == 0 || hasChanged) break;
                    }

                    Client* client = new_Client(clientName, clientSurname, clientId);

                    registerClient(admin, client, clientsDatabase);

                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    break;
                } else if (adminAction == 1) {
                    printf("\nEnter the next information about the movie to register: \n");
                    printf("\nName: ");
                    char* movieName = scanChar();
                    printf("Price: $");
                    double moviePrice = scanInt();

                    Movie* movie = new_Movie(movieName, moviePrice);

                    registerMovie(movie, moviesDatabase);

                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else if (adminAction == 2) {
                    if (clientsDatabase->counter == 0) {
                        printf("\nThere are not any clients registered.\n");
                    } else {
                        showClientsList(clientsDatabase);
                        printf("\nOperation successful\n");
                    }
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else if (adminAction == 3) {
                    if (moviesDatabase->counter == 0) {
                        printf("\nThere are not any movies registered.\n");
                    } else {
                        showMoviesList(moviesDatabase);
                        printf("\nOperation successful\n");
                    }
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else if (adminAction == 4) {
                    if (excess->rentedMoviesCounter == 0) {
                        printf("\nNo movie was rented yet.\n");
                    } else {
                        showRentedMoviesList(excess);
                        printf("\nOperation successful\n");
                    }
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else if (adminAction == 5) {
                    showTotalIncome(excess);
                    printf("\nOperation successful\n");
                    printf("\nReturning to Main Menu\n");
                    canGoToMainMenu = 1;
                } else if (adminAction == 6) {
                    canGoToMainMenu = 1;
                } else printf("\nPlease enter a valid option.\n");
            }
        } else if (user == 1) {
            // Client
            printf("\n0. Log In");
            printf("\n1. Go back to main menu\n\n");
            int loggingIn;
            while (!canGoToMainMenu) {
                loggingIn = scanInt();
                if (loggingIn == 0) {
                    printf("\nEnter your ID, or press '1' to return to the main menu");
                    printf("\nTo register a new ID, contact an Admin\n\n");
                    int clientLocation = 0;
                    int changed = 0;
                    int clientId;
                    while (!canGoToMainMenu) {
                        clientId = scanInt();
                        if (clientId == 1) {
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                        } else {
                            for(int i = 0; i < clientsDatabase->counter; i++) {
                                if (clientsDatabase->clientsList[i]->id == clientId) {
                                    clientLocation = i;
                                    changed = 1;
                                    break;
                                }
                                if (i == clientsDatabase->counter - 1) {
                                    printf("\nThe ID is not registered. Please, try again.\n\n");
                                }
                            }
                            if (clientsDatabase->counter == 0) {
                                printf("\nThe mail is not registered. Please, try again.\n\n");
                            }
                            if (changed) break;
                        }
                    }

                    if (canGoToMainMenu) break;

                    Client* loggedClient = clientsDatabase->clientsList[clientLocation];

                    printf("\n0. Rent movie");
                    printf("\n1. Show my movies");
                    printf("\n2. Show my total debt\n\n");
                    int option;
                    while (!canGoToMainMenu) {
                        option = scanInt();
                        if (option == 0) {
                            if (moviesDatabase->counter == 0) {
                                printf("\nThere are not any movies available at the moment.\n");
                            } else {
                                printf("\nSelect one of the following movies by pressing its index: \n");
                                showMoviesList(moviesDatabase);
                                printf("\n");
                                int movieOption;
                                while (1) {
                                    movieOption = scanInt();
                                    if (movieOption >= 0 && movieOption < moviesDatabase->counter) {
                                        printf("\nHow many days would you like to rent it for? ");
                                        int days;
                                        while (1) {
                                            days = scanInt();
                                            if (days > 0 && days <= 30) {
                                                rentMovie(loggedClient, days, moviesDatabase, movieOption, excess);
                                                break;
                                            } else {
                                                printf("\nThe minimum of days is 1, and de maximum is 30\n");
                                                printf("\nEnter a valid option\n\n");
                                            }
                                        }
                                        printf("\nOperation successful\n");
                                        break;
                                    } else printf("\nPlease, enter a valid option.\n\n");
                                }
                            }
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                        } else if (option == 1) {
                            if (loggedClient->moviesCounter == 0) {
                                printf("\nYou have not rented any movies yet.\n");
                            } else {
                                showMyMovies(loggedClient);
                                printf("\nOperation successful\n");
                            }
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                        } else if (option == 2) {
                            showTotalDebt(loggedClient);
                            printf("\nOperation successful\n");
                            printf("\nReturning to Main Menu\n");
                            canGoToMainMenu = 1;
                        } else printf("\nPlease enter a valid option.\n");
                    }
                } else if (loggingIn == 1) {
                    canGoToMainMenu = 1;
                } else printf("\nPlease enter a valid option.\n");
            }
        } else if (user == 2) {
            // Exit
            for (int i = 0; i < clientsDatabase->counter; i++) {
                freeClient(clientsDatabase->clientsList[i]);
            }
            freeClientsDatabase(clientsDatabase);
            for (int i = 0; i < moviesDatabase->counter; i++) {
                freeMovie(moviesDatabase->moviesList[i]);
            }
            freeMoviesDatabase(moviesDatabase);
            freeExcess(excess);
            printf("\nExit successful\n\n");
            break;
        } else printf("\nPlease enter a valid option.\n");
    }

    return 0;
}
