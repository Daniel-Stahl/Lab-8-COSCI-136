#include "Heap.hpp"
#include <iomanip>

using namespace std;

class Warehouse {
public:
    Warehouse();
    void AddOrder();
    void PrintInventory();
    void PrintOrders(bool printProcessed);
    
private:
    Heap heap;
    int inStock;
    double price;
    double warehouseCost;
    double warehouseProfit;
    double customerTotal;
    double totalMarkUp;
    int totalOrders;
    int totalShipped;
    
};
