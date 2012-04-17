#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <QDateTime>

// Do buy and sell need separate individual order types?
enum T_ORDER {MARKET_BUY, MARKET_SELL, BUY_STOP, BUY_LIMIT, BUY_STOP_LIMIT,
             SELL_STOP, SELL_LIMIT, SELL_STOP_LIMIT};

class Order : public QObject
{
    Q_OBJECT
public:
    explicit Order( QString symbol, int shares, float stop = 0, float limit = 0, QObject *parent = 0);

    // Getter method for type of order
    T_ORDER type();
    int getShares();
    float getLimit();
    float getStop();
    QString getSymbol();

    void setShares(int);
    void setLimit(float);
    void setStop(float);

    
private:
    int m_shares;
    float m_limitPrice;
    float m_stopPrice;

    QDateTime m_timePlaced;
    T_ORDER m_typeOfOrder;
    QString m_stockSymbol;

signals:
    
public slots:
    
};

#endif // ORDER_H
