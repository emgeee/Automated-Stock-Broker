#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../StockBroker/stockbroker.h"
#include <QGroupBox>
#include <QRadioButton>
#include <QBoxLayout>

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
    QGroupBox orderList;
    QRadioButton buy;

};

#endif // MAINWINDOW_H
