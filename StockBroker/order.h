#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <QDateTime>

// Do buy and sell need separate individual order types?
enum T_ORDER {MARKET_BUY,MARKET_SELL};

class Order : public QObject
{
    Q_OBJECT
public:
    explicit Order(QString symbol, int shares, QObject *parent = 0);

    // Getter method for type of order
    T_ORDER type();
    int getShares();
    QString getSymbol();

    void setShares(int number);


    
private:
    int m_shares;
    float m_value;
    QDateTime m_timePlaced;
    T_ORDER m_typeOfOrder;
    QString m_stockSymbol;

signals:
    
public slots:
    
};

#endif // ORDER_H
