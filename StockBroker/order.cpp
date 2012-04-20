#include "order.h"

// Constructor
Order::Order(T_ORDER type, QString symbol, int shares, float stop, float limit, QObject *parent):
    QObject(parent), m_typeOfOrder(type), m_stockSymbol(symbol), m_shares(shares), m_stopPrice(stop), m_limitPrice(limit)
{
    callBack = NULL;
    m_timePlaced = QDateTime::currentDateTime();
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


QDateTime Order::getDate()
{
    return m_timePlaced;
}

// Should this be by a pointer?
void Order::setDate(QDateTime d)
{
    m_timePlaced = d;
}

bool Order::operator<(const Order &o) const
{
    return (m_timePlaced < o.m_timePlaced);
}
