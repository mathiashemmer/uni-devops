#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include "moduleselection.h"

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

bool MainWindow::ValidatePassword(std::string user, std::string password){
    std::string cadLog, cadPass, buffer;
    std::ifstream myFile;
    myFile.open("../POO_Trabalho_M2/pass.prt", std::ios::app | std::ios::in | std::ios::out);
    if(myFile.is_open()){
        while(getline(myFile, buffer)){
           cadLog = buffer.substr(0, buffer.find(':'));
           cadPass = buffer.substr(buffer.find(':')+1);
           if(user == cadLog && password == cadPass) return true;
       }
    }
    return false;
}

void MainWindow::on_btn_Login_clicked()
{
    std::string user, password;
    if(ValidatePassword(ui->txt_username->text().toStdString(), ui->txt_password->text().toStdString())){
        ModuleSelection m;
        m.setModal(true);
        close();
        m.exec();
    }else{
        ui->statusBar->showMessage("Senha ou usuário incorreto/(os)", 1000);
    }
}
