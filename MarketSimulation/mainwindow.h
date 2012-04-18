#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../StockBroker/stockbroker.h"
#include <QFontComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
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
    QFontComboBox buy;
    QFontComboBox sell;
    QPushButton submit;
    QLabel symbol;
    QLabel shares;
    QLabel limit;
    QLabel stop;
    QLineEdit symbolEdit;
    QLineEdit sharesEdit;
    QLineEdit limitEdit;
    QLineEdit stopEdit;

};

#endif // MAINWINDOW_H
