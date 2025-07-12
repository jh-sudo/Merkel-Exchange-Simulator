#pragma once
#include <string>
#include<vector>
#include "OrderBookEntry.h"

class Candlestick
{
    public:
    //properties
        std::string time, product, type;
        double high, low, open, close;

    Candlestick(
        std::string time,
        std::string product,
        std::string type,
        double high,
        double low,
        double open,
        double close);

    //task 1
    void printCandlesticks();
    static void printCandlesticksTable(std::vector<Candlestick> candles);

    static std::vector<Candlestick>calculateCandlesticks(
        std::vector<OrderBookEntry> entries);

    //task 2 & 3 
    static void plotCandlesticks(std::vector<Candlestick>candles);

};