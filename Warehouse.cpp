#include "Warehouse.hpp"
enum ShippingStatus{ExtremeRush = 0, ExpediteRush = 1, Standard = 2};

Warehouse::Warehouse() {
    inStock = 500;
}

void Warehouse::AddOrder() {
    Order newOrder;
    int items;
    int shippingStatus;
    
    cout << "How many widgets? ";
    cin >> items;
    
    cout << "Which shipping do you want to use? ExtremeRush = 0, ExpediteRush = 1, Standard = 2\n Shipping: ";
    cin >> shippingStatus;
    
    newOrder.SetOrder(items, shippingStatus);
    heap.Enqueue(newOrder);
}

void Warehouse::PrintInventory() {
    cout << inStock << " Widgets remain in stock\n";
}

void Warehouse::PrintOrders() {
    Heap tempHeap = heap;
    Order order = tempHeap.Dequeue();
    int hSize = tempHeap.ReturnHeapSize();
    
    int index = 0;
    
    while (index <= hSize) {
        cout << "\nOrder ID: " << order.GetOrderID();
        
        if (order.GetShippingType() == ExtremeRush) {
            cout << " Shipping: ExtremeRush\n";
        }
        
        if (order.GetShippingType() == ExpediteRush) {
            cout << " Shipping: ExpediteRush\n";
        }
        
        if (order.GetShippingType() == Standard) {
            cout <<  " Shipping: Standard\n";
        }
        
        order = tempHeap.Dequeue();

        index++;
    }
    
}
