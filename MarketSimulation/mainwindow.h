#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../StockBroker/stockbroker.h"
#include <QComboBox>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include "simbroker.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QComboBox dropdown;
    QRadioButton buy;
    QRadioButton sell;
    QPushButton submit;
    QLabel symbol;
    QLabel shares;
    QLabel limit;
    QLabel stop;
    QLineEdit symbolEdit;
    QLineEdit sharesEdit;
    QLineEdit limitEdit;
    QLineEdit stopEdit;

    SimBroker *broker;

};

#endif // MAINWINDOW_H
