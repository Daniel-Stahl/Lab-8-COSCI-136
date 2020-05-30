//#include <iostream>
#include "Warehouse.hpp"

using namespace std;

void MainMenu();

int main() {
    MainMenu();
}

void MainMenu() {
    Warehouse warehouse;
    int userChoice = 0;
    
    do {
        
        do {
            cout << "Main Menu\n 1) Recieve new order\n 2) Print inventory & orders on hand details\n 3) Close day\n 4) Exit Program\n Choice: ";
            cin >> userChoice;
            cout << "\n";
        
            if (!cin || (userChoice <= 0 || userChoice > 4)) {
                cout << "Invalid entry, please try again.\n" << endl;
                cin.clear();
                cin.ignore(200, '\n');
            }
        } while(!cin);
        
        
        
        
        switch (userChoice) {
            case 1:
                //1) Recieve new order
                warehouse.AddOrder();
                break;
            case 2:
                //2) Display details of inventory and outstanding orders on hand
                warehouse.PrintInventory();
                warehouse.PrintOrders(false);
                break;
                
            case 3:
                //
                warehouse.PrintOrders(true);
                break;

        }
    } while (userChoice != 4);
}

