#include "order.h"

Order::Order(QString symbol, int shares, QObject *parent) :
    QObject(parent), m_stockSymbol(symbol), m_shares(shares)
{
}

QString Order::type()
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
