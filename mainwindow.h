#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QVector>
#include <cassert>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QCheckBox>

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
    void refreshtable();

private slots:
    void on_pushButton_clicked();
    void on_refresh_clicked();
    void on_regexe_clicked();
    void on_save_clicked();
    void on_load_clicked();
    void on_delete_items_clicked();

private:
    Ui::MainWindow *ui;
    QString name;
    int stock;
    QString year;
    QString rawmonth;
    QString month;
    QVector<Product*> *plist;
    void defaultwindow();
    void linearregg(QString n, QVector<Product*> &p);
    void outstream();
    void instream();
};

class Product{
public:
    Product (QString input);
    Product(QString n, int s, QString y, QString m);
    ~Product(){delete check;}
    Product (const Product&) = delete;
    void operator = (const Product&) = delete;
    QStringList output;
    QString getName() const;
    bool operator< (Product b);
    int getYm() const;
    int getStock() const;
   // QCheckBox *check;

private:
    QString name;
    int stock;
    QString year;
    QString month;
    int ym;
};
//any copy of this class must not exist...



#endif // MAINWINDOW_H
