#include <string>

using namespace std;

class Order {
public:
    Order();
    Order(int newItem, int newShipping);
    void SetOrder(int items, int shipping);
    int GetOrderID() const;
    int GetOrderQTY() const;
    int GetShippingType() const;
    void SetOrderPrice(int price);
    int GenerateOrderID();
    
private:
    int orderID;
    int qty;
    int totalPrice;
    int shippingType;
};
