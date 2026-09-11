#include <iostream>
#include "market.h"
#include "bot.h"
#include "render.h"

int main() {
    const int TOTAL_TICKS = 20;
    const double INITIAL_PRICE = 100.0;
    const double INITIAL_CASH = 10000.0;
    const double VOLATILITY = 0.025; // 2.5% tick volatility for realistic price swings

    Market market(INITIAL_PRICE, VOLATILITY);
    Bot bot(INITIAL_CASH, -0.02, 0.03); // Buy when price drops >= 2%, sell when rises >= 3%

    Render::printHeader();

    // Initial state before simulation begins (Tick 0)
    int executedQty = 0;
    Render::printTick(0, market.getCurrentPrice(), market.getCurrentPrice(), Action::HOLD, executedQty, bot);

    // Simulate 20 ticks
    for (int tick = 1; tick <= TOTAL_TICKS; ++tick) {
        double prevPrice = market.getCurrentPrice();
        double currentPrice = market.tick();
        Action action = bot.evaluate(currentPrice, prevPrice, executedQty);
        Render::printTick(tick, currentPrice, prevPrice, action, executedQty, bot);
    }

    Render::printSummary(market, bot);

    return 0;
}
