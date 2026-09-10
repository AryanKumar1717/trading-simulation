// main.cpp
#include <iostream>
#include "market.h"

int main() {
    Market m(1500.0);
    
    // Generate 5 candles
    for (int i = 0; i < 5; i++) {
        Candle c = m.generateCandle(10);
        std::cout << "Candle " << i << ": O:" << c.open 
                  << " H:" << c.high << " L:" << c.low 
                  << " C:" << c.close << std::endl;
    }
    
    return 0;
}