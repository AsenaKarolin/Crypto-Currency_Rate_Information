#include <QtCore>
#include <QApplication>
#include "myclass.h"
#include <unistd.h>
int main(int argc,char *argv[])
{
   //Creates the application and executes it
   QApplication a(argc, argv);
   MyClass my;
   my.show();
   return a.exec();
}
