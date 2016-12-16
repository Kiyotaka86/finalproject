#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::linearregg(QString n, QVector<Product*> &p)
{
    QVector<Product*> copy;

    for(auto i: p){
        if(i->getName()==n)
            copy.push_back(i);
    }

    std::sort(copy.begin(), copy.end(), [](Product* a, Product* b){return a->getYm()<b->getYm();});


    // y = number of stock, copy->operator[i]()->stock;  y= copy[0] - copy.end() -1
    // x = number of elements... i+1 - copy->size()

    QVector<int> y;
    QVector<int> x;

    for(int i=0; i<copy.size(); ++i)
        y.push_back(copy[i]->getStock());

    for(int i=1; i<=copy.size(); ++i)
        x.push_back(i);

    int k = copy.size();

    double sumy = std::accumulate(y.begin(), y.end(), 0.0);
    double sumx = std::accumulate(x.begin(), x.end(), 0.0);
    double sumxy = 0.0;
    double sumxx = 0.0;

    for(int i=0; i<k; ++i)
        sumxy += (x[i])*(y[i]);
    for(int i=0; i<k; ++i)
        sumxx += (x[i])*(x[i]);

    //calculate slope and intercept, then the next val
     double slope = (((k)*(sumxy)-(sumx)*(sumy)))/((k)*(sumxx)-(sumx)*(sumx));

     double intercept = ((sumy) - (slope)*(sumx)) / (k);

     double next = (slope)*(k+1) + (intercept);

    ui->added->insertPlainText(QString::number(sumx) + "\n");
    ui->added->insertPlainText(QString::number(sumy) + "\n");
    ui->added->insertPlainText(QString::number(sumxx) + "\n");
    ui->added->insertPlainText(QString::number(sumxy) + "\n");
    ui->added->insertPlainText(QString::number(next) + "\n");



}
