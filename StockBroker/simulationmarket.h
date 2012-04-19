#ifndef SIMULATIONMARKET_H
#define SIMULATIONMARKET_H


#include "QThread"
#include "QHash"
#include "QString"
#include "QList"
#include "QFile"

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


    void generateFakeMarketFromFile(QFile inputFile);

    QList<*stock> *stocks;

};

#endif // SIMULATIONMARKET_H
