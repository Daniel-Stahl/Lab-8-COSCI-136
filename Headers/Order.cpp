#include "Order.hpp"

Order::Order(){};

Order::Order(int newItem, int newShipping, int newShipped, double newCost, double newProfit, double newTotal, double newMarkUpTot) {
    SetOrder(newItem, newShipping, newShipped, newCost, newProfit, newTotal, newMarkUpTot);
}

void Order::SetOrder(int items, int shipping, int shipped, double cost, double profit, double total, double markUp) {
    orderID = GenerateOrderID();
    qty = items;
    shippingType = shipping;
    totalShipped = shipped;
    warehouseCost = cost;
    warehouseProfit = profit;
    customerTotal = total;
    markUpTotal = markUp;
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

int Order::GetTotalShip() const {
    return totalShipped;
}

double Order::GetCost() const {
    return warehouseCost;
}

double Order::GetProfit() const {
    return warehouseProfit;
}

double Order::GetTotal() const {
    return customerTotal;
}

double Order::GetMarkUpTot() const {
    return markUpTotal;
}

int Order::GenerateOrderID() {
    static int num = 0;
    return ++num;
}
