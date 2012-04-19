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

// IF :
//      a new buy order
//      a new sell order
//      price flucation
//
// OCCURS, this method will update the stock within the Market List

void simulationMarket::updateStockInMarket(QString ticker, int price, int quantity)
{

    for(int i = 0; i < stocks->size(); ++i){

        // if tickers match, found in List
        // remove from list, update then reinsert
        if(stocks->at(i).tickerSymbol == ticker){
            stock *updatedStock = new stock();
            updatedStock->tickerSymbol = ticker;
            updatedStock->currentPrice = price;
            updatedStock->quantityAvailable = quantity;

            stocks->append(*updatedStock);

            stocks->removeAt(i);
}

}

}


// Logs all of the price flucations to a text file
// This is good to see whenever the market prices changes
// it will be written to a file using a timer
void simulationMarket::logStockPriceHistory()
{


}
