#include "bot.h"
#include <cmath>

std::string actionToString(Action action) {
    switch (action) {
        case Action::BUY:  return "BUY";
        case Action::SELL: return "SELL";
        case Action::HOLD: return "HOLD";
        default:           return "UNKNOWN";
    }
}

Bot::Bot(double startCash, double buyDrop, double sellRise)
    : initialCash(startCash),
      cash(startCash),
      shares(0),
      buyThreshold(buyDrop),
      sellThreshold(sellRise) {}

Action Bot::evaluate(double currentPrice, double previousPrice, int& executedShares) {
    executedShares = 0;
    if (previousPrice <= 0.0) return Action::HOLD;

    double change = (currentPrice - previousPrice) / previousPrice;

    // Price drops by 2% or more -> BUY
    if (change <= buyThreshold) {
        int sharesToBuy = static_cast<int>(cash / currentPrice);
        if (sharesToBuy > 0) {
            executedShares = sharesToBuy;
            cash -= executedShares * currentPrice;
            shares += executedShares;
            return Action::BUY;
        }
    }
    // Price rises by 3% or more -> SELL
    else if (change >= sellThreshold) {
        if (shares > 0) {
            executedShares = shares;
            cash += executedShares * currentPrice;
            shares = 0;
            return Action::SELL;
        }
    }

    return Action::HOLD;
}

double Bot::getCash() const {
    return cash;
}

int Bot::getShares() const {
    return shares;
}

double Bot::getInitialCash() const {
    return initialCash;
}

double Bot::getTotalPortfolioValue(double currentPrice) const {
    return cash + (static_cast<double>(shares) * currentPrice);
}

double Bot::getProfitLoss(double currentPrice) const {
    return getTotalPortfolioValue(currentPrice) - initialCash;
}

double Bot::getProfitLossPercentage(double currentPrice) const {
    if (initialCash == 0.0) return 0.0;
    return (getProfitLoss(currentPrice) / initialCash) * 100.0;
}
