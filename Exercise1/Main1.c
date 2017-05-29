#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
#include "../Util/ScanUtil.h"


void clientMenu(DataBase* database);
void adminMenu(DataBase* database);

DataBase* setup(){
    DataBase* database = createDataBase();
    Manufacturer* samsung = createManufacturer("Samsung", "we also sell appliances",
                                             "silicon valley", "California","03327 42-4377", "samsung.com");
    addManufacturer(database, samsung);
    Provider* dhl = createProvider("DHL Express","DHL Express provides international courier, parcel and express mail services. It´s the world's largest logistics company operating around the world",
                                  "Av. Córdoba 783","CABA","0810-122-3345", "dhl.com");
    addProvider(database, dhl);
    Appliance* washingMachine = createAppliance("washing machine","8",1500,"v8.0.1");
    addAppliance(database,washingMachine,"samsung","dhl");
    return database;
}

int main() {
    DataBase* database = setup();
    while(1) {
        printf("Enter as User (1) or Admin? (2)   to exit enter (-1)\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                clientMenu(database);
                break;
            case 2:
                adminMenu(database);
                break;
            case -1:
                exit(0);
            default:
                printf("Enter one of the options above\n");
        }
    }
}