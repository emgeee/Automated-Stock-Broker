#include "stockbroker.h"


StockBroker::StockBroker()
{
    orderList = new QList<Order*>();
}

void StockBroker::updateMarket(float value)
{
    m_value = value;

    // iterate through all lists and convert appropriate orders to new orders
    // and execute any market orders
    // TODO convert indexes to enable deletion
    for(int i = 0; i < orderList->length(); i++){
        switch ((*orderList)[i]->type()){
        case BUY_STOP:
            if((*orderList)[i]->getStop() >= m_value){

            }
            break;
        case BUY_LIMIT:
            if((*orderList)[i]->getStop() >= m_value){

            }
            break;
        case BUY_STOP_LIMIT:
            if((*orderList)[i]->getStop() >= m_value){

            }
            break;
        case SELL_STOP:
            if((*orderList)[i]->getStop() >= m_value){

            }
            break;
        case SELL_LIMIT:
            if((*orderList)[i]->getStop() >= m_value){

            }
            break;
        case SELL_STOP_LIMIT:
            if((*orderList)[i]->getStop() >= m_value){

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
