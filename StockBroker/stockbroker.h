#ifndef STOCKBROKER_H
#define STOCKBROKER_H

#include "StockBroker_global.h"
#include "order.h"
#include <QList>
#include <QDebug>

class STOCKBROKERSHARED_EXPORT StockBroker {
public:
    StockBroker(void *marketOrderBuyCallback,void *marketOrderSellCallback);

    void updateMarket(float value);
    void placeOrder(Order *o);
    void executeOrder(Order *o);

private:
    float m_value;

    // Callback function to place a market order
    void *placeMarketBuyOrder;
    void *placeMarketSellOrder;

    QList<Order*> *orderList;

};

#endif // STOCKBROKER_H
