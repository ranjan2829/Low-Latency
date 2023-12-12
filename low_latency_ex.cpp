#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
class QuantStrategy{
    public:
    void execute(){

    }

};
class TradingSystem{
    public:
    TradingSystem():strategy(){}
    void run(){
        auto start=high_resolution_clock::now();
        strategy.execute();
        auto end=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(end-start);
        cout<<"time"<<duration.count<<endl;
        
    }
}

