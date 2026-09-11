#include "render.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

static std::string formatDouble(double val, int precision = 2, bool withSign = false) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision);
    if (withSign && val > 0.0) {
        oss << "+";
    }
    oss << val;
    return oss.str();
}

void Render::printHeader() {
    std::cout << "\n=========================================================================================================\n";
    std::cout << "                                  TRADING SIMULATION (20 TICKS)                                          \n";
    std::cout << "=========================================================================================================\n";
    std::cout << std::left
              << std::setw(6)  << "Tick"
              << std::setw(12) << "Price ($)"
              << std::setw(12) << "Change (%)"
              << std::setw(10) << "Decision"
              << std::setw(8)  << "Qty"
              << std::setw(14) << "Cash ($)"
              << std::setw(10) << "Shares"
              << std::setw(16) << "Portfolio ($)"
              << std::setw(14) << "P&L ($)"
              << std::setw(10) << "P&L (%)"
              << "\n";
    std::cout << "---------------------------------------------------------------------------------------------------------\n";
}

void Render::printTick(int tick, double price, double prevPrice, Action action, int qty, const Bot& bot) {
    double pctChange = (prevPrice > 0.0) ? ((price - prevPrice) / prevPrice) * 100.0 : 0.0;
    double portfolioVal = bot.getTotalPortfolioValue(price);
    double pnl = bot.getProfitLoss(price);
    double pnlPct = bot.getProfitLossPercentage(price);

    std::string changeStr = (tick == 0) ? "0.00%" : (formatDouble(pctChange, 2, true) + "%");
    std::string pnlStr = formatDouble(pnl, 2, true);
    std::string pnlPctStr = formatDouble(pnlPct, 2, true) + "%";

    std::cout << std::left
              << std::setw(6)  << tick
              << std::setw(12) << formatDouble(price, 2)
              << std::setw(12) << changeStr
              << std::setw(10) << actionToString(action)
              << std::setw(8)  << qty
              << std::setw(14) << formatDouble(bot.getCash(), 2)
              << std::setw(10) << bot.getShares()
              << std::setw(16) << formatDouble(portfolioVal, 2)
              << std::setw(14) << pnlStr
              << std::setw(10) << pnlPctStr
              << "\n";
}

void Render::printSummary(const Market& market, const Bot& bot) {
    double endPrice = market.getCurrentPrice();
    double startPrice = market.getPriceHistory().front();
    double marketReturn = ((endPrice - startPrice) / startPrice) * 100.0;
    double botReturn = bot.getProfitLossPercentage(endPrice);

    std::cout << "=========================================================================================================\n";
    std::cout << "                                         SIMULATION SUMMARY                                              \n";
    std::cout << "=========================================================================================================\n";
    std::cout << "Initial Stock Price:   $" << formatDouble(startPrice, 2) << "\n";
    std::cout << "Final Stock Price:     $" << formatDouble(endPrice, 2) 
              << " (" << formatDouble(marketReturn, 2, true) << "%)\n";
    std::cout << "Initial Cash:          $" << formatDouble(bot.getInitialCash(), 2) << "\n";
    std::cout << "Final Cash:            $" << formatDouble(bot.getCash(), 2) << "\n";
    std::cout << "Final Shares Held:     " << bot.getShares() << " units\n";
    std::cout << "Total Portfolio Value: $" << formatDouble(bot.getTotalPortfolioValue(endPrice), 2) << "\n";
    std::cout << "Total Net P&L:         " << (bot.getProfitLoss(endPrice) >= 0 ? "+$" : "-$") 
              << formatDouble(std::abs(bot.getProfitLoss(endPrice)), 2)
              << " (" << formatDouble(botReturn, 2, true) << "%)\n";
    std::cout << "=========================================================================================================\n\n";
}
