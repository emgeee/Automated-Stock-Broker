#include "mainwindow.h"
#include "ui_mainwindow.h"

void callbackTest(Order *o){
    qDebug() << o->getUser()<< "purchased" << o->getSymbol() ;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // TEST MARKET //

    market = new simulationMarket();
    market->generateFakeMarketFromFile("tester.txt");
    market->printStocks();
    // END TEST MARKET ///

    /////// TEST CODE
    broker = new SimBroker("GOOG");
    broker->updateMarket(30);
    Order *o = new Order(BUY_LIMIT,"GOOG",1, 11, 23., 20.);
    o->setCallback(&callbackTest);

    broker->placeOrder(o);

    broker->updateMarket(10.4);

    ///////

    ui->setupUi(this);
    setWindowTitle("Automated Stock Broker");

    //populate the drop down menus
    dropdown.addItem("Market");
    dropdown.addItem("Stop");
    dropdown.addItem("Limit");
    dropdown.addItem("Stop-Limit");
    buy.setText("Buy");
    sell.setText("Sell");

    //set text for labels and push button
    symbol.setText("Symbol:");
    shares.setText("Shares:");
    limit.setText("Limit:");
    stop.setText("Stop:");
    submit.setText("Submit");

    //set styles of widgets
    submit.setStyleSheet("background-color:green; color:white; border-color:white; border:2px solid;");

    //organize buttons and drop down menu
    QVBoxLayout *orderList = new QVBoxLayout();
    orderList->addWidget(&buy);
    orderList->addWidget(&sell);
    orderList->addWidget(&dropdown);
    orderList->addWidget(&submit);
    QWidget *orderWidget = new QWidget();
    orderWidget->setLayout(orderList);

    //organize labels and line edits
    QVBoxLayout *lableLayout = new QVBoxLayout();
    lableLayout->addWidget(&symbol);
    lableLayout->addWidget(&shares);
    lableLayout->addWidget(&limit);
    lableLayout->addWidget(&stop);
    QWidget *lableWidget = new QWidget();
    lableWidget->setLayout(lableLayout);
    lableWidget->setStyleSheet("margin-bottom:5px;");

    QVBoxLayout *editLayout = new QVBoxLayout();
    editLayout->addWidget(&symbolEdit);
    editLayout->addWidget(&sharesEdit);
    editLayout->addWidget(&limitEdit);
    editLayout->addWidget(&stopEdit);
    //editLayout->addWidget(&submit);
    QWidget *editWidget = new QWidget();
    editWidget->setLayout(editLayout);


    //organize main layout
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(orderWidget);
    mainLayout->addWidget(lableWidget);
    mainLayout->addWidget(editWidget);
    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);

    marketWindow.setReadOnly(true);
    QVBoxLayout *finalLayout = new QVBoxLayout();
    finalLayout->addWidget(mainWidget);
    finalLayout->addWidget(&marketWindow);
    QWidget *finalWidget = new QWidget();
    finalWidget->setLayout(finalLayout);

    setCentralWidget(finalWidget);

    timer = new QTimer();
    timer->setInterval(2000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
    timer->start();

    marketFluxTimer = new QTimer();
    marketFluxTimer->setInterval(1000);
    connect(marketFluxTimer,SIGNAL(timeout()),this,SLOT(marketFluxTimerTimeout()));
    marketFluxTimer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerTimeout()
{

    marketWindow.clear();
    QStringList marketList = market->getEntireMarket();
    for(int i = 0; i<marketList.size(); i++) {
        marketWindow.append(marketList.at(i));
    }
}

void MainWindow::marketFluxTimerTimeout()
{
    market->fluctuatePrices(0.0,5.6);

}



