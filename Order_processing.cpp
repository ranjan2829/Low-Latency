#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

class Order {
public:
    int32_t orderId;
    int64_t price;
    int32_t quantity;
};

class LimitOrderBook {
public:
    // Function to add a new order to the order book
    void addOrder(const Order& order) {
        orders.push_back(order);
        // Sort orders based on price (assuming ascending order for simplicity)
        std::sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
            return a.price < b.price;
        });
    }

    // Function to match incoming market order with existing limit orders
    void matchMarketOrder(const Order& marketOrder) {
        // Iterate through limit orders and match with the market order
        for (auto it = orders.begin(); it != orders.end(); ) {
            if (marketOrder.quantity > 0 && marketOrder.price >= it->price) {
                // Execute the trade
                int32_t executedQuantity = std::min(marketOrder.quantity, it->quantity);
                std::cout << "Trade executed - Quantity: " << executedQuantity << ", Price: " << it->price << std::endl;

                // Update order book and market order
                it->quantity -= executedQuantity;
                marketOrder.quantity -= executedQuantity;

                // Remove the limit order if fully executed
                if (it->quantity == 0) {
                    it = orders.erase(it);
                } else {
                    ++it;
                }
            } else {
                // No match with current limit order
                ++it;
            }
        }

        // Handle remaining quantity of the market order (if any)
        if (marketOrder.quantity > 0) {
            std::cout << "Remaining market order quantity: " << marketOrder.quantity << std::endl;
        }
    }

private:
    std::vector<Order> orders;
};

class TradingEngine {
public:
    // Function to process incoming orders
    void processOrder(const Order& order) {
        if (order.price > 0 && order.quantity > 0) {
            if (order.price == 0) {
                // Market order
                limitOrderBook.matchMarketOrder(order);
            } else {
                // Limit order
                limitOrderBook.addOrder(order);
            }
        } else {
            std::cout << "Invalid order." << std::endl;
        }
    }

private:
    LimitOrderBook limitOrderBook;
};

int main() {
    // Initialize trading engine
    TradingEngine engine;

    // Example: Add limit orders
    Order limitOrder1{1, 1000000, 50};
    Order limitOrder2{2, 999000, 30};

    engine.processOrder(limitOrder1);
    engine.processOrder(limitOrder2);

    // Example: Add market order
    Order marketOrder{3, 0, 80};
    engine.processOrder(marketOrder);

    return 0;
}

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
class Order{
    public:
    int32_t OrderId;
    int64_t price;
    int32_t quantity;

};
class LimitOrderBook{
    public:
    void addOrder(const Order& order){
        orders.push_back(order);
        std::sort(orders.begin(),orders.end(),[](const Order& a,const Order& b){
            return a.price<b.price;
        });
        

    }
}