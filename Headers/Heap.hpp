#include "Order.hpp"
#include <iostream>

using namespace std;

class Heap {
public:
    Heap();
    int ParentPos(int index);
    int LeftChildPos(int index);
    int RightChildPos(int index);
    bool ParentExists(int index);
    bool IsChildLeft(int index);
    bool IsChildRight(int index);
    Order ReturnParent(int index);
    void DeepCopyHeap(const Heap& myHeap);
    Heap(const Heap& myHeap);
    Heap& operator=(const Heap& myHeap);
    int ReturnHeapSize();
    void Enqueue(Order newOrder);
    Order Dequeue();
    bool IsFull();
    void HeapUp();
    void HeapDown();
    void Swap(int indexA, int indexB);
    
    
private:
    int heapCap;
    int heapSize;

    Order* heapArray = new Order[100];
    
};
