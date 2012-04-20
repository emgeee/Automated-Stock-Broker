#ifndef SIMULATIONMARKET_H
#define SIMULATIONMARKET_H


#include "QThread"
#include "QHash"
#include "QString"
#include "QList"
#include "QFile"
#include "QDebug"
#include "QStringList"
#include "QListIterator"

// the stock struct is stored inside of a list of structs
// this way the market can be tracked
struct stock{
    QString name;
    QString tickerSymbol;
    QString currentPrice;
    int quantityAvailable;
};

class simulationMarket : public QThread
{
public:
    simulationMarket();
    void run();


    void logStockPriceHistory();

    void generateFakeMarketFromFile(QString fileName);

    int updateStockInMarket(QString ticker, int price, int quantity);
    QList<stock*> *stocks;

};

#endif // SIMULATIONMARKET_H
