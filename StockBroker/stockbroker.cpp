#include "stockbroker.h"


StockBroker::StockBroker()
{

    orderList = new QList<Order*>();
}

void StockBroker::updateMarket(float value)
{
    m_value = value;

    QList<Order> marketOrders;

    // iterate through all lists and convert appropriate orders to market order
    // TODO convert indexes to enable deletion
    foreach(Order *o, *orderList){
        switch (o->type()){
        case BUY_STOP:
            if(o->getStop() >= m_value){
                // TODO append new order
                //marketOrders << ;

                // TODO remove order from list
            }

            break;

        default:
            continue;
            break;
        }
    }
}

// Add a new order to the order list
void StockBroker::placeOrder(Order *o)
{

    // execute market orders immediately
    if(o->type() == MARKET_BUY || o->type() == MARKET_SELL){
        executeOrder(o);

    }else{
        *orderList << o;
    }

}

// Execute a buy or a sell market order
void StockBroker::executeOrder(Order *o)
{
    if(o->type() == MARKET_BUY){
        qDebug() << "Executing Market Buy Order";
        StockBroker::placeMarketBuyOrder(o->getSymbol(), o->getShares());
    }else if(o->type() == MARKET_SELL){
        qDebug() << "Executing Market Sell Order";
        StockBroker::placeMarketSellOrder(o->getSymbol(), o->getShares());
    }

    // TODO: execute order callback function

}
