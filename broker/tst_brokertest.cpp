#include <QtCore/QString>
#include <QtTest/QtTest>

class BrokerTest : public QObject
{
    Q_OBJECT
    
public:
    BrokerTest();
    
private Q_SLOTS:
    void testCase1();
};

BrokerTest::BrokerTest()
{
}

void BrokerTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(BrokerTest)

#include "tst_brokertest.moc"
