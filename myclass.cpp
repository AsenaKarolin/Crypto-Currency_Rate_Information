#include <QtGui>
#include <QLabel>
#include "myclass.h"
#include <QRegExp>
#include <QHBoxLayout>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QHeaderView>
#include <iostream>
#include <unistd.h>
#include <QTimer>
using namespace std;
MyClass::MyClass(QWidget *parent) : QTableWidget(parent)
{
    //Sets the row and column number of the table
    table->setRowCount(7);
    table->setColumnCount(4);
    // Hides the horizontal and vertical header
    table->horizontalHeader()->setVisible(false);
    table->verticalHeader()->setVisible(false);
    //Fills the inner cells of the table with the string "Connecting" to initialize
    for (int i = 1; i < 7; i++){
          for (int j = 1; j < 4; j++) {
              QTableWidgetItem *item = new QTableWidgetItem("Connecting");//(tr("%1").arg(pow(i, j+1)));
              table->setItem(i, j, item);
          }
      }
    //Obtains the current time in hh:mm:ss format
    QString time = "Time: " + (QTime::currentTime().toString("hh:mm:ss"));

    //Writes the time in the upper right cell of the table
    table->setItem(0,0,new QTableWidgetItem(time));
    //Writes the constant strings to the table
    table->setItem(0,1,new QTableWidgetItem("USD"));
    table->setItem(0,2,new QTableWidgetItem("EUR"));
    table->setItem(0,3,new QTableWidgetItem("GBP"));
    table->setItem(1,0,new QTableWidgetItem("Bitcoin"));
    table->setItem(2,0,new QTableWidgetItem("Ethereum"));
    table->setItem(3,0,new QTableWidgetItem("Ripple"));
    table->setItem(4,0,new QTableWidgetItem("Litecoin"));
    table->setItem(5,0,new QTableWidgetItem("Monero"));
    table->setItem(6,0,new QTableWidgetItem("Zcash"));

    //Sets the layout
     QHBoxLayout *layout = new QHBoxLayout;
     layout->addWidget(table);
     setLayout(layout);

     //Connects to the API and extracts the necessary information
     manager = new QNetworkAccessManager(this) ;
     connect(manager, SIGNAL(finished(QNetworkReply *)),this, SLOT(replyFinished(QNetworkReply *)));
     //Sends the information to the slot "replyFinished()"
     manager->get(QNetworkRequest(QUrl("https://api.coingecko.com/api/v3/simple/price?ids=bitcoin,ethereum,ripple,litecoin,monero,zcash&vs_currencies=usd,eur,gbp")));

     //Sets a timer to call the "myTimer()" slot every 20000 ms (20 seconds) and update the values in the table
     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(myTimer()));
     timer->start(20000);


}
void MyClass::myTimer(){
    //Connects to the API and extracts the necessary information
    manager = new QNetworkAccessManager(this) ;
    connect(manager, SIGNAL(finished(QNetworkReply *)),this, SLOT(replyFinished(QNetworkReply *)));
    //Sends the information to the slot "replyFinished()"
    manager->get(QNetworkRequest(QUrl("https://api.coingecko.com/api/v3/simple/price?ids=bitcoin,ethereum,ripple,litecoin,monero,zcash&vs_currencies=usd,eur,gbp")));
}

void MyClass::replyFinished(QNetworkReply *reply)  {

     //Stores the information obtained from the API in a string called "data"
     QString data = (QString) reply->readAll();

     //Parses the string using regular expressions
     //Finds the values of bitcoin and puts the information into the corresponding cells
     QRegExp rx("bitcoin\":.\"usd\":(\\d+\\.\\d+),\"eur\":(\\d+\\.\\d+),\"gbp\":(\\d+\\.\\d+)");
     if ( rx.indexIn(data) != -1 ) {

       table->setItem(1,1,new QTableWidgetItem(rx.cap(1)));
       table->setItem(1,2,new QTableWidgetItem(rx.cap(2)));
       table->setItem(1,3,new QTableWidgetItem(rx.cap(3)));

     }
     //Finds the values of ethereum and puts the information into the corresponding cells
     QRegExp rx2("ethereum\":.\"usd\":(\\d+\\.\\d+),\"eur\":(\\d+\\.\\d+),\"gbp\":(\\d+\\.\\d+)");
     if ( rx2.indexIn(data) != -1 ) {

       table->setItem(2,1,new QTableWidgetItem(rx2.cap(1)));
       table->setItem(2,2,new QTableWidgetItem(rx2.cap(2)));
       table->setItem(2,3,new QTableWidgetItem(rx2.cap(3)));

     }
     //Finds the values of ripple and puts the information into the corresponding cells
     QRegExp rx3("ripple\":.\"usd\":(\\d+\\.\\d+),\"eur\":(\\d+\\.\\d+),\"gbp\":(\\d+\\.\\d+)");
     if ( rx3.indexIn(data) != -1 ) {

       table->setItem(3,1,new QTableWidgetItem(rx3.cap(1)));
       table->setItem(3,2,new QTableWidgetItem(rx3.cap(2)));
       table->setItem(3,3,new QTableWidgetItem(rx3.cap(3)));

     }
     //Finds the values of litecoin and puts the information into the corresponding cells
     QRegExp rx4("litecoin\":.\"usd\":(\\d+\\.\\d+),\"eur\":(\\d+\\.\\d+),\"gbp\":(\\d+\\.\\d+)");
     if ( rx4.indexIn(data) != -1 ) {

       table->setItem(4,1,new QTableWidgetItem(rx4.cap(1)));
       table->setItem(4,2,new QTableWidgetItem(rx4.cap(2)));
       table->setItem(4,3,new QTableWidgetItem(rx4.cap(3)));

     }
     //Finds the values of monero and puts the information into the corresponding cells
     QRegExp rx5("monero\":.\"usd\":(\\d+\\.\\d+),\"eur\":(\\d+\\.\\d+),\"gbp\":(\\d+\\.\\d+)");
     if ( rx5.indexIn(data) != -1 ) {

       table->setItem(5,1,new QTableWidgetItem(rx5.cap(1)));
       table->setItem(5,2,new QTableWidgetItem(rx5.cap(2)));
       table->setItem(5,3,new QTableWidgetItem(rx5.cap(3)));

     }
     //Finds the values of zcash and puts the information into the corresponding cells
     QRegExp rx6("zcash\":.\"usd\":(\\d+\\.\\d+),\"eur\":(\\d+\\.\\d+),\"gbp\":(\\d+\\.\\d+)");
     if ( rx6.indexIn(data) != -1 ) {

       table->setItem(6,1,new QTableWidgetItem(rx6.cap(1)));
       table->setItem(6,2,new QTableWidgetItem(rx6.cap(2)));
       table->setItem(6,3,new QTableWidgetItem(rx6.cap(3)));

     }
     //Obtains the current time in hh:mm:ss format
     QString time = "Time: " + (QTime::currentTime().toString("hh:mm:ss"));
     table->setItem(0,0,new QTableWidgetItem(time));

}
