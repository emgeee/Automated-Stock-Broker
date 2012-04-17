#include "order.h"

// Constructor - no value required
Order::Order(QString symbol, int shares, QObject *parent) :
    QObject(parent), m_stockSymbol(symbol), m_shares(shares)
{
}

// Constructor - allows assigning value
Order::Order(float value, QString symbol, int shares, QObject *parent) :
    QObject(parent), m_value(value), m_stockSymbol(symbol), m_shares(shares)
{
}

T_ORDER Order::type()
{
    return m_typeOfOrder;
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
