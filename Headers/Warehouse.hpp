#include "Heap.hpp"

using namespace std;

class Warehouse {
public:
    Warehouse();
    void AddOrder();
    void PrintInventory();
    void PrintOrders();
    
private:
    Heap heap;
    int inStock;
    
};
