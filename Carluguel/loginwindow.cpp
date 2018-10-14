#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <modulescreen.h>

LoginWindow::LoginWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    ModuleScreen ms;
    ms.setModal(true);
    this->hide();
    ms.exec();
}
