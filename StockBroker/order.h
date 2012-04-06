#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <QDateTime>


// Do buy and sell need separate individual order types?
enum T_ORDER {MARKET_BUY, MARKET_SELL};

class Order : public QObject
{
    Q_OBJECT
public:
    explicit Order(QObject *parent = 0);
    
private:
    float m_value;
    QDateTime timePlaced;

signals:
    
public slots:
    
};

#endif // ORDER_H
