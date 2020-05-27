#include "Warehouse.hpp"

Warehouse::Warehouse() {
    inStock = 500;
}

void Warehouse::AddOrder() {
    Order newOrder1;
    newOrder1.SetOrder(16, 4, 1);
    heap.Enqueue(newOrder1);
    
    Order newOrder2;
    newOrder2.SetOrder(12, 5, 0);
    heap.Enqueue(newOrder2);
    
    Order newOrder3;
    newOrder3.SetOrder(32, 4, 2);
    heap.Enqueue(newOrder3);
}
