#include "market.h"
#include <chrono>
#include <algorithm>

Market::Market(double startPrice, double vol, double driftVal)
    : currentPrice(startPrice),
      initialPrice(startPrice),
      volatility(vol),
      drift(driftVal),
      rng(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count())),
      dist(0.0, 1.0) {
    priceHistory.push_back(currentPrice);
}

double Market::tick() {
    double z = dist(rng);
    double pctChange = drift + volatility * z;
    currentPrice *= (1.0 + pctChange);
    if (currentPrice < 1.0) {
        currentPrice = 1.0;
    }
    priceHistory.push_back(currentPrice);
    return currentPrice;
}

double Market::getCurrentPrice() const {
    return currentPrice;
}

double Market::getPreviousPrice() const {
    if (priceHistory.size() >= 2) {
        return priceHistory[priceHistory.size() - 2];
    }
    return currentPrice;
}

const std::vector<double>& Market::getPriceHistory() const {
    return priceHistory;
}
