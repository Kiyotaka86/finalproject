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

void MainWindow::refreshtable()
{
    ui->table1->clear();
    ui->table1->setColumnCount(3);
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
    ui->year->setValue(2016);
    ui->n_stock->setMaximum(999999999);
    ui->delete_items->setToolTip("Delete all elements in the table");
    ui->refresh->setToolTip("Reload the table");
    ui->save->setToolTip("Save current table as CSV file");
    ui->load->setToolTip("Load a table from CSV file");
    ui->regexe->setToolTip("Predict the number of the storage of an item in the next month");
}

void MainWindow::on_pushButton_clicked()
{
    name= ui->Product_name->text();
    stock=ui->n_stock->value();
    year = ui->year->text();
    rawmonth = ui->month->text();

    if(rawmonth.toInt()<10)
        this->month = "0"+rawmonth;
    else
        this->month=rawmonth;


    if(name=="")
    {
        ui->added->insertPlainText("You need at least name!\n");
        return;
    }

    for(auto i: *plist)
    {
        if(i->getName() == name && i->output[2] == year+"/"+month  )
        {
            ui->added->insertPlainText("You cannot add the same item in the same month!\n");
            return;
        }
    }


    Product* pro= new Product(name, stock, year, month);
    plist->push_back(pro);
    ui->added->insertPlainText(name +" "+ year +"/"+ month + " " + QString::number(stock) + " added\n");

}

void MainWindow::on_refresh_clicked()
{
    refreshtable();
}

Product::Product(QString input)
{
    this->month = input.right(2);
    input.chop(3);
    this->year = input.right(4);
    input.chop(5);
    int namerange = input.indexOf(",")-1;
    this->name = input.left(namerange);
    namerange+=2;
    int rangestock = input.size() - namerange;
    this->stock = input.right(rangestock).toInt();

    output <<name << QString::number(stock) << year + "/" + month;

    ym = (year+month).toInt();

}


Product::Product(QString n, int s, QString y, QString m)
{
    this->name=n;
    this->stock=s;
    this->year=y;
    this->month=m;

    output <<name << QString::number(stock) << year + "/" + month;

    ym = (year+month).toInt();

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
        ui->added->insertPlainText("Put a name on table\n");

}

void MainWindow::on_save_clicked()
{
    outstream();
}

void MainWindow::on_load_clicked()
{
    instream();
}

void MainWindow::on_delete_items_clicked()
{
    QMessageBox comfdel;
    comfdel.setText("Are you sure to delete all items?");
    comfdel.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    comfdel.setDefaultButton(QMessageBox::Cancel);
    int kk = comfdel.exec();

    if(kk==QMessageBox::Cancel)
        return;

    for(int i=0; i<plist->size(); ++i)
    {
            plist->clear();
    }

    refreshtable();
}
