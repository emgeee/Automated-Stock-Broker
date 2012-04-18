#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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

    //organize buttons and drop down menu
    QVBoxLayout *orderList = new QVBoxLayout();
    orderList->addWidget(&buy);
    orderList->addWidget(&sell);
    orderList->addWidget(&dropdown);
    QWidget *orderWidget = new QWidget();
    orderWidget->setLayout(orderList);

    //organize labels and line edits
    QHBoxLayout *symbolLayout = new QHBoxLayout();
    symbolLayout->addWidget(&symbol);
    symbolLayout->addWidget(&symbolEdit);
    QWidget *symbolWidget = new QWidget();
    symbolWidget->setLayout(symbolLayout);

    QHBoxLayout *sharesLayout = new QHBoxLayout();
    sharesLayout->addWidget(&shares);
    sharesLayout->addWidget(&sharesEdit);
    QWidget *sharesWidget = new QWidget();
    sharesWidget->setLayout(sharesLayout);

    QHBoxLayout *limitLayout = new QHBoxLayout();
    limitLayout->addWidget(&limit);
    limitLayout->addWidget(&limitEdit);
    QWidget *limitWidget = new QWidget();
    limitWidget->setLayout(limitLayout);

    QHBoxLayout *stopLayout = new QHBoxLayout();
    stopLayout->addWidget(&stop);
    stopLayout->addWidget(&stopEdit);
    QWidget *stopWidget = new QWidget();
    stopWidget->setLayout(stopLayout);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(symbolWidget);
    layout->addWidget(sharesWidget);
    layout->addWidget(limitWidget);
    layout->addWidget(stopWidget);
    layout->addWidget(&submit);
    QWidget *wid = new QWidget();
    wid->setLayout(layout);

    //organize main layout
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(orderWidget);
    mainLayout->addWidget(wid);
    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);

    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
