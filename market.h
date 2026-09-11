#ifndef MARKET_H
#define MARKET_H

#include <vector>
#include <random>

class Market {
private:
    double currentPrice;
    double initialPrice;
    double volatility;
    double drift;
    std::mt19937 rng;
    std::normal_distribution<double> dist;
    std::vector<double> priceHistory;

public:
    Market(double startPrice = 100.0, double vol = 0.025, double driftVal = 0.001);
    double tick();
    double getCurrentPrice() const;
    double getPreviousPrice() const;
    const std::vector<double>& getPriceHistory() const;
};

#endif // MARKET_H
