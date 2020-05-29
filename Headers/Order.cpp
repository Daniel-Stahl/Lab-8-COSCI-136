#include "Order.hpp"

Order::Order(){};

Order::Order(int newItem, int newShipping) {
    SetOrder(newItem, newShipping);
}

void Order::SetOrder(int items, int shipping) {
    orderID = GenerateOrderID();
    qty = items;
    shippingType = shipping;
}

int Order::GetOrderID() const {
    return orderID;
}

int Order::GetOrderQTY() const {
    return qty;
}

int Order::GetShippingType() const {
    return shippingType;
}

void Order::SetOrderPrice(int price) {
    totalPrice = price;
    
}

int Order::GenerateOrderID() {
    static int num = 0;
    return ++num;
}
