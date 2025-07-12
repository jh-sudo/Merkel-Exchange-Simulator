#include "Candlestick.h"
#include <iostream>

Candlestick::Candlestick(
        std::string time,
        std::string product,
        std::string type,
        double high,
        double low,
        double open,
        double close): time(time),
                       product(product),
                       type(type),
                       high(high),
                       low(low),
                       open(open),
                       close(close){}

//task 1
void Candlestick::printCandlesticks()
{
    std::cout <<time<<"\t"
              <<product<<"\t"
              <<type<<"\t"
              <<high<<"\t"
              <<low<<"\t"
              <<open<<"\t"
              <<close<<"\t"
              <<std::endl;
}

void Candlestick::printCandlesticksTable(std::vector<Candlestick>candles)
{
     std::cout <<"time"<<"\t"<<"product"<<"\t"<<"type"<<"\t"
              <<"high"<<"\t"<<"low"<<"\t"<<"open"<<"\t"<<"close"<<"\t"
              <<std::endl;
    for(Candlestick& candles:candles){
        candles.printCandlesticks();

    }
}


//task 1
std::vector<Candlestick>Candlestick::calculateCandlesticks(
    std::vector<OrderBookEntry> entries)
{
    std::vector<Candlestick> candles;
    
    std::string product{entries[0].product},
                time{entries[0].timestamp},
                type{OrderBookEntry::obtToString(entries[0].orderType)};

    double high, low, open, close;
    double totalValue, totalAmount;

    std::string firstTimeStamp{entries[0].timestamp};

    for(OrderBookEntry &entry : entries)
    {   
        if(time == entry.timestamp)
        {
            
            totalValue += entry.price * entry.amount;
            totalAmount += entry.amount;
            high = std::max(high,entry.price);
            low = std::min(low,entry.price);
        }
        else 
        {
            
            if(time == firstTimeStamp)
            {
                open = totalValue/totalAmount;
            }
            else
            {
                close = totalValue/totalAmount;
                candles.push_back(
                        Candlestick{time,product,type,high,low,open,close});
                open = close;
            }

            //reset
            time = entry.timestamp;
            product = entry.product;
            type = OrderBookEntry::obtToString(entry.orderType);

            high = low = entry.price;
            totalValue = totalAmount = 0.;
        }
    }
    return candles;
}

//task 2
void Candlestick::plotCandlesticks(std::vector<Candlestick>candles)
{

    //determine the range of y
    double highest = candles[0].high;
    double lowest = candles[0].low;

    // Find the highest and lowest values in the candlesticks
    for(Candlestick candle: candles)
    {
        highest = std::max(highest, candle.high);
        lowest = std::min(lowest, candle.low);
    }

    int steps = 100;
    double rangeY = highest - lowest;
    double stepSize = rangeY/steps;

    // Loop through y values from highest to lowest
    for(double y = highest; y > lowest; y -= stepSize)
    {
        std::cout <<y<< "\t";

        int maxSize = 20;
        // Adjust maxSize if it's greater than the number of candles
        if(maxSize> candles.size())
        {
            maxSize = candles.size();
        }

        // Loop through candles to create the candlestick plot
        for(int i=0; i<maxSize; i++)
        {
            Candlestick candle = candles[i];
            if(y> candle.high || y< candle.low)
            {
                std::cout<<"     ";
            }
            else if((y<candle.high && y> candle.open)
                                        || 
                    (y >candle.low && y<candle.close))
            {
                std::cout<<"  |  ";
            }
            else 
            {
                if(candle.open > candle.close)
                {
                    std::cout<<" --- ";
                }
                else
                {
                    std::cout <<" +++ ";
                }
            }
            
        }
        std::cout<<std::endl;
    }
    
}