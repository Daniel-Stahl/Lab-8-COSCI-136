#include "Heap.hpp"

Heap::Heap() {
    heapCap = 100;
    heapSize = 0;
    heapArray = new Order[100];
}

void Heap::Enqueue(Order newOrder) {
    if (heapSize == heapCap) {
        cout << "Reached capacity\n";
        return;
    }
    
    heapSize++;
    int pos = heapSize - 1;
    heapArray[pos] = newOrder;
    HeapUp(heapSize-1);
}

void Heap::HeapUp(int last) {
    int parentLoc = (last-1)/2;
    
    if (heapArray[parentLoc].GetShippingType() > heapArray[last].GetShippingType()) {
        Swap(&heapArray[parentLoc], &heapArray[last]);
        HeapUp(parentLoc);
    }
    
}

void Heap::HeapDown() {
    
}

void Heap::Swap(Order* orderA, Order* orderB) {
    Order* tempOrder = orderA;
    orderA = orderB;
    orderB = tempOrder;
}
