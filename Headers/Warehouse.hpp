#include "Heap.hpp"

using namespace std;

class Warehouse {
public:
    Warehouse();
    void AddOrder();
    
private:
    Heap heap;
    int inStock;
    
};
