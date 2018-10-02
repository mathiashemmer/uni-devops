#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(this->lista1.size() > 0){
        int a = this->lista1.last();
        this->lista1.append(a+1);
    }else{
        this->lista1.append(1);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox mybox;
    if (QMessageBox::Yes == QMessageBox::question(this,
                                                  tr("title"),
                                                  tr(QString::number(this->lista1.last()).toStdString().c_str())))
    {
        // do stuff
    }
}
