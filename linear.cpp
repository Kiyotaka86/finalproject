#include "mainwindow.h"
#include "ui_mainwindow.h"





void MainWindow::linearregg(QString n, QVector<Product*> &p)
{
    QVector<Product*> copy;

    for(auto i: p){
        if(i->getName()==n)
            copy.push_back(i);
    }

    auto i = copy.begin();
    std::sort(i, copy.end());





}
