#ifndef STOCKBROKER_H
#define STOCKBROKER_H

#include "StockBroker_global.h"
#include "order.h"
#include <QList>
#include <QDebug>


class STOCKBROKERSHARED_EXPORT StockBroker {

public:
    // Virtual Callback function to place a market order
    virtual bool placeMarketBuyOrder(QString symbol, int shares) = 0;
    virtual bool placeMarketSellOrder(QString symbol, int shares) = 0;

    void updateMarket(float value);
    void placeOrder(Order *o);

    QString getSymbol();

protected:
    float m_value;

    QList<Order*> *orderList;

    void executeOrder(Order *o);
    QString m_symbol;

};

#endif // STOCKBROKER_H
