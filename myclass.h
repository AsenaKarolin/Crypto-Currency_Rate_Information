#include <QtGui>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QLabel>
#include <QTableWidget>
#include <QTimer>
class MyClass : public QTableWidget
{
    Q_OBJECT

    public:
      MyClass(QWidget *parent = 0);


    public slots:
      void replyFinished(QNetworkReply * reply) ;
      void myTimer();

    private:
      QTableWidget *table= new QTableWidget();
      QNetworkAccessManager *manager ;
} ;
