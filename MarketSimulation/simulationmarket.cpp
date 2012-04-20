#include "simulationmarket.h"

simulationMarket::simulationMarket()
{

}


void simulationMarket::run(){


}

void simulationMarket::fluctuatePrices()
{

    float flucation = randFloatGenerator(0.0, 25);
    foreach(stock *s, stocks){
       updateStockPrice(s->tickerSymbol,flucation);
    }

}


// creates a fake market, with stocks, values, and quantities
// reads from input file and inserts into the
// stock market list, which keeps track of all values of each stock
void simulationMarket::generateFakeMarketFromFile(QString fileName){

    QFile inputFile(fileName);

    if(!inputFile.open(QIODevice::ReadOnly)){
        qDebug () << inputFile.errorString() <<  endl;
    }

    else {
        QTextStream in(&inputFile);


        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList fields = line.split(",");

            stock *newStock = new stock();
            newStock->tickerSymbol = fields.at(0);
            newStock->currentPrice = fields.at(1).toFloat();
            newStock->quantityAvailable = fields.at(2).toInt();

            stocks.append(newStock);


        }

        inputFile.close();
    }

}


bool simulationMarket::canProccessOrder(QString ticker, int quantity)
{

    foreach(stock *s, stocks){
        if(s->tickerSymbol == ticker){
            if(s->quantityAvailable < quantity){
                return false; // can't not enough on the market
            }

        }
    }

    return true;
}

float simulationMarket::getPrice(QString ticker)
{


    if(doesStockExist(ticker))
    {

    foreach(stock *s, stocks){
        if(s->tickerSymbol == ticker){
            return s->currentPrice;
        }
    }
    }

    return -1; // didn't find in market


}

void simulationMarket::printStocks()
{


    foreach(stock *s, stocks){
        qDebug () << s->tickerSymbol << s->quantityAvailable << s->currentPrice << endl;
    }


}

bool simulationMarket::doesStockExist(QString ticker)
{
    foreach(stock *s, stocks){
        if(s->tickerSymbol == ticker){
            return true;
        }
    }

    return false;

}


float simulationMarket::randFloatGenerator(float a, float b)
{

    QTime t = QTime::currentTime();
    uint seed = t.msec();
    srand(seed);
    return ((b-a)*(float(rand())/RAND_MAX)) + a;
}

bool simulationMarket::updateStockPrice(QString ticker, float offSet)
{
    if(doesStockExist(ticker)){
        foreach(stock *s, stocks){
            if(s->tickerSymbol == ticker){
               s->currentPrice = s->currentPrice + offSet;
            }
        }
    }

    return false;
}

QStringList simulationMarket::getEntireMarket()
{
    QStringList marketList;
    foreach(stock *s, stocks){
        QString stockinfo = s->tickerSymbol + " - " + QString::number(s->currentPrice) + " " + QString::number(s->quantityAvailable);
        marketList.append(stockinfo);
    }

    return marketList;
}
