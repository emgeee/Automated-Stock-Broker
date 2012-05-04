#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <QDateTime>
#include <functional>

// Do buy and sell need separate individual order types?
enum T_ORDER {MARKET_BUY, MARKET_SELL, BUY_STOP, BUY_LIMIT, BUY_STOP_LIMIT,
             SELL_STOP, SELL_LIMIT, SELL_STOP_LIMIT};

class Order : public QObject
{
    Q_OBJECT
public:
    explicit Order(T_ORDER, QString, int user, int, float stop = 0, float limit = 0, QObject *parent = 0);

    /*
      Each of the variables use should have a self explanatory name and they can be set using the
      following methods.

      share - the number of shares in the order
      userId - a unique number identifying a customer
      limitPrice - the limit price, only used for limit and buy-limit orders
      stopPrice - a buy price, only user for buy and buy-stop orders
      timePlaced - the time the order was placed
      typeOfOrder - use enum T_ORDER - type of order
      stockSymbol - the ticker symbol for the appropriate stock

      User defined callback functions - You can use the "setCallback()"
      function to set a callback funtion that will be executed after and order
      has been successfully executed. An example could be to look up a users
      email address based on their userID and email them a message with an
      update.

      */

    // Getter method for type of order
    T_ORDER type();
    int getShares();
    float getLimit();
    float getStop();
    QString getSymbol();
    QDateTime getDate();
    int getUser();

    // Setter method for each type
    void setType(T_ORDER t);
    void setShares(int);
    void setLimit(float);
    void setStop(float);
    void setCallback(void (*f)(Order*));
    void executeCallback(Order*);
    void setDate(QDateTime);

    // Needed for sorting
    bool operator<(const Order&) const;

private:
    int m_shares;
    int m_userID;
    float m_limitPrice;
    float m_stopPrice;

    QDateTime m_timePlaced;
    T_ORDER m_typeOfOrder;
    QString m_stockSymbol;

    std::pointer_to_unary_function<Order*, void> *callBack;

signals:
    
public slots:
    
};

#endif // ORDER_H
