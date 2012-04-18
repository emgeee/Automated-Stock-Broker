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

    QVBoxLayout *orderList = new QVBoxLayout();
    orderList->addWidget(&buy);
    orderList->addWidget(&sell);
    orderList->addWidget(&dropdown);
    QWidget *orderWidget = new QWidget();
    orderWidget->setLayout(orderList);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(orderWidget);
    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);

    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
