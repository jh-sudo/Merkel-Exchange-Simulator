# Merkel Exchange Simulator

A command-line cryptocurrency exchange simulator written in C++. The program enables users to explore market data, simulate trades, and visualize candlestick patterns using both internal data and external CSV input.

---

## 🚀 Features

- View historical cryptocurrency exchange data
- Simulate placing bids and asks on different products
- Visualize candlestick charts in ASCII
- Load external candlestick data from CSV for plotting
- Simulated wallet functionality with trade fulfillment logic
- Modular design with extendable architecture

---

## 🛠️ How to Run

1. **Build the project** using a C++ compiler (e.g. g++):

```bash
g++ main.cpp MerkelMain.cpp OrderBook.cpp CSVReader.cpp Candlestick.cpp -o merkel-exchange
```

2. **Run the program**:

```bash
./merkel-exchange
```

> Ensure that the CSV data file (`20200601.csv`) is in the same directory as the executable.

---

## 📁 Project Structure

```
.
├── main.cpp
├── MerkelMain.cpp / MerkelMain.h
├── OrderBook.cpp / OrderBook.h
├── CSVReader.cpp / CSVReader.h
├── Candlestick.cpp / Candlestick.h
├── OrderBookEntry.h
├── Wallet.cpp / Wallet.h
├── 20200601.csv
```

- `MerkelMain`: Main interaction handler for user input and output
- `OrderBook`: Handles order management and market logic
- `Candlestick`: Calculates and prints candlestick charts
- `CSVReader`: Parses CSV files for both orders and candlestick data
- `Wallet`: Manages the user’s crypto balances

---

## 🧰 Technologies Used

- **C++17**
- **Standard Template Library (STL)**
- **Console-based plotting and interaction**

---

## 🧠 Developer Commentary

This was one of the most rewarding C++ projects I’ve worked on. It required a strong grasp of object-oriented design and data handling from CSV files. Some insights and reflections:

- Initially, it was tricky to decide the right data structures for managing orders efficiently. I chose `std::vector` for simplicity and used sorting where necessary for simulation accuracy.
- Debugging time-based transitions between timestamps in the order book made me appreciate the importance of robust testing.
- I faced issues with rendering visual candlesticks due to formatting constraints in the console. After a few iterations, I managed to implement a basic ASCII-style visualisation that captures essential market trends.
- I aimed for modularity by separating classes like `CSVReader`, `Candlestick`, `OrderBook`, and `Wallet`, making the system easier to maintain and extend.
- Looking back, I would enhance user interaction with command input validation and perhaps even extend to a graphical interface in future versions.

---

## 🎓 Educational Scope

This project was created as part of the **Object-Oriented Programming (OOP)** and **Data Structures** module in C++. It served to demonstrate proficiency in:

- C++ class design and encapsulation
- File I/O with real-world data (CSV)
- Algorithmic logic in market simulation
- Code modularity and reusability

