#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plist = new QVector<Product*> ;
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
    year = ui->year->text();
    month = ui->month->text();

    if(name=="")
    {
        ui->added->insertPlainText("You need at least name!\n");
    }
    else{
        Product* pro= new Product(name, stock, year, month);
        plist->push_back(pro);
        ui->added->insertPlainText(name +" "+ year +"/"+ month + " " + QString::number(stock) + " added\n");
    }
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
        for(int i=0;i < plist->size(); ++i)
        {
            ui->table1->insertRow(0);
            ui->table1->setItem(0,0, new QTableWidgetItem (plist->operator [](i)->output[0]));
            ui->table1->setItem(0,1, new QTableWidgetItem (plist->operator [](i)->output[1]));
            ui->table1->setItem(0,2, new QTableWidgetItem (plist->operator [](i)->output[2]));
        }
    }

    outstream();

}

QString Product::getName() const
{
    return name;
}

bool Product::operator < (Product b)
{
    return ym < b.ym;
}

int Product::getYm() const
{
    return ym;
}

int Product::getStock() const
{
    return stock;
}

void MainWindow::on_regexe_clicked()
{
    QString liname = ui->regname->text();
    bool inname = false;

    for(int i=0; i<plist->size(); ++i){
        if(plist->operator [](i)->getName()==liname)
            inname=true;
    }
    if(inname)
        linearregg(liname, *plist);
    else
        ui->added->insertPlainText("Put a name exists\n");

}
