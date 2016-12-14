#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QVector>

namespace Ui {
class MainWindow;
}

class Product;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTableView *table1;

private slots:
    void on_pushButton_clicked();


    void on_refresh_clicked();

private:
    Ui::MainWindow *ui;
    QString name;
    int stock;
    QString year;
    QString month;
    QVector<Product*> *plist;
    void defaultwindow();
    void printtable();
};

class Product{
public:
    Product(QString n, int s, QString y, QString m){
        this->name=n;
        this->stock=s;
        this->year=y;
        this->month=m;
        output <<name << QString::number(stock) << year + "/" + month;
    }

    ~Product(){}
    QStringList output;
    QString getName() const;

private:
    QString name;
    int stock;
    QString year;
    QString month;

};



#endif // MAINWINDOW_H
