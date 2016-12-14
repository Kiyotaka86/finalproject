#include "mainwindow.h"
#include <QApplication>
#include <QDataStream>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <vector>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
