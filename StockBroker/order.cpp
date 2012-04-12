#include "order.h"

Order::Order(QObject *parent) :
    QObject(parent)
{
}

QString Order::type()
{
    return typeOfOrder;
}
