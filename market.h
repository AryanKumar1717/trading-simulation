// market.h
#ifndef MARKET_H
#define MARKET_H

struct Candle {
    double open, high, low, close;
    int volume;
};

struct Tick {
    double price;
};

class Market {
public:
    Market(double startPrice);
    Tick generateTick();
    Candle generateCandle(int ticksPerCandle);
    
private:
    double currentPrice;
};

#endif