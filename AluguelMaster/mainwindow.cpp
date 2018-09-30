#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modulescreen.h"
#include <QString>

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

void MainWindow::on_pbtn_Login_clicked()
{
    QString login = ui->txt_User->text();
    QString password = ui->txt_Password->text();

    if(login != "Alex" || password != "dadez"){
        ui->statusBar->showMessage("Usuário ou Senha incorretos." , 2000);
    }else{
        ModuleScreen moduleScreen;
        hide();
        moduleScreen.setModal(true);
        moduleScreen.exec();
    }
}
