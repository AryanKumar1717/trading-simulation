#ifndef BOT_H
#define BOT_H

#include <string>

enum class Action {
    BUY,
    SELL,
    HOLD
};

std::string actionToString(Action action);

class Bot {
private:
    double initialCash;
    double cash;
    int shares;
    double buyThreshold;  // e.g., -0.02 (-2%)
    double sellThreshold; // e.g., +0.03 (+3%)

public:
    Bot(double startCash = 10000.0, double buyDrop = -0.02, double sellRise = 0.03);

    Action evaluate(double currentPrice, double previousPrice, int& executedShares);

    double getCash() const;
    int getShares() const;
    double getInitialCash() const;
    double getTotalPortfolioValue(double currentPrice) const;
    double getProfitLoss(double currentPrice) const;
    double getProfitLossPercentage(double currentPrice) const;
};

#endif // BOT_H
