#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QRadioButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QTimer>

#include "simbroker.h"
#include "stockbroker.h"
#include "simulationmarket.h"


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
    QTextEdit marketWindow;

    SimBroker *broker;
    QTimer *timer;
    simulationMarket *market;

public slots:
    void timerTimeout();
};

#endif // MAINWINDOW_H
