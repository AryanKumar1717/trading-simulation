// market.cpp
#include "market.h"
#include <cstdlib>
#include <cmath>

Market::Market(double startPrice) : currentPrice(startPrice) {}

Tick Market::generateTick() {
    // Random walk: price moves +/- 0-2% randomly
    double change = (rand() % 201 - 100) / 10000.0; // -1% to +1%
    currentPrice += currentPrice * change;
    return {currentPrice};
}

Candle Market::generateCandle(int ticksPerCandle) {
    Candle c = {currentPrice, currentPrice, currentPrice, currentPrice, 0};
    
    for (int i = 0; i < ticksPerCandle; i++) {
        Tick t = generateTick();
        if (t.price > c.high) c.high = t.price;
        if (t.price < c.low) c.low = t.price;
        c.close = t.price;
        c.volume += rand() % 1000;
    }
    return c;
}