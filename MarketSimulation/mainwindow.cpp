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

    broker = new SimBroker("GOOG");
    broker->updateMarket(30);


    ui->setupUi(this);
    setWindowTitle("Automated Stock Broker");

    //populate the drop down menus
    dropdown.addItem("Market");
    dropdown.addItem("Stop");
    dropdown.addItem("Limit");
    dropdown.addItem("Stop-Limit");
    dropdown1.addItem("User 1");
    dropdown1.addItem("User 2");

    //set text for radio buttons
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

    //organize buttons and drop down menus
    QVBoxLayout *orderList = new QVBoxLayout();
    orderList->addWidget(&buy);
    orderList->addWidget(&sell);
    orderList->addWidget(&dropdown);
    orderList->addWidget(&dropdown1);
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

    //initialize timer for market updates
    timer = new QTimer();
    timer->setInterval(2000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
    timer->start();

    //initialize timer for market flux
    marketFluxTimer = new QTimer();
    marketFluxTimer->setInterval(1000);
    connect(marketFluxTimer,SIGNAL(timeout()),this,SLOT(marketFluxTimerTimeout()));
    marketFluxTimer->start();

    //connect the submit button to a slot
    connect(&submit, SIGNAL(clicked()), this, SLOT(buttonPushed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerTimeout()
{
    //clear the text edit
    marketWindow.clear();
    //get a list of the current market
    QStringList marketList = market->getEntireMarket();
    //print each market statement to the text edit
    for(int i = 0; i<marketList.size(); i++) {
        marketWindow.append(marketList.at(i));
    }
}

void MainWindow::marketFluxTimerTimeout()
{
    market->fluctuatePrices(-5,5);

}

void MainWindow::buttonPushed() {
    T_ORDER orderType;
    int user;

    //determine the type of order to be placed
    QString type = dropdown.currentText();
    QString buyOrSell;
    //determine if it is a buy or sell
    if(buy.isChecked()) {
        buyOrSell = "buy";
    }
    else if(sell.isChecked()) {
        buyOrSell = "sell";
    }
    //if neither button is pushed show an error message
    else {
        QMessageBox msg;
        msg.setText("Please choose buy or sell");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
        return;
    }

    //determine the exact order type
    if(type == "Market") {
        if(buyOrSell == "buy") {
            orderType = MARKET_BUY;
        }
        else {
            orderType = MARKET_SELL;
        }
    }
    else if(type == "Stop") {
        if(buyOrSell == "buy") {
            orderType = BUY_STOP;
        }
        else {
            orderType = SELL_STOP;
        }
    }
    else if(type == "Limit") {
        if(buyOrSell == "buy") {
            orderType = BUY_LIMIT;
        }
        else {
            orderType = SELL_LIMIT;
        }
    }
    else if(type == "Stop-Limit") {
        if(buyOrSell == "buy") {
            orderType = BUY_STOP_LIMIT;
        }
        else {
            orderType = SELL_STOP_LIMIT;
        }
    }

    //determine the user;
    user = dropdown1.currentIndex() + 1;

    //broker = new SimBroker(symbolEdit.text());
    //broker->updateMarket(30);
    //create and order using the Order class
    Order *o = new Order(orderType,symbolEdit.text(),user, sharesEdit.text().toInt(), stopEdit.text().toInt(), limitEdit.text().toInt());
    o->setCallback(&callbackTest);

    //place the order and update the market
    broker->placeOrder(o);
    //broker->updateMarket(market->getPrice(symbolEdit.text()));

    //clear the line edits
    symbolEdit.clear();
    sharesEdit.clear();
    stopEdit.clear();
    limitEdit.clear();
}

