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

    void on_save_clicked();

    void on_load_clicked();

private:
    Ui::MainWindow *ui;
    QString name;
    int stock;
    QString year;
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
    ~Product(){}
    QStringList output;
    QString getName() const;
    bool operator< (Product b);
    int getYm() const;
    int getStock() const;

private:
    QString name;
    int stock;
    QString year;
    QString month;
    int ym;
};


#endif // MAINWINDOW_H
