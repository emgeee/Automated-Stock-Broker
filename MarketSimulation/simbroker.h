#ifndef SIMBROKER_H
#define SIMBROKER_H

#include "../StockBroker/stockbroker.h"
class SimBroker : protected StockBroker
{
public:
    SimBroker(QString);

    bool placeMarketBuyOrder(QString, int);
    bool placeMarketSellOrder(QString, int);

};

#endif // SIMBROKER_H
