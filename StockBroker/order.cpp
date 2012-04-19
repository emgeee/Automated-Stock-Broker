#include "order.h"

// Constructor - no value required
Order::Order( QString symbol, int shares, float stop, float limit, QObject *parent):
    QObject(parent), m_stockSymbol(symbol), m_shares(shares), m_stopPrice(stop), m_limitPrice(limit)
{
    callBack = NULL;
}

// If this works...
void Order::setCallback(void (*f)(Order*))
{
    if(callBack != NULL)
        delete callBack;

    callBack = new std::pointer_to_unary_function<Order*, void>(f);

}

void Order::executeCallback(Order *o)
{
    if (callBack != NULL)
        (*callBack)(o);
}

T_ORDER Order::type()
{
    return m_typeOfOrder;
}

void Order::setType(T_ORDER t)
{
    m_typeOfOrder = t;
}

int Order::getShares()
{
    return m_shares;
}

void Order::setShares(int number)
{
    m_shares = number;
}

QString Order::getSymbol()
{
    return m_stockSymbol;
}

float Order::getLimit()
{
    return m_limitPrice;
}

void Order::setLimit(float value)
{
    m_limitPrice = value;
}

float Order::getStop()
{
    return m_stopPrice;
}

void Order::setStop(float value)
{
    m_stopPrice = value;
}

void Order::setSymbol(QString symbolName)
{
    m_stockSymbol = symbolName;
}


