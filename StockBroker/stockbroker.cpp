#include "stockbroker.h"


StockBroker::StockBroker(void *marketOrderCallback)
    : placeMarketOrder(marketOrderCallback)
{
}

void StockBroker::updateMarket(float value)
{
    m_value = value;

}

// Add a new order to the order list
void StockBroker::placeOrder(Order o)
{


}
