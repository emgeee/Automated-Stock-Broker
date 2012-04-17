#ifndef STOCKBROKER_H
#define STOCKBROKER_H

#include "StockBroker_global.h"
#include "order.h"
#include <QList>
#include <QDebug>


class STOCKBROKERSHARED_EXPORT StockBroker {
public:
    StockBroker();

    // Callback function to place a market order
    static bool *(placeMarketBuyOrder)(QString symbol, int shares);
    static bool *(placeMarketSellOrder)(QString symbol, int shares);

    void updateMarket(float value);
    void placeOrder(Order *o);

private:
    float m_value;

    QList<Order*> *orderList;

    void executeOrder(Order *o);

};

#endif // STOCKBROKER_H
