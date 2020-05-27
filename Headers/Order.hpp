#include <string>

using namespace std;

class Order {
public:
    Order();
    Order(int newItem, int newPrice, int newShipping);
    void SetOrder(int items, int price, int shipping);
    int GetOrderID() const;
    int GetOrderQTY() const;
    int GetShippingType() const;
    int GenerateOrderID();
    
private:
    int orderID;
    int qty;
    int totalPrice;
    int shippingType;
};
