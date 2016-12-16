#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::outstream()
{
    //QString filename;
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save the Table"), "",
            tr("Storage Table (*.csv);;All Files (*)"));
    if (fileName.isEmpty())
           return;
    else {
           QFile file(fileName);
           if (!file.open(QIODevice::WriteOnly)) {
               QMessageBox::information(this, tr("Unable to open file"),
                   file.errorString());
               return;
           }
           else
           {
               QTextStream out (&file);

               for(auto i : *plist)
               {
                   out<< i->output[0] << "," << i->output[1] << "," << i->output[2] <<"\n";
               }
           }
           file.close();
    }
}

void MainWindow::instream()
{
    if(!plist->isEmpty())
    {
        QMessageBox comfread;
        comfread.setText("If a file is loaded, the table is overwritten");
        comfread.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        comfread.setDefaultButton(QMessageBox::Cancel);
        int kk = comfread.exec();

        if(kk==QMessageBox::Cancel)
            return;
    }

    QString fileName = QFileDialog::getOpenFileName(this,
           tr("Open Table"), "",
           tr("Storage Table (*.csv);;All Files (*)"));

    if (fileName.isEmpty())
         return;
     else
    {
        QFile file(fileName);

         if (!file.open(QIODevice::ReadOnly))
         {
             QMessageBox::information(this, tr("Unable to open file"),
                 file.errorString());
             return;
         }

         QTextStream in(&file);

         plist->clear();   // clear existing contacts

         QString input;

         while(!in.atEnd())
         {
             input = in.readLine();
             Product* inp = new Product(input);
             plist->push_back(inp);
         }

    file.close();
    refreshtable();
    }
}



