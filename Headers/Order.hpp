#include <string>

using namespace std;

class Order {
public:
    Order();
    Order(int newItem, int newShipping, int newShipped, double newCost, double newProfit, double newTotal, double newMarkUpTot);
    void SetOrder(int items, int shipping, int shipped, double cost, double profit, double total, double markUp);
    int GetOrderID() const;
    int GetOrderQTY() const;
    int GetShippingType() const;
    int GetTotalShip() const;
    double GetCost() const;
    double GetProfit() const;
    double GetTotal() const;
    double GetMarkUpTot() const;
    int GenerateOrderID();
    
private:
    int orderID;
    int qty;
    int shippingType;
    int totalShipped;
    double warehouseCost;
    double warehouseProfit;
    double customerTotal;
    double markUpTotal;
};
