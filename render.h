#ifndef RENDER_H
#define RENDER_H

#include "market.h"
#include "bot.h"

class Render {
public:
    static void printHeader();
    static void printTick(int tick, double price, double prevPrice, Action action, int qty, const Bot& bot);
    static void printSummary(const Market& market, const Bot& bot);
};

#endif // RENDER_H
