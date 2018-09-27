#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadcarros.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
    }
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCadastroCarro_clicked()
{
    CadCarros cadcar;
    cadcar.setModal(true);
    cadcar.exec();
}
