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
#include "QTimer"
#include "QTime"


// the stock struct is stored inside of a list of structs
// this way the market can be tracked
struct stock{
    QString name;
    QString tickerSymbol;
    float currentPrice;
    int quantityAvailable;
};

class simulationMarket : public QThread
{
public:
    simulationMarket();
    void run();



    void printStocks();
    void generateFakeMarketFromFile(QString fileName);

    bool canProccessOrder(QString ticker, int quantity);
    bool doesStockExist(QString ticker);
    bool updateStockPrice(QString ticker);

    float getPrice(QString ticker);
    float randFloatGenerator(float a, float b);

    QList<stock*> stocks;

};

#endif // SIMULATIONMARKET_H
