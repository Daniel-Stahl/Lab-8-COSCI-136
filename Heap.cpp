#include "Heap.hpp"

Heap::Heap() {
    heapCap = 100;
    heapSize = 0;
}

int Heap::ParentPos(int index) {
    return (index - 1) / 2;
}

int Heap::LeftChildPos(int index) {
    return (index * 2) + 1;
}

int Heap::RightChildPos(int index) {
    return (index * 2) + 2;
}

bool Heap::ParentExists(int index) {
    return ParentPos(index) >= 0;
}

bool Heap::IsChildLeft(int index) {
    return LeftChildPos(index) < heapSize;
}

bool Heap::IsChildRight(int index) {
    return RightChildPos(index) <= heapSize;
}

int Heap::ReturnHeapSize() {
    return heapSize;
}

void Heap::DeepCopyHeap(const Heap& myHeap) {
    delete [] heapArray;
    
    heapCap = myHeap.heapCap;
    heapSize = myHeap.heapSize;
    
    if (myHeap.heapArray) {
        heapArray = new Order[100];
        
        for (int i = 0; i < heapSize; i++) {
            heapArray[i] = myHeap.heapArray[i];
        }
    } else {
        heapArray = nullptr;
    }
}

Heap::Heap(const Heap& myHeap) {
    heapArray = nullptr;
    DeepCopyHeap(myHeap);
}

Heap& Heap::operator=(const Heap& myHeap) {
    if (this == &myHeap) {
        return *this;
    }
    
    DeepCopyHeap(myHeap);
    return *this;
}

Order Heap::ReturnParent(int index) {
    return heapArray[ParentPos(index)];
}

bool Heap::IsFull() {
    return heapSize == heapCap;
}

void Heap::Enqueue(Order newOrder) {
    if (IsFull()) {
        cout << "Reached capacity\n";
        return;
    }
  
    heapArray[heapSize] = newOrder;
    heapSize++;
    HeapUp();
}

Order Heap::Dequeue() {    
    Order heapRoot = heapArray[0];
    heapArray[0] = heapArray[heapSize-1];
    heapSize--;
    HeapDown();
    return heapRoot;
}

void Heap::HeapUp() {
    int index = heapSize - 1;
    
    while (ParentExists(index) && ReturnParent(index).GetShippingType() > heapArray[index].GetShippingType()) {
        Swap(ParentPos(index), index);
        index = ParentPos(index);
    }
}

void Heap::HeapDown() {
    int index = 0;
    
    while (IsChildLeft(index)) {
        int smallestChild = LeftChildPos(index);
        
        if (IsChildRight(index)) {
            if (heapArray[smallestChild+1].GetShippingType() < heapArray[smallestChild].GetShippingType()) {
                smallestChild = RightChildPos(index);
            } else if (heapArray[smallestChild+1].GetShippingType() == heapArray[smallestChild].GetShippingType()) {
                if (heapArray[smallestChild].GetOrderID() < heapArray[smallestChild+1].GetOrderID()) {
                    smallestChild = LeftChildPos(index);
                } else {
                   smallestChild = RightChildPos(index);
                }
            }
        }
        
        Swap(index, smallestChild);
        
        index = smallestChild;
    }
}

void Heap::Swap(int indexA, int indexB) {
    Order temp = heapArray[indexA];
    heapArray[indexA] = heapArray[indexB];
    heapArray[indexB] = temp;
}
