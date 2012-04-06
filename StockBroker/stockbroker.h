#ifndef STOCKBROKER_H
#define STOCKBROKER_H

#include "StockBroker_global.h"
#include "order.h"
#include <QList>

class STOCKBROKERSHARED_EXPORT StockBroker {
public:
    StockBroker(void *marketOrderCallback);

    void updateMarket(float value);
    void placeOrder(Order o);

private:
    float m_value;

    // Callback function to place a market order
    void *placeMarketOrder;

    QList<Order> *orderList;

};

#endif // STOCKBROKER_H
