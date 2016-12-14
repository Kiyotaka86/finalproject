#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plist = new std::vector<Product*>;
    defaultwindow();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::defaultwindow()
{
    ui->table1->setColumnCount(3);
    ui->table1->setRowCount(0);
    QStringList tableheader;
    tableheader <<"Name" <<"Stock"<<"Year/Month";
    ui->table1->setHorizontalHeaderLabels(tableheader);

    ui->month->setRange(1,12);
    ui->year->setRange(1800,3000);
    ui->year->setValue(2015);
    ui->n_stock->setMaximum(999999999);
}

void MainWindow::on_pushButton_clicked()
{
    name= ui->Product_name->text();
    stock=ui->n_stock->value();
    year = ui->year->value();
    month = ui->month->value();
    Product* pro= new Product(name, stock, year, month);
    plist->push_back(pro);
    ui->added->insertPlainText(name +" "+ QString::number(year)+"/"+QString::number(month)+" added\n");


    ui->n_stock->clear();


}



void MainWindow::printtable()
{

}

void MainWindow::on_refresh_clicked()
{
    ui->table1->clear();
    ui->table1->setRowCount(0);
    QStringList tableheader;
    tableheader <<"Name" <<"Stock"<<"Year/Month";
    ui->table1->setHorizontalHeaderLabels(tableheader);
    if(plist->size()==0){}
    else{
        for(size_t i=0;i < plist->size(); ++i)
        {
            ui->table1->insertRow(i);
            ui->table1->setItem(i,0, new QTableWidgetItem("mmkmk"));
            ui->table1->setItem(i,1, new QTableWidgetItem ("kokoko"));
            ui->table1->setItem(i,2, new QTableWidgetItem ("loko"));
        }
    }
}


QString Product::getName() const
{
    return name;
}
