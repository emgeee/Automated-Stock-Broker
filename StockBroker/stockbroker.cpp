#include "stockbroker.h"


StockBroker::StockBroker(void *marketOrderBuyCallback,
                         void *marketOrderSellCallback)
    : placeMarketBuyOrder(marketOrderBuyCallback),
      placeMarketSellOrder(marketOrderSellCallback)
{
    if(placeMarketBuyOrder == NULL || placeMarketSellOrder == NULL){
        qDebug() << "Must pass in a valid market order function";
        return;
    }

    orderList = new QList<Order*>();
}

void StockBroker::updateMarket(float value)
{
    m_value = value;
}

// Add a new order to the order list
void StockBroker::placeOrder(Order *o)
{

    // execute market orders immediately
    if(o->type() == "MARKET_BUY" || o->type() == "MARKET_SELL"){
        executeOrder(o);

    }else{
        *orderList << o;
    }

}

// Execute a buy or a sell market order
void StockBroker::executeOrder(Order *o)
{

}
