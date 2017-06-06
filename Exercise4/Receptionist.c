#include "Receptionist.h"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>

/*
 * Description: Contains the functions related to the Receptionist structure
 */

/*
 * Description: Creates a Receptionist
 * Returns: The Receptionist created
 */
Receptionist* new_Receptionist(char* name, char* surname, int id) {

    Receptionist* receptionist = malloc(sizeof(Receptionist));

    receptionist->name = malloc(sizeof(char) * (strlen(name) + 1));
    receptionist->surname = malloc(sizeof(char) * (strlen(surname) + 1));
    receptionist->id = id;

    strcpy(receptionist->name, name);
    strcpy(receptionist->surname, surname);

    return receptionist;
}

/*
 * Description: Gives information about the room availability status and its price per night
 * Returns: Void
 */
void giveInfo(Hotel* hotel) {
    for (int i = 0; i < 400; i++) {
        if (!hotel->roomList[i]->isOccupied) {
            printf("\nBasic Rooms: Available");
            printf("\nPrice: $%.2f\n", hotel->roomList[i]->price);
            break;
        }
        if (i == 399) printf("\nThere are no basic rooms available at the moment");
    }
    for (int i = 400; i < sizeof(hotel->roomList) / sizeof(hotel->roomList[0]); i++) {
        if (!hotel->roomList[i]->isOccupied) {
            printf("\nDeluxe Rooms: Available");
            printf("\nPrice: $%.2f\n\n", hotel->roomList[i]->price);
            break;
        }
        if (i == sizeof(hotel->roomList) / sizeof(hotel->roomList[0]) - 1) printf("\nThere are no deluxe rooms available at the moment\n\n");
    }
}

/*
 * Description: Frees the space of memory assigned to a receptionist and all its components
 * Returns: Void
 */
void freeReceptionist(Receptionist* receptionist) {
    free(receptionist->name);
    free(receptionist->surname);
    free(receptionist);
}
