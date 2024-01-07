#include <iostream>
#include <cstdint>
class Order{
    public:
    int32_t orderId;
    int64_t price;
    int32_t quantity;
};
class TradingEngine{
    public:
    void processOrder(const Order& order){
        //logic


    }
};
int main(){
    Order order;
    order.orderID=1;
    order.price=1500;
    order.quantity=160;
    TradingEngine Engine;
    Engine.processOrder(order);
    return 0;
}