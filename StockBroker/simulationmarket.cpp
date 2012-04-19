#include "simulationmarket.h"

simulationMarket::simulationMarket()
{
    generateFakeMarketFromFile("tester.txt");

}

// handles updating the values from orders placed
void simulationMarket::run(){



}


// creates a fake market, with stocks, values, and quantities
// reads from input file and inserts into the
// stock market list, which keeps track of all values of each stock
void simulationMarket::generateFakeMarketFromFile(QString fileName){

    QFile inputFile(fileName);


    if(!inputFile.open(QIODevice::ReadOnly)){
        qDebug () << "Error with file..." << endl;
    }

    else {
        QTextStream in(&inputFile);

        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList fields = line.split(",");


            qDebug() << fields << endl;

            stock *newStock = new stock();

            newStock->tickerSymbol = fields.at(0);
            newStock->currentPrice = fields.at(1);
            newStock->quantityAvailable = fields.at(2).toInt();

            stocks->append(*newStock);

        }
        inputFile.close();
    }

}
