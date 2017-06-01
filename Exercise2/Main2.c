#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
#include "../Util/ScanUtil.h"
void clientMenu(DataBase* database);
void adminMenu(DataBase* database);
void userMenu(DataBase* dataBase);

DataBase* setup(){
    DataBase* database = createDataBase();
    Manufacturer* nikon = createManufacturer("Nikon", "we sell the best cameras",
                                               "everywhere", "California","03327 42-4377", "nikon.com");
    addManufacturer(database, nikon);
    Provider* dhl = createProvider("DHL Express","DHL Express provides international courier, parcel and express mail services. It´s the world's largest logistics company operating around the world",
                                   "Av. Córdoba 783","CABA","0810-122-3345", "dhl.com");
    addProvider(database, dhl);

    Camera* sonyCamera = createCamera("best sony camera",35,60,4,DSLR,5000);
    Accessory* accessory = createAccessory("sonyLens","a bigger more expensive lens",1000);
    addCamera(database,sonyCamera,0,0);
    addAccessory(database,accessory,0,0);
    return database;
}

int main() {
    DataBase* database = setup();
    while(1) {
        printf("Enter as User (1) or Admin? (2)\n if you want to create an Account, press (3)\n  to exit enter (-1)\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                clientMenu(database);
                break;
            case 2:
                adminMenu(database);
                break;
            case 3:
                userMenu(database);
                break;
            case -1:
                exit(0);
            default:
                printf("Enter one of the options above\n");
        }
    }
}