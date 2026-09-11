# 📈 Terminal Trading Simulation

Welcome! This is a simple computer simulation that lets you watch an automated trading bot buy and sell a fake stock in real-time right inside your terminal.

---

## 🧐 What Does This Project Do?

Imagine you give a robot $10,000 and tell it to trade a stock on its own. 

Every second ("tick"), the stock price randomly moves up or down just like real stock markets do. The bot watches the price changes, decides whether to **buy**, **sell**, or **hold**, and tracks whether it is making or losing money over 20 rounds of trading.

---

## 💡 Quick Basics (In Simple Terms)

- **What is a Stock?**  
  A stock is a tiny piece of ownership in a company. When the company does well, the stock price usually goes up; when it doesn't, the price goes down.

- **What is Trading?**  
  Trading is buying stocks at a lower price and trying to sell them later at a higher price to make a profit.

- **What is P&L (Profit & Loss)?**  
  P&L is the scoreboard that shows how much money you've gained or lost compared to the $10,000 you started with.

---

## 🤖 How the Bot Thinks & Decides

The bot follows a very straightforward strategy:

1. **BUY ("Buy the Dip")**: If the stock price drops by **2% or more** in a single tick, the bot thinks it's a good bargain and uses its available cash to buy shares.
2. **SELL ("Take Profit")**: If the stock price jumps up by **3% or more** in a single tick, the bot sells its shares to lock in the profit.
3. **HOLD**: If the price doesn't change enough (or if it doesn't have enough cash to buy or shares to sell), it simply waits and does nothing.

---

## 🚀 How to Compile & Run (Windows)

You only need a standard C++ compiler (`g++`). Open PowerShell or Command Prompt in this folder and run:

### 1. Compile the code:
```powershell
g++ -std=c++17 main.cpp market.cpp bot.cpp render.cpp -o market.exe
```

### 2. Run the simulation:
```powershell
.\market.exe
```

---

## 📊 Understanding the Output

When you run the program, you'll see a clean table with 20 rows. Here is what each column means:

| Column | What It Means |
| :--- | :--- |
| **Tick** | The step number (from 0 to 20). |
| **Price ($)** | The current price of 1 share of the stock. |
| **Change (%)** | How much the price went up (+) or down (-) compared to the last tick. |
| **Decision** | What the bot decided to do: `BUY`, `SELL`, or `HOLD`. |
| **Qty** | How many shares were bought or sold in that tick. |
| **Cash ($)** | Cash currently sitting in the bot's wallet. |
| **Shares** | Total number of shares the bot currently owns. |
| **Portfolio ($)** | Cash + (Shares × Current Price) — total worth of everything the bot owns. |
| **P&L ($ / %)** | Total profit or loss in dollars and percentage compared to starting $10,000. |

At the end, a **Simulation Summary** shows your total earnings, remaining shares, and how the stock performed overall.

---

## 📁 Project Structure

- **[main.cpp](file:///c:/Users/Aryan/5th%20sem/cpp/TradingSimulation/main.cpp)**: The starting point that runs the 20-tick simulation loop.
- **[market.h](file:///c:/Users/Aryan/5th%20sem/cpp/TradingSimulation/market.h)**: Blueprint for the market, declaring price tracking and price generator functions.
- **[market.cpp](file:///c:/Users/Aryan/5th%20sem/cpp/TradingSimulation/market.cpp)**: Generates realistic random stock price swings using math and random numbers.
- **[bot.h](file:///c:/Users/Aryan/5th%20sem/cpp/TradingSimulation/bot.h)**: Blueprint for the trading bot, portfolio wallet, and trade rules.
- **[bot.cpp](file:///c:/Users/Aryan/5th%20sem/cpp/TradingSimulation/bot.cpp)**: Logic that checks price percentage changes and executes buy/sell orders.
- **[render.h](file:///c:/Users/Aryan/5th%20sem/cpp/TradingSimulation/render.h)**: Blueprint for displaying information neatly on the screen.
- **[render.cpp](file:///c:/Users/Aryan/5th%20sem/cpp/TradingSimulation/render.cpp)**: Formats the data into clean tables and prints the summary to your terminal.

---

## 🔮 What We'd Improve Next

- **Multiple Stocks**: Let the bot watch and trade 3 to 5 different companies at once.
- **Smarter Indicators**: Add popular technical indicators like Moving Averages (SMA/EMA) or RSI instead of only single-tick price jumps.
- **Stop-Loss Protection**: Teach the bot to sell if a stock drops too much (e.g., -5%) to prevent big losses.
- **Visual ASCII Charts**: Draw mini price line charts directly in the terminal to visualize trends over time.
- **Interactive Mode**: Let the user choose starting cash, risk tolerance, and number of ticks from the command line.
