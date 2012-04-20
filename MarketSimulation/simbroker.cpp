#include "simbroker.h"

SimBroker::SimBroker(QString symbol)
{
    orderList = new QList<Order*>();
    m_symbol = symbol;
}

bool SimBroker::placeMarketBuyOrder(QString symbol, int shares)
{
    qDebug() << shares << " sold of " << symbol;
    return true;
}

bool SimBroker::placeMarketSellOrder(QString symbol, int shares)
{
    qDebug() << shares << " bought of " << symbol;
    return true;
}
