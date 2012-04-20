#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    broker = new SimBroker("GOOG");
    Order *o = new Order(MARKET_BUY,"GOOG",100, 23, 30);
    broker->placeOrder(o);

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

    setCentralWidget(mainWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}




