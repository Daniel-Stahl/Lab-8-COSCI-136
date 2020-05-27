#include "Order.hpp"

Order::Order(){};

Order::Order(int newItem, int newPrice, int newShipping) {
    SetOrder(newItem, newPrice, newShipping);
}

void Order::SetOrder(int items, int price, int shipping) {
    orderID = GenerateOrderID();
    qty = items;
    totalPrice = price;
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

int Order::GenerateOrderID() {
    static int num = 0;
    return ++num;
}
