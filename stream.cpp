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
    }

    //QFile gocsv("filename.txt");
//    if(gocsv.open(QFile::WriteOnly | QFile::Truncate))
//    {
//        QTextStream out (&gocsv);

//        for(auto i : *plist)
//        {
//            out<< i->output[0] << "," << i->output[1] << "," << i->output[2] <<"\n";
//        }
//        gocsv.close();
//    }

}
