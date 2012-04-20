#include "stockbroker.h"


StockBroker::StockBroker(QString symbol) :
    m_symbol(symbol)
{
    orderList = new QList<Order*>();
}

void StockBroker::updateMarket(float value)
{
    m_value = value;

    // create a local reference for easier access
    QList<Order*> &list = *orderList;

    QList<Order*> executionList;

    // iterate through all lists and convert appropriate orders to new orders
    // and execute any market orders
    for(int i = 0; i < orderList->length(); i++){
        switch (list[i]->type()){
        case BUY_STOP:
            if(list[i]->getStop() >= m_value){
                list[i]->setType(MARKET_BUY);
                executionList << list[i];

                //remove order after execution
                list.removeAt(i);
                i--;
            }
            break;

        case BUY_LIMIT:
            if(list[i]->getLimit() <= m_value){
                list[i]->setType(MARKET_BUY);
                executionList << list[i];

                //remove order after execution
                list.removeAt(i);
                i--;
            }
            break;

        case BUY_STOP_LIMIT:
            if(list[i]->getStop() >= m_value){
                //becomes Buy limit
                list[i]->setType(BUY_LIMIT);

                //Must recheck if the new limit order should be executed
                i--;
            }
            break;

        case SELL_STOP:
            if(list[i]->getStop() <= m_value){
                list[i]->setType(MARKET_BUY);
                executionList << list[i];

                //remove order after execution
                list.removeAt(i);
                i--;
            }
            break;

        case SELL_LIMIT:
            if(list[i]->getLimit() >= m_value){
                list[i]->setType(MARKET_BUY);
                executionList << list[i];

                //remove order after execution
                list.removeAt(i);
                i--;
            }
            break;

        case SELL_STOP_LIMIT:
            if(list[i]->getStop() <= m_value){
                //becomes Buy limit
                list[i]->setType(BUY_LIMIT);

                //Must recheck if the new limit order should be executed
                i--;
            }
            break;

        default:

            break;
        }
    }

    // sort the execution list based off of time placed
    qSort(executionList);

    // Execute orders
    foreach(Order *o, executionList){
        executeOrder(o);
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

    o->executeCallback(o);
}


QString StockBroker::getSymbol()
{
    return m_symbol;
}



