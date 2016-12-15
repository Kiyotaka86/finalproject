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

    void on_regexe_clicked();

private:
    Ui::MainWindow *ui;
    QString name;
    int stock;
    QString year;
    QString month;
    QVector<Product*> *plist;
    void defaultwindow();
    void linearregg(QString n, QVector<Product*> &p);
};

class Product{
public:
    Product(QString n, int s, QString y, QString m){
        this->name=n;
        this->stock=s;
        this->year=y;

        if(m.toInt()<10)
            this->month = "0"+m;
        else
            this->month=m;

        output <<name << QString::number(stock) << year + "/" + month;

        ym = (y+month).toInt();

    }

    ~Product(){}
    QStringList output;
    QString getName() const;
    bool operator< (Product b);
    int getYm() const;

private:
    QString name;
    int stock;
    QString year;
    QString month;
    int ym;
};


#endif // MAINWINDOW_H
