#include "Order.hpp"
#include <iostream>

using namespace std;

class Heap {
public:
    Heap();
    void Enqueue(Order newOrder);
    void HeapUp(int last);
    void HeapDown();
    void Swap(Order* orderA, Order* orderB);
    
    
private:
    int heapCap;
    int heapSize;
    Order* heapArray;
    
};
