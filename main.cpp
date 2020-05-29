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
        cout << "Main Menu\n 1) Print inventory & orders on hand details\n 2) Recieve new order\n 3) Close day\n 4) Exit Program\n Choice: ";
        cin >> userChoice;
        cout << "\n";
        
        switch (userChoice) {
            case 1:
                //1) Display details of inventory and outstanding orders on hand
                warehouse.PrintInventory();
                warehouse.PrintOrders(false);
                break;
            case 2:
                //2) Recieve new order
                warehouse.AddOrder();
                
                break;
                
            case 3:
                warehouse.PrintOrders(true);
                
                /*3) Close day and process orders recieved on that day
                - show the total number of orders processed along with their total cost to the warehouse, total profit, and total cost to the customers
                - show inventory on hand (if any) after day's orders been processed.
                - show a list of processed orders in the order they will be shipped.
                - With each filled order include the following information (see the sample below):  order number, rush status ( extreme, rush, standard; do not use numeric values), total quantity shipped, total quantity ordered, % of markup, the total cost to the warehouse, amount of markup,  and warehouse profit
                - display  the processed orders in a table format */
                
                break;
        }
        
        
        
    } while (userChoice != 4);
    
    
    
    /*
     MENU:
     
     
     
     
     
     
     */
    
    
    
}

