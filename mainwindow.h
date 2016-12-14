#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

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
    int year;
    int month;
    std::vector<Product*>* plist;
    void defaultwindow();
    void printtable();
};

class Product{
public:
    Product(QString n, int stock, int year, int month){
        this->name=n;
        this->stock=stock;
        this->year=year;
        this->month=month;
        this->output <<name << QString::number(stock) << QString::number(year) + "/" + QString::number(month);
    }


    QStringList output;

    QString getName() const;

private:
    QString name;
    int stock;
    int year;
    int month;

};




#endif // MAINWINDOW_H
