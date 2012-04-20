#ifndef SIMBROKER_H
#define SIMBROKER_H

#include "stockbroker.h"

class SimBroker : StockBroker
{
public:
    SimBroker(QString);

    using StockBroker::updateMarket;
    using StockBroker::placeOrder;
    using StockBroker::getSymbol;

    bool placeMarketBuyOrder(QString, int);
    bool placeMarketSellOrder(QString, int);

};

#endif // SIMBROKER_H
