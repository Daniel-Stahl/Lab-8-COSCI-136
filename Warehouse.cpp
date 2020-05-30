#include "Warehouse.hpp"
enum ShippingStatus{ExtremeRush = 0, ExpediteRush = 1, Standard = 2};

Warehouse::Warehouse() {
    inStock = 500;
    price = 3.00;
    totalOrders = 0;
}

void Warehouse::AddOrder() {
    Order newOrder;
    int items = 0;
    int shippingStatus = -1;
    double cost = 0;
    double profit = 0;
    double total = 0;
    
    while (items <= 0) {
        cout << "How many widgets? ";
        cin >> items;
        
        if (items <= 0) {
            cout << "Error: Number of widgets cannot be 0 or less than 0, please try again\n";
        }
    }
    
    while (shippingStatus < 0 || shippingStatus > 2) {
        cout << "\nWhich shipping do you want to use? ExtremeRush = 0, ExpediteRush = 1, Standard = 2\nShipping: ";
        cin >> shippingStatus;
        
        if (shippingStatus < 0 || shippingStatus > 2) {
            cout << "Error: Number for shipping cannot be less than 0 or greater than 2, please try again.\n";
        }
    }
    
    if (shippingStatus == ExtremeRush) {
        total = ((price * .50) + price) * items;
        totalMarkUp = price * .50 * items;
    } else if (shippingStatus == ExpediteRush) {
        total = ((price * .20) + price) * items;
        totalMarkUp = price * .20 * items;
    } else if (shippingStatus == Standard) {
        total = ((price * .10) + price) * items;
        totalMarkUp = price * .10 * items;
    }
    
    cost = price * items;
    profit = total - cost;
    totalShipped = items;
    
    newOrder.SetOrder(items, shippingStatus, totalShipped, cost, profit, total, totalMarkUp);
    heap.Enqueue(newOrder);
    
    warehouseCost += cost;
    customerTotal += total;
    warehouseProfit += profit;
    totalOrders += items;
    
    inStock -= items;
}

void Warehouse::PrintInventory() {
    cout << "\n" << inStock << " Widgets remain in stock\n";
}

void Warehouse::PrintOrders(bool printProcessed) {
    Order order;
    Heap tempHeap;
    int hSize;
    int index = 0;
    int tempPerMarkup = 0;
    int tempTotalShip = 0;
    int tempTotalOrders = 0;
    double tempWarehouseCost = 0;
    double tempWarehouseProfit = 0;
    double tempCustomerTotal = 0;
    double tempCost = 0;
    double tempProfit = 0;
    double tempMarkup = 0;
    string shippingStat;
    
    if (printProcessed) {
        order = heap.Dequeue();
        hSize = heap.ReturnHeapSize();
        tempTotalOrders = totalOrders;
        tempWarehouseCost = warehouseCost;
        tempWarehouseProfit = warehouseProfit;
        tempCustomerTotal = customerTotal;
    } else {
        tempHeap = heap;
        order = tempHeap.Dequeue();
        hSize = tempHeap.ReturnHeapSize();
    }
    
    cout << "\nOrders Processed: " << tempTotalOrders << "\n" << fixed << setprecision(2) << "Warehouse cost: " << tempWarehouseCost << "\n" << "Customer cost: " << tempCustomerTotal << "\n" << "Profit: " << tempWarehouseProfit << "\n";
    
    cout << "\nOrder ID" << setw(20) << "Shipping Status" << setw(8) << "QTY" << setw(15) << "QTY Shipped" << setw(10) << "Markup" << setw(20) << "Warehouse cost" << setw(15) << "Total Markup" << setw(20) << "Warehouse Profit\n";
    
    while (index <= hSize) {
        if (printProcessed) {
            tempCost = order.GetCost();
            tempProfit = order.GetProfit();
            tempMarkup = order.GetMarkUpTot();
            tempTotalShip = order.GetTotalShip();
        }
    
        shippingStat = order.GetShippingType() == ExtremeRush ? "Extreme Rush" : order.GetShippingType() == ExpediteRush ? "Expedite Rush" : "Standard";
        tempPerMarkup = order.GetShippingType() == ExtremeRush ? 50 : order.GetShippingType() == ExpediteRush ? 20 : 10;
        
        cout << setw(8) << order.GetOrderID() << setw(20) << shippingStat << setw(8) << order.GetOrderQTY() << setw(15) << tempTotalShip << setw(10) << tempPerMarkup << setw(20) << fixed << setprecision(2) << tempCost << setw(15) << tempMarkup << setw(19) << tempProfit << "\n";
        
        if (printProcessed) {
            order = heap.Dequeue();
        } else {
            order = tempHeap.Dequeue();
        }
        
        index++;
    }
    
    cout << "\n";
    
}
